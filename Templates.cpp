/************************* Templates ***************************/
// Function templates
// In C++, function templates are functions that serve as a pattern for creating other similar functions. 
// you only need to write one function, and it will work with many different types.
template <typename T> // this is the template parameter declaration
T max(T x, T y)
{
    return (x > y) ? x : y;
}

// Class templates
template <class T>
class Array {
    ...
    int getLength();
};

template <typename T> // member functions defined outside the class need their own template declaration
int Array<T>::getLength() { return m_length; } // note class name is Array<T>, not Array


// None-type parameters
template <class T, int size> // size is the non-type parameter
class StaticArray {...};

// Function template specialization
// Used when you want some some customization for certain type
// Simply define the specialized function with template type specified
template <>
void Storage<double>::print() // specify <double> here
{
    std::cout << std::scientific << m_value << '\n';
}


// Class template specialization
// Used when we want a customized version of class definition for certain type
template <> 
class Storage<bool> { // we're specializing Storage8 for bool
    ...
};
