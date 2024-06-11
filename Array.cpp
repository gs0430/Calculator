// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"

//Array default constructor
template <typename T>
Array <T>::Array (void):
max_size_(0)
{
}

//Array initializing constructor
template <typename T>
Array <T>::Array (size_t length):
max_size_(length), 
Base_Array<T>(length)
{
}

//Array initializing constructor with fill
template <typename T>
Array <T>::Array (size_t length, T fill):
max_size_(length), 
Base_Array<T>(length, fill)
{
}

//Array copy constructor
template <typename T>
Array <T>::Array (const Array & arr):
max_size_(arr.max_size_), 
Base_Array<T>(arr) 
{
}

//Array destructor
template <typename T>
Array <T>::~Array (void)
{
}

//Array assign operator method
//size and data from parent class, size in Array represents array current size
//only change allocation size of lhs array if it is not large enough to hold rhs
//copy all data from right hand side to a new data array instance, which is then returned and assigned to lhs array
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    if (this != &rhs){
    
        if(max_size_ < rhs.size_){
            this->size_ = rhs.size_;
            max_size_ = rhs.max_size_;

            delete[] this->data_; 
            this->data_ = new T[this->size_];
        }

        for(size_t i = 0; i < this->size_; i++){
            this->data_[i] = rhs.data_[i];
        }
    }

    return *this;
}

//Resize array to the new size parameter
//size and data from parent class, size in Array represents array current size
//if the passed size is smaller than the size, just update size and max size
//if passed size is greater, create new array instance and copy data over. Free up old data array memory so it can be reassigned from instance
//max and size are updated to reflect the new size
template <typename T>
void Array <T>::resize (size_t new_size)
{
    if(new_size < this->size_){
        this->size_ = new_size;
        max_size_ = new_size;
    }

    if(new_size > this->size_){

        T * new_data = new T [new_size];

        for(size_t i = 0; i < this->size_; i++){
            new_data[i] = this->data_[i];
        }

        delete[] this->data_;

        this->data_ = new_data;
        this->size_ = new_size;
        max_size_ = new_size;
    }
}
