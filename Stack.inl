//return size of stack
template <typename T>
inline
size_t Stack <T>::size (void) const
{
    return size_;
}

//return the top of the stack, last element in underlying array
template <typename T>
inline
T Stack <T>::top (void) const
{
    return array_[size_ - 1];
}

//check if the stack size is 0, empty
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
    return size_ == 0;
}
