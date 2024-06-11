#include "Calculator.h"


Calculator::Calculator() 
{
}

Calculator::~Calculator() 
{
}

// PROF COMMENT: Create a design that does not require having parenthesis as
// as command object since parenthesis are not executed.

// RESPONSE: I changed the design so that the ( and ) tokens are inserted into the stack as nullptrs instead of Command objects.
// This way, the stack can still be used to keep track of the order of operations, but the parentheses themselves are not executed and treated as Command objects.
// Note: The professor's comment was originally in the file that had the code for the Open_Parenthesis class.
// I deleted the class and file due to the updated desgin, so I moved the comment here.
Array <Command*> Calculator::infix_to_postfix(const std::string& infix, Command_Factory& factory, Array <Command*>& postfix)
{
    std::istringstream input(infix);
	std::string token;
    //Pointer to command object
    Command* cmd = 0;
    //Temp stack to hold operators
    Stack<Command*> temp;
    //Output queue to hold postfix expression
    //Used queue so I could append appropriately in order which isn't possible with a stack or array
    Queue<Command*> output;
    
    while (!input.eof()) {
        input >> token;
        //Create command objects based on token
        if (token == "+") {
            cmd = factory.create_add();
        } else if (token == "-") {
            cmd = factory.create_subtract();
        } else if (token == "/") {
            cmd = factory.create_divide();
        } else if (token == "*") {
            cmd = factory.create_multiply();
        } else if (token == "%") {
            cmd = factory.create_modulus();

        //if token is (, push nullptr to stack
        } else if (token == "(") {
            temp.push(nullptr);
            continue;
        //if token is ), pop all operators from stack until ( is encountered, represented by nullptr
        } else if (token == ")") {
            while (!temp.is_empty() && temp.top() != nullptr) {
                output.enqueue(temp.top());
                temp.pop();
            }
            //if stack is empty, there is an extra ) token
            if (temp.is_empty()) {
                throw std::runtime_error("Error: Extra ) parentheses");
            }
            //pop the ( token
            temp.pop();
            continue;
        } else {
            try {
                //if token is a number, create a number command object and enqueue it to the output queue
                cmd = factory.create_number(std::stoi(token));
                output.enqueue(cmd);
            } catch (std::invalid_argument& e) {
                //if token cannot be converted to a number, throw an error
                throw std::runtime_error("Error: Invalid token in expression");
            }
            continue;
        }
        //pop operators from stack and enqueue them to the output queue until the stack is empty, a ( is encountered, a number is encountered, or an operator with lower precedence is encountered
        while(!temp.is_empty() && temp.top() != nullptr && cmd->get_precedence() > 0 && temp.top()->get_precedence() >= cmd->get_precedence()) {
            output.enqueue(temp.top());
            temp.pop();
        }
        //push the current operator to the stack
        temp.push(cmd);

    }
    //pop all remaining operators from the stack and enqueue them to the output queue
    while (!temp.is_empty()) {
        //if a ( is encountered, there is an extra ( token
        if (temp.top() == nullptr) {
            throw std::runtime_error("Error: Extra ( parentheses");
        }
        output.enqueue(temp.top());
        temp.pop();
    }

    //resize the passed in postfix array to the size of the output queue and copy the contents of the postfix queue to the array
    postfix.resize(output.size());
    for (int i = 0; i < postfix.size(); i++) {
        postfix[i] = output.dequeue();
    }

    return postfix;
}

//evaluate the postfix array expression by executing each command object
//checks for nullptrs (representing ( and ) tokens) and skipping them
void Calculator::evaluate_postfix(Array <Command*>& postfix)
{
    for (int i = 0; i < postfix.size(); i++) {
        if (postfix[i] != nullptr) {
            postfix[i]->execute();
        }
    }
}

void Calculator::calculate()
{
    //create a stack to hold the result of the expression
    Stack<int> result;
    //create a factory object to create command objects, passing in the result stack
    Stack_Command_Factory factory = Stack_Command_Factory(result);
    std::string input;

    Array <Command*> postfix;

    while (true) {
        try {
            std::cout << "Enter an expression (or type QUIT to exit):\n";
            std::getline(std::cin, input);
            //if user types QUIT, exit the program
            if (input == "QUIT") {
                break;
            }
            //convert the infix expression to postfix and evaluate it
            infix_to_postfix(input, factory, postfix);
            evaluate_postfix(postfix);
            //print the result
            std::cout << "Result: " << result.top() << std::endl;
        //catch any exceptions thrown, print the error message, and continue the loop
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }

        //clear the result stack and delete the command objects in the postfix array to prevent memory leaks
        for (int i = 0; i < postfix.size(); i++) {
            delete postfix[i];
            postfix[i] = nullptr;
        }
        result.clear();
    }
}
