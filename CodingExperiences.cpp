/***************** About custom type assignment ***************/
// When you declare a const member, the class object cannot be assigned
// because const variable cannot be assigned.
class Edge {
private:
    const int m_v;
    const int m_w;
    const double m_weight;
    ...
};

// Then when I tried to use std::priority_queue<Edge>, it cannot compile
std::priority_queue<Edge> pq;
pq.push(e);
pq.pop();
// This is because priority_queue requires its elements be MoveAssignable and MoveConstructible
// A class with const member variable is not MoveAssignable
// But copy constructor vs assignment operator overloading is clear now
