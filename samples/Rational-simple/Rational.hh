#ifndef __RATIONAL_HH
#define __RATIONAL_HH

#include <iostream>
#include <string>

class Rational {
private:
  int num;
  int den;
public:
  // constructors
  Rational(void);
  Rational(std::string s);
  Rational(int n, int d);
  Rational(const Rational& q);

  // methods
  Rational plus(Rational that);
  Rational times(Rational that);
  std::string to_string(void) const;

  // operator methods
  Rational operator-(void);
  int operator[](std::string s);
};

// operators
std::ostream& operator<<(std::ostream& os, const Rational& q);
std::istream& operator>>(std::istream& is, Rational& q);
Rational operator+(Rational q1, Rational q2);
Rational operator*(Rational q1, Rational q2);

#endif
