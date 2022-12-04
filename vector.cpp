#include"vector.h"

template<typename T>
vector<T>::vector()
{
    arr_ = new T[1];
    capacity_ = 1;
}

template<typename T>
bool vector<T>::isEmpty() const { return size_ == 0; }

template<typename T>
size_t vector<T>::size() const { return size_; }

template<typename T>
size_t vector<T>::capacity() const { return capacity_; }

template<typename T>
void vector<T>::addMemory()
{
    capacity_ *= 2;
    T* tmp = arr_;
    arr_ = new T[capacity_];
    for (size_t i = 0; i < size_; ++i) arr_[i] = tmp[i];
    delete[] tmp;
}

template<typename T>
void vector<T>::element(int i)
{
    if (size() != 0) cout << arr_[i] << endl;
    else cout << "Empty." << endl;
}

template<typename T>
void vector<T>::pushBack(T& value)
{
    if (size_ >= capacity_) addMemory();
    arr_[size_++] = value;
}

template<typename T>
void vector<T>::remove(size_t index)
{
    for (size_t i = index + 1; i < size_; ++i)
    {
        arr_[i - 1] = arr_[i];
    }
    --size_;
}

template<typename T>
void vector<T>::show_vector(vector<T> obj)
{
    if (obj.size() == 0) cout << "Empty." << endl;
    else
    {
        for (int i = 0; i < obj.size(); i++)
            cout << arr_[i] << endl;
    }
}

template<typename T>
T& vector<T>::operator[](size_t index) { return arr_[index]; }

template<typename T>
const T& vector<T>::operator[](size_t index) const { return arr_[index]; }

template<typename T>
vector<T>::~vector() { delete[] arr_; }

template<typename T>
inline std::ostream& operator<<(std::ostream& os, const vector<T>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) os << vec[i] << " ";
    return os;
}

template<typename T>
T* vector<T>::begin() { return &arr_[0]; }

template<typename T>
const T* vector<T>::begin() const { return &arr_[0]; }

template<typename T>
T* vector<T>::end() { return &arr_[size_]; }

template<typename T>
const T* vector<T>::end() const { return &arr_[size_]; }

template<typename T>
vector<T>::vector(vector& other)
{
    if (this != &other)
    {
        delete[] arr_;
        arr_ = new T[other.capacity_];
        for (size_t i = 0; i < other.size_; ++i) arr_[i] = other.arr_[i];
        size_ = other.size_;
        capacity_ = other.capacity_;
    }
}

template<typename T>
vector<T>::vector(vector&& other) noexcept
{
    if (this != &other)
    {
        delete[] arr_;
        arr_ = other.arr_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        other.arr_ = nullptr;
        other.size_ = other.capacity_ = 0;
    }
}

template<typename T>
vector<T>& vector<T>::operator=(vector<T>& other) {
    if (this != &other) {
        delete[] arr_;
        arr_ = new T[other.capacity_];
        for (size_t i = 0; i < other.size_; ++i) arr_[i] = other.arr_[i];
        size_ = other.size_;
        capacity_ = other.capacity_;
    }
    return *this;
}

template<typename T>
vector<T>& vector<T>::operator=(vector&& other) noexcept {
    if (this != &other) {
        delete[] arr_;
        arr_ = other.arr_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        other.arr_ = nullptr;
        other.size_ = other.capacity_ = 0;
    }
    return *this;
}
