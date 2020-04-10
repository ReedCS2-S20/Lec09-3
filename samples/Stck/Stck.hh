#include <string>

class Stck {

private:
  int *elements;
  int num_elements;
  int capacity;

public:  
  Stck(int capacity);
  bool is_empty();
  void push(int value);
  int pop();
  int top();
  std::string to_string();
  ~Stck();
};




