//checks if queue size is 0, empty
template<typename T>
inline
bool Queue<T>::is_empty() const {
    return size_ == 0;
}

//returns size of queue
template<typename T>
inline
size_t Queue<T>::size() const {
    return size_;
}
