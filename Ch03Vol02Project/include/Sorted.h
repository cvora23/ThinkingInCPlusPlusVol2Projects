//: C06:Sorted.h
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2001 MindView, Inc.
// Available at www.BruceEckel.com.
// Template specialization
#ifndef SORTED_H
#define SORTED_H
#include <vector>
#include <string.h>

template<class T>
class Sorted : public std::vector<T> {
public:
  void sort();
};

template<class T>
void Sorted<T>::sort() { // A bubble sort
  for(int i = this->size(); i > 0; i--)
    for(int j = 1; j < i; j++)
      if(this->at(j-1) > this->at(j)) {
        // Swap the two elements:
        T t = this->at(j-1);
        this->at(j-1) = this->at(j);
        this->at(j) = t;
      }
}

// Partial specialization for pointers:
template<class T>
class Sorted<T*> : public std::vector<T*> {
public:
  void sort();
};

template<class T>
void Sorted<T*>::sort() {
  for(int i = this->size(); i > 0; i--)
    for(int j = 1; j < i; j++)
      if(*this->at(j-1) > *this->at(j)) {
        // Swap the two elements:
        T* t = this->at(j-1);
        this->at(j-1) = this->at(j);
        this->at(j) = t;
      }
}

// Full specialization for char*:
template<>
void Sorted<char*>::sort() {
  for(int i = this->size(); i > 0; i--)
    for(int j = 1; j < i; j++)
      if(strcmp(this->at(j-1), this->at(j)) > 0) {
        // Swap the two elements:
        char* t = this->at(j-1);
        this->at(j-1) = this->at(j);
        this->at(j) = t;
      }
}
#endif // SORTED_H ///:~
