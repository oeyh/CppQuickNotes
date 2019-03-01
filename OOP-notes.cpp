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

// NOTE: To instantiate a class using default constructor, no () is needed, otherwise compiler
// will think you are defining a function with no parameters and return type is that class
Point p; // correct
Point p(); // not correct for instantiating a class


/********************** Constructor Initializer List ************************************/
/*
1. This is initialization instead of assignment
2. More efficient
3. const type can be initialized this way (cannot be assigned)
Rule: Use member initializer lists to initialize your class member variables instead of assignment.
*/
// an example:
class Fraction {
private:
    int numerator;
    int denominator;
    const int e;

public:
    Fraction(int n, int d)
        : numerator(n), denominator(d), e(2.72) {}
    .....
};


/******** Destructor *****************/
// A destructor is another special kind of class member function that is executed when an object of that class is destroyed.
// Whereas constructors are designed to initialize a class, destructors are designed to help clean up.



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

/********************** Static keyword ******************/
/** Static member variables **/
// static member variables are shared by all objects of the class and are not attached to any particular object
class Something
{
public:
    static int s_value; // declares the static member variable
};
Something s;
s.s_value // access through a particular object
Something::s_value // access through class name



/** Static member functions **/
// static member functions are shared by all objects of the class and are not attached to any particular object
// Static member functions have two interesting quirks worth noting.
// First, because static member functions are not attached to an object, they have no this pointer, because this pointer always points to the object that the member function is working on.
// Second, static member functions can directly access other static members (variables or functions), but not non-static members.
// This is because non-static members must belong to a class object, and static member functions have no class object to work with!
class Something
{
private:
    static int s_value;
public:
    static int getValue() { return s_value; } // static member function
};

int Something::s_value = 1; // initializer

int main()
{
    std::cout << Something::getValue() << '\n';
}


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
// parent class vs child class, or, base class vs derived class, or, superclass vs subclass;
// Order of construction: most base class first, then derived class, from top to bottom;
// Order of destruction: the other way around, from most-dervied class to most-base class;
// Calling base class constructor in derived class constructor: put base class constructor in derived class constructor's
// initializer list (cannot put in body because body is executed after base class construction is done)
class Base {
private:
    int m_n;
public:
    Base(int n) {...}
};

class Derived : public Base {
private:
    double m_x;
public:
    Derived(int n, double x) : Base(n), m_x(x) {...}
}
// Access specifier for class members:
// public: can be accessed by any objects
// protected: accessed by class members, friends and derived class members
// private: by class members and friends only
class BaseClass {
private:
    ...
protected:
    ...
public:
    ...
};

// Access specifier for inheritance:
// public: inherited base members stay with their original accesses (public, protected or private)
//         use public inheritance unless you have a specific reason to do otherwise
// private: inherited base members all becomes private when you try to access them through derived class
// If you do not choose an inheritance type, C++ defaults to private inheritance
// Public inheritance is the most commonly used type of inheritance. Very rarely will you see other types of inheritance
// Publicly inherited members remain their original access level in base class (private, protected, or public)
class DerivedClass : public BaseClass {

};

// Functions in derived class
// 1. Regular functions that does not coincide with any ones in base class, use as usual
// 2. Functions that have same signiture as in base class override the ones in base class (when calling from derived class or object)
// 3. To call base class functions in derived class, use BaseClass::func() explicitly
// 4. Multiple inheritance: Avoid multiple inheritance unless alternatives lead to more complexity. (Java doesn't support multiple inheritance)
class DerivedClass : public BaseClass1, public BaseClass2 {

};


/************************ Virtual function and Polymorphism ***********************/
// In my own words, virtual functions provide a way to call derived class object member
// functions through references or pointers to a base class object and therefore
// facilitate the use of generalized references and pointers to base classes.

// A virtual function call will resolve to a call to the matching (overriding) function (same signature and return type)
// in the most-derived class between base class of the reference/pointer and derived class of the object

// Rule: Never call virtual functions from constructors or destructors

// virtual keyword is required for base class virtual function, but can be implicit in overrides functions in
// its derived classes.

// Rule: Apply the override specifier to every intended override function you write. -- this is very similar to the use of @Override in Java
class A {
    virtual void speak() {}
};

class B : public A {
    virtual void speak() override {}
};

// The final specifier will disallow any further override in further-derived classes (show compiler error if try to override)
class Base final {...};  // cannot inherit class
void speak() final {...} // cannot override class function

// Whenever you are dealing with inheritance, you should make any explicit destructors virtual.
// to make sure the derived class destructor is called which will call Base’s destructor in turn.

// How virtual functions work in a program
// early binding (static binding, function calls are resolved at compile time) vs late binding (dynamic binding, function calls are resolved at runtime)
// Virtual functions use special type of late binding and a virtual table to find the correct function
// A virtual table contains one entry for each virtual function that can be called by objects of the class.
// Each entry in this table is simply a function pointer that points to the most-derived function accessible by that class.
// When a class object is created, a pointer, *__vptr is set to point to the virtual table for that class.

/***********************  Abstract Classes and Interface Classes *****************/
/*
 Abstract class:
 To create a pure virtual function, rather than define a body for the function, we simply assign the function the value 0.
 - First, any class with one or more pure virtual functions becomes an abstract base class, which means that it can not be instantiated
 - Second, any derived class must define a body for this function, or that derived class will be considered an abstract base class as well.
 */
class A {
    ...
    virtual int getName() = 0;
    ...
};
/*
 we can define pure virtual functions that have also bodies, in this case:
 - the body must be provided separately (not inline)
 - provide a default implementation for a function, but still force any derived classes to provide their own implementation.

 Interface class:
 An interface class is a class that has no member variables, and where all of the functions are pure virtual!
 In other words, the class is purely a definition, and has no actual implementation.
 Interfaces are useful when you want to define the functionality that derived classes must implement,
 but leave the details of how the derived class implements that functionality entirely up to the derived class.
 */

// First, any class with one or more pure virtual functions becomes an abstract base class, which means that it can not be instantiated
// Second, any derived class must define a body for this function, or that derived class will be considered an abstract base class as well.
