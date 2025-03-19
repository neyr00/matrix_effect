#ifndef LList_HPP
#define LLIST_HPP
#include "node.hpp"
#include "list.hpp"
template <typename T>
class linkedlist : public list<T> {
private:
    node<T> *main;
    size_t size;
public:
    linkedlist() : size(0), main(nullptr) {}
    ~linkedlist() {
        while (main != nullptr) {
            node<T> *temp = main;
            main = main->next;
            delete temp;
        }
    }
    bool empty() override { return size == 0; }
    size_t getSize() override { return size; }
    T get(size_t index) override {
        node<T> *cur = main;
        for (size_t i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->data;
    }
    void push_back(T obj) override {
        node<T> *new_node = new node<T>(obj);
        if (main == nullptr)
            main = new_node;
        else {
            node<T> *cur = main;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = new_node;
        }
        size++;
    }
    void insert(T obj, size_t index) override {
        if (index >= size)
            push_back(obj);
        else {
            node<T>* cur = main;
            node<T>* new_node = new node<T>(obj);
            if (index) {
                for (size_t i = 0; i < index - 1; i++)
                    cur = cur->next;
                new_node->next = cur->next;
                cur->next = new_node;
            }
            else {
                new_node->next = main;
                main = new_node;
            }
            size++;
        }
    }
    void erase(size_t index) override {
        if (index == 0) {
            node<T> *temp = main;
            main = main->next;
            delete temp;
        }
        else {
            node<T> *cur = main;
            for (size_t i = 0; i < index - 1; i++)
                cur = cur->next;
            node<T> *temp = cur->next;
            cur->next = temp->next;
            delete temp;
        }
        size--;
    }
};
#endif