/************************************************************************/
/************* C++ STL (Standard Template Library) Containers ***************/

// The container classes fall into three basic categories: Sequence containers, Associative containers, and Container adapters
// Sequence: array, vector, deque, etc.
// Associative: set, map
// Adapters: stack, queue, priority queue

// STL iterators
// Operator* -- Dereferencing the iterator returns the element that the iterator is currently pointing at.
// begin() returns an iterator representing the beginning of the elements in the container
// end() returns an iterator representing the element just past the end of the elements

/********** STD::VECTOR ***********/
// vectors are dynamic arrays
// defined in vector header
#include <vector>

// declaration and initialization
// array length not needed
std::vector<int> vec = {1, 9, 8, 9};
std::vector<int> vec {1, 9, 8, 9}; // uniform init
std::vector<int> v; // empty vector
std::vector<int> v(10); // all-zero vector
std::vector<int> v(10, 2); // all-two vector

// use [] or at() for indexing
vec[2]      // no bound checking
vec.at(2) // with bound checking

// length of std::vector
vec.size()

// add to the end of a vector
vec.push_back(3);

// for loop
// * Most containers define the variable type that can
// * be used to store its size. To access the type, you
// * can do container<T>::size_type. This can get annoying
// * to write so we can create an alias/synonym for this
// * type and call it vecsz_t.
using vecsz_t = std::vector<int>::size_type;
for (vecsz_t i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << " ";
}

/*
vector is the type of sequence that should be used by default...
deque is the data structure of choice when most insertions and
deletions take place at the beginning or at the end of the
sequence
*/


/********** STD::ARRAY ***********/
// defined in array header
#include <array>

// declaration and initialization
// must provide array length
std::array<int, 3> arr = {1, 2, 3};
std::array<int, 3> arr2 {1, 2, 3}; // uniform init

// use [] or at() for indexing
arr[2]      // no bound checking
arr.at(2)   // with bound checking

// length of std::array
arr.size()


/********** STD::STRING ***********/
#include <string>

// declaration and initialization
std::string myName("Hai");
std::string herName = "Liu";

// length of a string
myName.length()

// use [] or at() for indexing
myName[0]
myName.at(0)

// string appending
myName += " Yan";

// find substring
myName.find('i'); // 2
myName.find("ba"); // -1, not found

/********** STD::SET ***********/



/********** STD::UNORDERED_SET ***********/
#include <unordered_set>

std::unordered_set<int> nums;

// Insert
nums.insert(3);

//


/********** STD::MAP ***********/



/********** STD::DEQUE ***********/



/********** STD::QUEUE ***********/
#include <queue>

// FIFO data structure
std::queue<int> myqueue;

// push to back of queue
myqueue.push(4);
// return front of queue
myqueue.front() += 2;
// pop front of queue, note that it doesn't return the popped item
myqueue.pop();
// get size of queue
myqueue.size()
myqueue.empty()
