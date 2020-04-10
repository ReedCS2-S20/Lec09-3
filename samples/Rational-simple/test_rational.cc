#include <iostream>
#include "Rational.hh"

int main() {
  Rational q1;
  Rational q2;
  
  std::cout << "Enter a rational number: ";
  std::cin >> q1;
  std::cout << "Enter another rational number: ";
  std::cin >> q2;

  std::cout << "The first was " << q1 << "." << std::endl;
  std::cout << "Its numerator is " << q1["numerator"] << "." << std::endl;
  std::cout << "The second was " << q2 << "." << std::endl;
  std::cout << "Its negation is " << -q2 << "." << std::endl;
  std::cout << "Their sum is " << (q1 + q2) << "." << std::endl;
  std::cout << "Their product is " << (q1 * q2) << "." << std::endl;

}

