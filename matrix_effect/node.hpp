#ifndef NODE_HPP
#define NODE_HPP
template <typename T>
struct node {
    T data;
    node* next;
    node(T value) : data(value), next(nullptr) {}
};
#endif