#ifndef _BASE_ARRAY_H_
#define _BASE_ARRAY_H_

#include <cstring>         

/**
 * @class Base_Array
 *
 * Parent class that has a basic Array implementation without resizing.
 */
template <typename T>
class Base_Array
{
public:
  /// Type definition of the element type.
  typedef T type;

  /// Default constructor.
  Base_Array (void);

  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   */
  Base_Array (size_t length);

  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   * @param[in]      fill          Initial value for each element
   */
  Base_Array (size_t length, T fill);
  
  /**
   * Copy constructor
   *
   * @param[in]     arr         The source array.
   */
  Base_Array (const Base_Array & arr);

  /// Destructor.
  ~Base_Array (void);

  /**
   * Assignment operation
   *
   * @param[in]       rhs      Right-hand side of equal sign
   * @return          Reference to self
   */
  const Base_Array & operator = (const Base_Array & rhs);

  /**
   * Retrieve the current size of the array.
   *
   * @return          The current size
   */
  size_t size (void) const;

  /**
   * Get the element at the specified index. If the index is not
   * within the range of the array, then std::out_of_range exception
   * is thrown.
   *
   * @param[in]       index               Zero-based location
   * @return          Element at \index
   * @exception       std::out_of_range   Invalid \a index value
   */
  T & operator [] (size_t index);

  /**
   * @overload
   *
   * The returned element is not modifiable.
   */
  const T & operator [] (size_t index) const;
  
  /**
   * Get the element at the specified index. If the \a index is not within
   * the range of the array, then std::out_of_range exception is thrown.
   *
   * @param[in]       index                 Zero-based location
   * @return          Element at \index
   * @exception       std::out_of_range     Invalid index value
   */  
  T get (size_t index) const;

  /** 
   * Set the element at the specified \a index. If the \a index is not
   * within range of the array, then std::out_of_range exception is 
   * thrown.
   *
   * @param[in]       index                 Zero-based location
   * @param[in]       value                 New value for element
   * @exception       std::out_of_range     Invalid \a index value
   */
  void set (size_t index, T value);

  /**
   * Locate the specified element in the array. The index of the first
   * occurrence of the element is returned. If the element is not
   * found in the array, then -1 is returned.
   *
   * @param[in]        element        Element to search for
   * @return           Index value of the element
   * @retval           -1             Element not found
   */
  int find (T element) const;

  /**
   * @overload
   *
   * This version allows you to specify the start index of the search. If
   * the start index is not within the range of the array, then the
   * std::out_of_range exception is thrown.
   *
   * @param[in]       element              Element to search for
   * @param[in]       start                Index to begin search
   * @return          Index value of first occurrence
   * @retval          -1                   Element not found
   * @exception       std::out_of_range    Invalid index
   */
  int find (T element, size_t start) const;

  /**
   * Test the array for equality.
   *
   * @param[in]       rhs                  Right hand side of equal to sign
   * @retval          true                 Left side is equal to right side
   * @retval          false                Left side is not equal to right side
   */
  bool operator == (const Base_Array & rhs) const;

  /**
   * Test the array for inequality.
   *
   * @param[in]       rhs                  Right-hand size of not equal to sign
   * @retval          true                 Left side is not equal to right side
   * @retval          false                Left size is equal to right side
   */
  bool operator != (const Base_Array & rhs) const;

  /**
   * Fill the contents of the array.
   *
   * @param[in]       element              Fill element
   */
  void fill (T element);

protected:
  // Pointer to the actual data.
  T * data_;

  // Size of array, also represents current size
  size_t size_;

};

#include "Base_Array.inl"
#include "Base_Array.cpp"

#endif   // !defined _ARRAY_H_
