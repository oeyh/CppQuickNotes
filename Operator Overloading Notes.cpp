// arithmetic operators, using friend function
friend Point operator+ (const Point &rhs) {
    ......
    return p; // a Point object
}

// I/O operators << and >>, using friend function
friend std::ostream& operator<< (std::ostream &out, const Point &rhs) {
    out << ...
    return out;
}

friend std::istream& operator>> (std::istream &in, Point &rhs) {
    in >> ...
    return in;
}

// unary operator +, -, !, using member function
Point Point::operator- () {
    return Point(-x, -y);
}

bool Point::operator! () {
    return (x == 0 && y == 0);
}

// comparison operators, using friend function
friend bool operator== (const Point &p1, const Point &p2);
friend bool operator!= (const Point &p1, const Point &p2);
friend bool operator< (const Point &p1, const Point &p2); // this is important for some ordered containers
friend bool operator<= (const Point &p1, const Point &p2);
friend bool operator> (const Point &p1, const Point &p2);
friend bool operator>= (const Point &p1, const Point &p2);

// increment and decrement operators, using member functions
// within class definition:
Point& operator++(); // prefix ++
Point& operator--(); // prefix --

Point operator++(int); // postfix ++
Point operator--(int); // postfix --
// implementation is also different between prefix and postfix, see details in: 
// https://www.learncpp.com/cpp-tutorial/97-overloading-the-increment-and-decrement-operators/






/*
- If you’re overloading assignment (=), subscript ([]), function call (()), or member selection (->), do so as a member function.
- If you’re overloading a unary operator, do so as a member function.
- If you’re overloading a binary operator that modifies its left operand (e.g. operator+=), do so as a member function if you can.
- If you’re overloading a binary operator that does not modify its left operand (e.g. operator+), do so as a normal function or friend function.
*/

