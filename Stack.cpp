//Stack default constructor
#include <iostream>
template <typename T>
Stack <T>::Stack (void):
size_(0)
{

}

//Stack copy constructor
template <typename T>
Stack <T>::Stack (const Stack & stack): 
array_(stack.array_), 
size_(stack.size_)
{

}

//Stack destructor
template <typename T>
Stack <T>::~Stack (void)
{
}

//Stack push method
//if array is not large enough to hold element, increase the array size by 1
//add element to the end of array, the top of stack
//increase stack size to reflect added element
template <typename T>
void Stack <T>::push (T element)
{	
    if (size_ >= array_.size()) {
        array_.resize(size_ + 1);
    }
    array_[size_] = element;
    size_++;
}

//Stack pop method
//decrease stack size by 1 to reflect the top of the stack properly in conjunction with the underlying array
template <typename T>
void Stack <T>::pop (void)
{
    if (is_empty()) {
        throw empty_exception("The stack is empty");
    }
    size_--;
}

//Stack assign operator method 
//assign the rhs underlying array and rhs stack size to the lhs
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    if (this != &rhs) {
        array_ = rhs.array_;
        size_ = rhs.size_;
    }
    return *this;
}

//clear the stack by resizing underlying array to 0 and resetting stack size to 0
template <typename T>
void Stack <T>::clear (void)
{
    size_ = 0;
    array_.resize(0);
}
