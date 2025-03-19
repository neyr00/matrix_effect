#ifndef LIST_HPP
#define LIST_HPP
template <typename T>
class list {
public:
	virtual T get(size_t index) = 0;
	virtual size_t getSize() = 0;
	virtual bool empty() = 0;
	virtual void push_back(T obj) = 0;
	virtual void insert(T obj, size_t index) = 0;
	virtual void erase(size_t index) = 0;
};
#endif