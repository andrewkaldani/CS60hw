#ifndef LBAG_H
#define LBAG_H

#include <cstdlib>
#include <ostream>
#include "node.h"

template <class T>
class LBag
{
public:
    typedef T value_type;
    typedef std::size_t size_type;

    // pre: none
    // post: creates an empty LBag
    LBag();

    // pre: none
    // post: creates an LBag that is a copy of given LBag
    LBag(const LBag &);

    //Returns all memory to the runtime environment and sets head and tail to nullptr
    ~LBag();

    //pre: none
    //post:  change this bag to be a copy of the parameter bag
    void operator =(const LBag &);

    //pre: none
    //post:  returns the number of nodes in the linked list
    size_type size() const;

    //pre: none
    //post:  returns the number of times the parameter value appears in the bag
    size_type count(const T &) const;

    //pre: none
    //Post:  the parameter value is inserted at the head of the bag
    void insert(const T &);

    //pre: none
    //post:  our bag includes all of its elements, followed by all of the parameter bag's elements
    void operator +=(const LBag &);//homework

    //pre: none
    //post:  removes the first instance of the parameter value in the bag, if there is one.
    bool erase_one(const T &);//homework

    //pre: none
    //post:  removes all instances of the parameter value in the bag.
    size_type erase(const T &);//homework

    template <class T2>//Don't use class's type variable, because this is NOT part of the class
    friend std::ostream& operator <<(std::ostream& out, const LBag<T2> &);

private:
    node<T> *head, *tail;
};

template <class T>
LBag<T> operator +(const LBag<T> &, const LBag<T> &);





template <class T>
LBag<T>::LBag(){
  tail = nullptr;
  head = tail;
}


template <class T>
LBag<T>::LBag(const LBag<T> & b){
  list_copy(b.head, b.tail, head, tail);
}

template <class T>
LBag<T>::~LBag(){
  list_clear(head, tail);
}

template <class T>
void LBag<T>::operator =(const LBag<T> & b){
    list_clear(head, tail);
    list_copy(b.head, b.tail, head, tail);
}


template <class T>
typename LBag<T>::size_type LBag<T>::size() const{
  return list_size(head);
}


template <class T>
typename LBag<T>::size_type LBag<T>::count(const T & value) const{
  size_type count = 0;
  node<T>* p = list_search(head, value);
  while(p!=nullptr){
    p = list_search(p->link(), value);
    ++count;
  }
  return count;

}

template <class T>
void LBag<T>::insert(const T & value){
  list_head_insert(head, tail, value);
}



template <class T>
std::ostream& operator <<(std::ostream& out, const LBag<T> & b){
  out<<b.head;
  return out;
}


template <class T>
void LBag<T>::operator +=(const LBag<T>& b) {
  node<T> *temp = b.head;
   while (temp != nullptr) {
       tail->setlink(new node<T>(temp->data(), nullptr));
       temp = temp->link();
       tail = tail->link();
   }

}


template <class T>
LBag<T> operator +(const LBag<T> & a, const LBag<T> & b) {
	LBag<T> result(a);
	result += b;
	return result;
}
template <class T>
bool LBag<T>::erase_one(const T & value) {
	node<T> *temp = head;
  node<T> *prev = nullptr;
	while (temp != nullptr) {
		if (temp->data() == value) {
			if (temp == head) {
				head = head->link();
				delete temp;
			} else {
				prev->setlink(temp->link());
				delete temp;
			}
			return true;
		} else {
			prev = temp;
			temp = temp->link();
		}
	}
	return false;
}



template <class T>
LBag<int>::size_type LBag<T>::erase(const T & value) {
	size_type count = 0;
	while (this->erase_one(value))
		++count;
	return count;
}


#endif // LBAG_H
