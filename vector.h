#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template<typename T>
class vector
{
    T* arr_;
    size_t size_{};
    size_t capacity_{};
public:
    vector();
    ~vector();
    vector(vector& other);
    vector(vector&& other) noexcept;
    bool isEmpty() const;
    size_t size() const;
    size_t capacity() const;
    void addMemory();
    void pushBack(T& value);
    void element(int i);
    void remove(size_t index);
    void show_vector(vector<T> obj);
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    T* begin();
    const T* begin() const;
    T* end();
    const T* end() const;

    vector& operator=(vector& other);
    vector& operator=(vector&& other) noexcept;
    friend inline ostream& operator<<(std::ostream& os, const vector<T>& vec)
    {
        for (size_t i = 0; i < vec.size(); ++i) os << vec[i] << " ";
        return os;
    }
};
