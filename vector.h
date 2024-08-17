#ifndef VECTOR_H
#define VECTOR_H

#include <exception>

class Vector{
public:
    Vector(); // : m_size {0}, m_cap {0}, m_arr {nullptr} {};
             // initializer list ^^ (verevi grac expression-y)
    Vector(int, int, int*);
    Vector(const Vector &);  // copy ctor;
    Vector(Vector &&);  // move ctor;

    ~Vector();

public:
    const int &operator[](int) const;
    int &operator[](int);

    bool operator==(const Vector &);
    bool operator!=(Vector &);
    bool operator>(const Vector &);
    bool operator>=(const Vector &);
    bool operator<(const Vector &);
    bool operator<=(const Vector &);

    Vector& operator=(const Vector &);      // copy operator assignment
    Vector& operator=(Vector &&);           // move operator assignment

    friend std::ostream& operator<<(std::ostream &, const Vector &);
    friend std::istream& operator>>(std::istream &, Vector &);
public:
    void push_back(int);
    void push_front(int);
    void pop_back();
    void resize();
    bool empty();

    void clear();

    void print();
public:
    void set_size(const int&);
    int get_size() const;

    void set_cap(const int&);
    int get_cap() const;

    void set_arr(int*, int);
    int* get_arr() const;

private:
    int m_size;
    int m_cap;
    int* m_arr;
};

#endif //VECTOR_H
