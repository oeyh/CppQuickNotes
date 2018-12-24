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

// 3 types:

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

/********** STD::ARRAY ***********/
// defined in array header
#include <array>

// declaration and initialization
// must provide array length
std::array<int, 3> arr = {1, 2, 3};
std::array<int, 3> arr2 {1, 2, 3}; // uniform init

// use [] or at() for indexing
arr[2]
arr.at(2)

// length of std::array
arr.size()


/********** STD::VECTOR ***********/
// vectors are dynamic arrays
// defined in vector header
#include <vector>

// declaration and initialization
// array length not needed
std::vector<int> arr = {1, 9, 8, 9};
std::vector<int> arr {1, 9, 8, 9}; // uniform init

// use [] or at() for indexing
arr[2]
arr.at(2)

// length of std::vector
arr.size()


/********** STD::STRING ***********/
#include <string>

// declaration and initialization
std::string myName("Hai");

// length of a string
myName.length()

// use [] or at() for indexing
myName[0]
myName.at(0)

// string appending
myName += " Yan";


/********** STD::SET ***********/




/********** STD::MAP ***********/
