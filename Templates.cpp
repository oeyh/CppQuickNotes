/********************** Templates ***********************/
// Function using templates
template <typename T>
const T& max(const T& a, const T& b) {
    return (a >= b) ? a : b;
}



// Class using templates
template <class T>
class Array {
    ...

    int getLength();
};

// member functions defined outside the class need their own template declaration
template <typename T>
int Array<T>::getLength() { // note Array<T> here, instead of Array

}
