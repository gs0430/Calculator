//Queue default constructor
template <typename T>
Queue <T>::Queue (void): 
size_(0),
front_index(0)
{
}

//Queue copy constructor
template <typename T>
Queue <T>::Queue (const Queue & s): 
array_(s.array_), 
size_(s.size_),
front_index(s.front_index)
{
}

//Queue destructor
template <typename T>
Queue <T>::~Queue (void)
{
}

//Queue enqueue method 
//if array needs space to enqueue a element, increase the size by 1
//add the element to the end of the array
//increase queue size to reflect enqueued element
template <typename T>
void Queue <T>::enqueue (T element) 
{
    if (size_ >= array_.size()) {
        array_.resize(size_ + 1);
    }
    array_[size_] = element;
    size_++;
}

//Queue dequeue method
//front element of queue is the element in the queue corresponding to the front index value
//size of queue is decreased by 1 everytime a element is dequeued and front of queue index is increased by 1
template<typename T>
T Queue <T>::dequeue (void) 
{
    if (is_empty()) {
        throw empty_exception("Queue is empty");
    }
    T front_element = array_[front_index];
    front_index++;
    size_--;

    if (front_index == array_.size()) {
        clear();
    }
    
    return front_element;
}

//Queue clear method
//resets the front of the queue, the size of the queue, and the underlying array size all to 0
template<typename T>
void Queue <T>::clear (void) 
{
    array_.resize(0);
    front_index = 0;
    size_ = 0;
}

//Queue assign operator method
//assign the rhs underlying array, rhs queue size, and rhs front index of queue to the lhs
template<typename T>
const Queue <T> & Queue <T>::operator = (const Queue<T>& rhs) 
{
    if (this != &rhs) {
        array_ = rhs.array_;
        size_ = rhs.size_;
        front_index = rhs.front_index;
    }
    return *this;
}
