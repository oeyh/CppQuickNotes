// Pointers, References and Dynamic Memory Allocation are the most powerful features in C/C++ language,
// which allows programmers to directly manipulate memory to efficiently manage the memory

// Pointer is a variable that stores memory address
// use * to declare a pointer

type *ptr;

// and use * to get the object that the pointer points to
// in this case, * is called dereference operator
std::cout << *ptr;

// Pointer has a type, too
// A pointer can only hold an address of the declared type; it cannot hold an address of a different type.
Point p(1, 2);
Point *ptr = &p;
Rectangle *ptr2 = &p; // will not work



/****** Pointer vs Reference **********/
// 1. Reference has to be initialized when declared.
// 2. Reference cannot be assigned (to change the object it references to)
// 3. Member selection: use -> with pointers and . with references:
ptr->member();
ref.member();


// Use nullptr to denote null pointers in C++11 and forward, instead of 0 or NULL (which is a macro of value 0)
int *ptr {nullptr};

//
