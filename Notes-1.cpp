/********** CONSTANT ***********/
/*
Const variables must be initialized when you define them,
and then that value can not be changed via assignment.
*/
const int a = 3;

/********** STREAM ***********/
>> // input operator
<< // output operator


/***** Class vs Struct *****/
/*
Usage:
- use class for objects that have both data and functions
- use struct for data-only structures

Access control:
- all members of a class are private by default
- all members of a struct are public by default

*/


/***** Initialization *****/

// Three types:
// 1. Copy initialization:
int x = 5;
Point2d p = Point2d(5, 3);

// 2. Direct initialization:
int x(5);
Point2d p(5, 3);

// 3. Uniform initialization:
int x{5};
Point2d p{5, 3};

// In C++11, prefer uniform init to direct init to copy init


/********** ARRAY ***********/
// delaration and initialization
int array[10] = {}; // all 0s
int array[10] = {0}; // all 0s
int array[3] = {1, 2, 3}; // initializer list
int array[] = {1, 2, 3}; // omit the length is OK if full initializer is given
int array[10] = {0, 1, 2, 3, 4}; // elements not specified will be 0

// fixed length array declaration must use constant or const variable
int n = 5;
double arr[n]; // will cause error!
const int m = 5;
double arr[m]; // this is OK

// array indexing is same as other major languages
array[0] = 4;

// length of an array
sizeof(array) / sizeof(array[0])

// decay of an array
/*
- The loss of type and dimensions of an array is known as decay of an array.
- This generally occurs when we pass the array into function by value or pointer.

How to prevent Array Decay?
- A typical solution to handle decay is to pass size of array also as a parameter
and not use sizeof on array parameters (See this for details)
- Another way to prevent array decay is to send the array into functions
by reference. This prevents conversion of array into a pointer,
hence prevents the decay.
*/

/************************** C-SYTLE STRING **************************/
char myString[] = "commitment";
// remember there's a null character "\0" automatically added to the end
// so the length of the char array is actually +1.

/*
l-value refers to an object with an identifiable memory location (locator value)
r-value refers to all the rest, temporary value without a defined memory address.
*/
int x = 5; // x is a non-const l-value
const int y = 5; // y is a const l-value
5 // literal 5 is an r-value
2 + 3 // results of an calculated expression is an r-value
Point(2, 3) // anonymous object is an r-value



/********************** Function argument passing *****************************/
// Three major ways of passing:
// 1. Pass by value
// arguments (actual parameters) are copied and passed to parameters (formal parameters)
// arguments will not be altered.
void func(int x) {}
int main() {
    int k = 3;
    func(k);
}

// 2. Pass by reference
// reference to arguments are passed and arguments may be altered by the function
void func(vector<int>& v) {}
int main() {
    vector<int> v {1, 2, 3};
    func(v);
}

//Rule: When passing an argument by reference, always use a const reference
// unless you need to change the value of the argument
// Const references can accept any type of argument, including l-values, const l-values, and r-values
// but non-const references can only accept non-const l-values (cannot accept literals, expressions, anonymous objects)


// 3. Pass by address
// address is conveyed by pointer
// Note that the address is passed by value, so the argument address is never changed
// but the object that the argument points to can be altered through the parameter pointer
void func(int *p, int n) {}
int main() {
    int arr[3] = {};
    func(arr, 3);
}

/********************** Function returns *****************************/
// 1. Return by value
// Note that return an anonymous object is also returning a value, this is a direct
// copy of the object, so no worry about the anonymous object been out of scope or destroyed
// but this requires copying an object, probably not the optimal solution.
Point func() {
    ...
    return Point(1, 2);
}


// 2. Return by reference
// Return by reference is typically used to return arguments passed by reference
// to the function back to the caller.
int& get(vector<int>& v, int k) {
    return v[k]; // v is a vector outside this function, which is passed in by reference
}
// Note that returning a reference to a local variable is bad because local
// variable goes out of scope and is destroyed out of the function

// 3. Return by address
// often used to return dynamically allocated memory to the caller
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // new ListNode() is used inside function
}
// Note that returning a pointer to a local variable is bad because local
// variable goes out of scope and is destroyed out of the function
// This is not a issue for dynamically allocated memory.



/********************** Compilation of C++ Program ******************/
// 1. Preprocessing: takes care of preprocessor directives, replace them with real source codes
// 2. Compilation: converts source code to assembly code (machine code) and generates object file
// 3. Linking: links all object files to generate either library or executable file


/********************** For Each Loops ******************/
// almost identical to for each loops in Java
int array[] = {1, 3, 2, 4, 5};
for (int i : array) {
    doSomething(i);
}
// OR when loop through object arrays (non-fundamental types)
Point arr[3] = {Point(1, 2), Point(3, 4), Point(1, 4)};
for (const Point &i : arr) {
    doAnotherThing(i);
}


/********************** Global variables ******************/
/*
Variables declared outside of a function are called global variables.
Global variables have static duration, which means they are created when the program starts and are destroyed when it ends.
Global variables have file scope (also informally called “global scope” or “global namespace scope”),
which means they are visible until the end of the file in which they are declared.
*/
// global scope operator (::)
int value = 5;

int main() {
    int value = 7; // hides global variable 'value'
    ::value++; // refers to global variable 'value'

    ....
}
