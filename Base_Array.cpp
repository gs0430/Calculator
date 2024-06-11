#include "Base_Array.h"
#include <iostream>

//Base Array default constructor
template <typename T>
Base_Array <T>::Base_Array (void):
size_(0), 
data_(nullptr)
{
}

//Base Array initializing constructor
template <typename T>
Base_Array <T>::Base_Array (size_t length):
size_(length), 
data_(new T[length])
{
}

//Base Array initializing constructor with fill
template <typename T>
Base_Array <T>::Base_Array (size_t length, T fill):
size_(length), 
data_(new T[length])
{
    for (size_t i = 0; i < length; ++i) {
        data_[i] = fill;
    }
}

//Base Array copy constructor
template <typename T>
Base_Array <T>::Base_Array (const Base_Array & arr):
size_(arr.size_),
data_(new T[arr.size_])
{
    for(size_t i = 0; i < size_; i++){
        data_[i] = arr.data_[i];
    }
}

//Base Array destructor
template <typename T>
Base_Array <T>::~Base_Array (void)
{
    delete[] data_;
}

//Base Array assign operator method
//only change allocation size of lhs array if it is not large enough to hold rhs
//copy all data from right hand side to a new data array instance, which is then returned and assigned to lhs array
template <typename T>
const Base_Array <T> & Base_Array <T>::operator = (const Base_Array & rhs)
{
    if (this != &rhs){

        if(size_ < rhs.size_){
    
            size_ = rhs.size_;
            delete[] data_; 
            data_ = new T[size_];

        }

        for(size_t i = 0; i < size_; i++){
            data_[i] = rhs.data_[i];
        }
    }

    return *this;
}

//[] operator methods to access and modify values based off indexes
template <typename T>
T & Base_Array <T>::operator [] (size_t index)
{
    if(index >= size_){
        throw std::out_of_range("Index is out of range");
    }
    return data_[index];
}

//overload [], not modifiable
template <typename T>
const T & Base_Array <T>::operator [] (size_t index) const
{
    if(index >= size_){
        throw std::out_of_range("Index is out of range");
    }
    return data_[index];
}

//get and set values from indexes
template <typename T>
T Base_Array <T>::get (size_t index) const
{
    if(index >= size_){
        throw std::out_of_range("Index is out of range");
    }
    return data_[index];
}

template <typename T>
void Base_Array <T>::set (size_t index, T value)
{
    if(index >= size_){
        throw std::out_of_range("Index is out of range");
    }
    data_[index] = value;
}

//find methods that loop through array and check each index if it matches the passed value, returns index of found value
template  <typename T>
int Base_Array <T>::find (T value) const
{
    for (size_t i = 0; i < size_; i++) {
        if (data_[i] == value) {
            return i;
        }
    }

    return -1;
}

//overload find, set the beginning point of for loop to the start index passed in
template <typename T>
int Base_Array <T>::find (T val, size_t start) const
{
    if(start >= size_){
        throw std::out_of_range("Start index is out of range");
    }
    for (size_t i = start; i < size_; i++) {
        if (data_[i] == val) {
            return i;
        }
    }

    return -1;
}

//equality operator method
//if left hand array and right hand array are not equal size, the arrays are not equal
//loop through each element of rhs array and if it does not match the element in the same index in the lhs array, it is not equal, returns false
//returns true if all elements at each index match
template <typename T>
bool Base_Array <T>::operator == (const Base_Array & rhs) const
{
    if(this == &rhs){
        return true;
    }

    if(size_ != rhs.size_){
        return false;
    }

    for (size_t i = 0; i < size_; i++) {
        if (data_[i] != rhs.data_[i]) {
            return false;
        }
    }

    return true;
}

//inequality operator method
//compare left array and right array with equality operator, return the opposite of the result
//if equality comparison results true, that means the the inequality comparison would be false and vice versa 
template <typename T>
bool Base_Array <T>::operator != (const Base_Array & rhs) const
{
    return !(*this == rhs);
}

//fill each index with passed ch
template <typename T>
void Base_Array <T>::fill (T value)
{
    for (size_t i = 0; i < size_; i++) {
        data_[i] = value;
    }
}

