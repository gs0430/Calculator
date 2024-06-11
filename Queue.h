#ifndef QUEUE_H
#define QUEUE_H

#include <exception>

#include "Array.h"

/**
 * @class Queue
 *
 * Basic queue for abitrary elements.
 */
template<typename T>
class Queue {
public:
    /// Type definition of the type.
    typedef T type;

    /**
     * @class empty_exception
     *
     * Exception thrown to indicate the stack is empty.
     */
    class empty_exception : public std::runtime_error {
        public:
            /// Default constructor.
            empty_exception (void)
                : std::runtime_error () { }

            /**
             * Initializing constructor.
             *
             * @param[in]      msg         Error message.
             */
            empty_exception (const char * msg)
                : std::runtime_error (msg) { }
    };

    /// Default constructor.
    Queue (void);

    /// Copy constructor.
    Queue (const Queue & s);

    /// Destructor.
    ~Queue (void);

    /**
     * Enqueue a new \a element into the queue. The element is inserted
     * after all the other elements in the list.
     *
     * @param[in]      element       Element to add to the list
     */
    void enqueue (T element);

    /**
     * Remove the front element from the queue.
     *
     * @exception      empty_exception    The queue is empty.
     */
    T dequeue (void);

    /**
     * Check if the queue is empty
     *
     * @retval         true          The queue is empty
     * @retval         false         The queue is not empty
     */
    bool is_empty (void) const;

    /**
     * Number of elements in the queue.
     *
     * @return         Size of the queue.
     */
    size_t size (void) const;

    /// Remove all elements from the queue.
    void clear (void);

    /**
     * Assignment operator
     *
     * @param[in]      rhs           Right-hand side of operator
     * @return         Reference to self
     */
    const Queue & operator = (const Queue & rhs);

private:
    //underlying structure for Queue
    Array<T> array_;

    //size of Queue
    size_t size_;

    //front index value of Queue
    size_t front_index;
};

#include "Queue.inl" 

#include "Queue.cpp"

#endif 