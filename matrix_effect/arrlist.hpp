#ifndef ARRList_HPP
#define ARRLIST_HPP
#include "list.hpp"
#include <algorithm>
using namespace std;
template <typename T>
class arrlist : public list<T> {
private:
    size_t size, capacity;
    T* arr;
    T temp;
    void resize() {
        capacity *= 2;
        T* new_arr = new T[capacity];
        for (size_t i = 0; i < size; i++)
            new_arr[i] = arr[i];
        delete[] arr;
        arr = new_arr;
    }
public:
    arrlist() : size(0), capacity(4) { arr = new T[capacity]; }
    ~arrlist() { delete[] arr; }
    bool empty() override { return size == 0; }
    size_t getSize() override { return size; }
    T get(size_t index) override { return arr[index]; }
    void push_back(T obj) override {
        if (size >= capacity)
            resize();
        arr[size++] = obj;
    }
    void sorted() {
        for (size_t i = 0; i < size; i++)
            for (size_t j = i + 1; j < size; j++)
                swap(arr[i], arr[j]);
    }
    void insert(T obj, size_t index) override {
        if (size >= capacity)
            resize();
        for (size_t i = size;i > index;--i)
            arr[i] = arr[i - 1];
        arr[index] = obj;
        size++;
    }
    void erase(size_t index) override {
        for (size_t i = index; i < size - 1; i++)
            arr[i] = arr[i + 1];
        size--;
    }
};
#endif