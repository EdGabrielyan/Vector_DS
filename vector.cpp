#include <iostream>
#include "vector.h"

Vector::Vector() {
    m_size = 0;
    m_cap = 5;
    m_arr = new int[m_cap];
}

Vector::Vector(int size, int cap, int* arr) {
    m_size = size;
    m_cap = cap;
    m_arr = arr;
}

Vector::Vector(const Vector &oth) {
    this->m_cap = oth.m_cap;
    this->m_size = oth.m_size;
    //delete [] this->m_arr; // sa petq chi delete anel qani vor im this->arr-n ela
                             // nuin texy cuic talis u oth.arr-n ela nuin texy cuic talis
    this->m_arr = new int[this->m_cap];
    for (int i = 0; i < this->m_size; ++i) {
        this->m_arr[i] = oth.m_arr[i];
    }
}

Vector::Vector(Vector &&oth) {
    this->m_size = oth.m_size;
    this->m_cap = oth.m_cap;
    this->m_arr = &oth.m_cap;
    oth.m_arr = nullptr;
    oth.m_size = 0;
    oth.m_cap = 0;
}

Vector::~Vector() {
    m_size = 0;
    m_cap = 0;
    delete [] m_arr;
    m_arr = nullptr;
}

const int &Vector::operator[](int index) const {
    if (index >= this->m_size && index < 0) {
        throw std::out_of_range("invalid index!");
    }
    return this->m_arr[index];
}

int &Vector::operator[](int index) {
    if (index >= m_size && index < 0) {
        throw std::out_of_range("invalid index!");
    }
    return m_arr[index];
}

bool Vector::operator==(const Vector &rhs) {
    if (this->m_size != rhs.m_size) {
        return false;
    }
    for (int i = 0; i < this->m_size; ++i) {
        if (this->m_arr[i] != rhs.m_arr[i]) {
            return false;
        }
    }
    return true;
}

bool Vector::operator!=(Vector &rhs) {
    if (this->m_size == rhs.m_size) {
        return false;
    }
    for (int i = 0; i < this->m_size; ++i) {
        if (this->m_arr[i] == rhs.m_arr[i]) {
            return false;
        }
    }
    return true;
}

bool Vector::operator>(const Vector &rhs) {
    if (this->m_size <= rhs.m_size) {
        return false;
    }
    for (int i = 0; i < this->m_size; ++i) {
        if (this->m_arr[i] <= rhs.m_arr[i]) {
            return false;
        }
    }
    return true;
}

bool Vector::operator>=(const Vector &rhs) {
    if (this->m_size < rhs.m_size) {
        return false;
    }
    for (int i = 0; i < this->m_size; ++i) {
        if (this->m_arr[i] < rhs.m_arr[i]) {
            return false;
        }
    }
    return true;
}

bool Vector::operator<(const Vector &rhs) {
    if (this->m_size >= rhs.m_size) {
        return false;
    }
    for (int i = 0; i < this->m_size; ++i) {
        if (this->m_arr[i] >= rhs.m_size) {
            return false;
        }
    }
    return true;
}

bool Vector::operator<=(const Vector &rhs) {
    if (this->m_size > rhs.m_size) {
        return false;
    }
    for (int i = 0; i < this->m_size; ++i) {
        if (this->m_arr[i] > rhs.m_arr[i]) {
            return false;
        }
    }
    return true;
}

Vector& Vector::operator=(const Vector &rhs) {
    if (*this == rhs) {
        return *this;
    }
    delete[] this->m_arr;
    this->m_size = rhs.m_size;
    this->m_cap = rhs.m_cap;
    this->m_arr = new int[this->m_cap];
    for (int i = 0; i < this->m_size; ++i) {
        this->m_arr[i] = rhs.m_arr[i];
    }
    return *this;
}

Vector& Vector::operator=(Vector &&rhs) {
    if (*this == rhs) {
        return *this;
    }
    m_size = rhs.m_size;
    m_cap = rhs.m_cap;
    m_arr = rhs.m_arr;
    rhs.m_arr = nullptr;
    rhs.m_size = 0;
    rhs.m_cap = 0;
    return *this;
}

std::ostream& operator<<(std::ostream& COUT, const Vector &oth) {
        COUT << oth.m_size << " ";
        COUT << oth.m_cap << " ";
        for (int i = 0; i < oth.m_size; ++i) {
            COUT << oth.m_arr[i];
        }
        return COUT;
}

std::istream& operator>>(std::istream& CIN, Vector &oth) {
    CIN >> oth.m_size;
    CIN >> oth.m_cap;
    //CIN >> reinterpret_cast<Vector &>(oth.m_arr);
    oth.m_arr = new int[oth.m_cap];
    for (int i = 0; i < oth.m_size; ++i) {
        CIN >> oth.m_arr[i];
    }
    return CIN;
}

void Vector::push_back(int elem) {
    if (m_cap == m_size) {
        resize();
    }
    m_arr[m_size++] = elem;
}

void Vector::push_front(int elem) {
    if (m_cap == m_size) {
        resize();
    }
    for (int i = m_size; i >= 1; --i) {
        m_arr[i] = m_arr[i - 1];
    }
    m_arr[0] = elem;
    ++m_size;
}

void Vector::pop_back() {
    if (empty()) {
        return;
    }
    else {
        m_arr[--m_size] = 0;
    }
}

void Vector::resize() {
    m_cap *= 2;
    int* tmp = new int[m_cap];
    for (int i = 0; i < m_size; ++i) {
        tmp[i] = m_arr[i];
    }
    delete [] m_arr;
    //m_arr = nullptr;
    m_arr = tmp;
}

bool Vector::empty() {
        return !m_size;
}

void Vector::print() {
    for (int i = 0; i < m_size; ++i) {
        std::cout << m_arr[i] << " ";
    }
}

void Vector::clear() {
    if (!m_size) {
        return;
    }
    else {
        m_size = 0;
        m_arr[m_size] = 0;
    }
}

void Vector::set_size(const int &size) {
    m_size = size;
}

int Vector::get_size() const {
    return m_size;
}

void Vector::set_cap(const int &cap) {
    m_cap = cap;
}
int Vector::get_cap() const {
    return m_cap;
}

void Vector::set_arr(int *arr, int arr_cap) {
    delete [] m_arr;
    m_arr = new int[arr_cap];
    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = arr[i];
    }
}

int* Vector::get_arr() const {
    return m_arr;
}

