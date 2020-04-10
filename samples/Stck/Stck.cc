#include "Stck.hh"
#include <cassert>
#include <string>

Stck::Stck(int capacity) :
  elements {new int[capacity]},
  num_elements {0},
  capacity {capacity}
{ }

bool Stck::is_empty() {
  return (num_elements == 0);
}

void Stck::push(int value) {
  assert(num_elements < capacity);
  elements[num_elements] = value;
  num_elements++;
}  

int Stck::pop() {
  assert(!is_empty());
  num_elements--;
  return elements[num_elements];
}  

int Stck::top() {
  assert(!is_empty());
  return elements[num_elements-1];
}  

std::string Stck::to_string() {
  if (is_empty()) {
    return "[ ]";
  } else {
    int i = num_elements-1;
    std::string ss = "[("+std::to_string(elements[i])+")";
    i--;
    while (i >= 0) {
      ss += " "+std::to_string(elements[i]);
      i--;
    }
    return ss + "]";
  }
}

Stck::~Stck() {
  delete [] elements;
}
