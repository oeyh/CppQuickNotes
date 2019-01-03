/********************** Instantiating a class ***********************/
// "this" is a pointer, it is also an rvalue expression and cannot be assigned.
// Direct init
Point p(1, 2);
Fraction f(1, 3);

// Copy init, may need customized copy constructor
Point p = Point(1, 2); // similar to Point p(Point(1, 2))
Fraction f = Point(1, 3);

// uniform init
Point p {1, 2};
Fraction f {1, 3};

// init with new keyword to allocate memory dynamically
Point* p = new Point(1, 2);
Fraction* f = new Fraction(1, 3);


/******** const member function *******/
// A const member function is a member function that guarantees it will not modify
// the object or call any non-const member functions (as they may modify the object).
// To declare a const member function, append the const keyword to the function prototype,
// after the parameter list, but before the function body
class Something {
private:
    int m_val;

public:
    int getVal() const {
        return m_val;
    }
}

/* Worthnoting:
- anonymous objects are primarily used either to pass or return values without
having to create lots of temporary variables;
- anonymous objects are treated as rvalues (which have no address), This means
anonymous objects can only be passed or returned by value or const reference.
Otherwise, a named variable must be used instead.
- anonymous objects are values, can be returned by return-by-value.
*/
// function declaration:
Cents add(const Cents &c1, const Cents &c2);
// function call:
add(Cents(6), Cents(8)) // this is OK because const references are used in function parameters


/************************ operator overloading ***********************/
/*
Operators can be overloaded as a normal function, a friend function, or a member function.
Best practices are:
- If you’re overloading assignment (=), subscript ([]), function call (()), or member selection (->), do so as a member function.
- If you’re overloading a unary operator, do so as a member function.
- If you’re overloading a binary operator that modifies its left operand (e.g. operator+=), do so as a member function if you can.
  Exceptions are << and >> operators as they the left operand are from iostream, part of the standard library
- If you’re overloading a binary operator that does not modify its left operand (e.g. operator+), do so as a normal function or friend function.
*/
// Other tips:
// - Overloaded assignment operators should always include a self-assignment check.
if (this == &other) {...}


/************************ Inheritance ***********************/
// parent class vs child class, or, base class vs derived class, or, superclass vs subclass
// Order of construction: most base class first, then derived class, from top to bottom
// Order of destruction: the other way around, from most-dervied class to most-base class

// Access specifier for class members:
// public: can be accessed by any objects
// protect: accessed by class members, friends and derived class members
// private: by class members and friends only

// Access specifier for inheritance:
// public: inherited base members stay with their original accesses (public, protected or private)
//         use public inheritance unless you have a specific reason to do otherwise
// private: inherited base members all becomes private when you try to access them through derived class


/************************ Virtual function and Polymorphism ***********************/
// In my own words, virtual functions provide a way to call derived class object member
// functions through references or pointers to a base class object and therefore
// facilitate the use of generalized references and pointers to base classes.

// A virtual function call will resolve to a call to the matching (overriding) function
// in the most-derived class between base class of the reference/pointer and derived class of the object

// Rule: Never call virtual functions from constructors or destructors

// virtual keyword is required for base class virtual function, but can be implicit in overrides functions in
// its derived classes.

// Rule: Apply the override specifier to every intended override function you write. -- this is very similar to the use of @Override in Java
