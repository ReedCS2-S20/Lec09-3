#ifndef __RATIONAL_HH
#define __RATIONAL_HH

#include <iostream>
#include <string>

class Rational {

private:
  int num;
  int den;

  void reduce(void);

public:
  // constructors
  Rational(void);
  Rational(std::string s);
  Rational(int n);
  Rational(int n, int d);
  Rational(const Rational& that);     // copy constructor

  // class methods
  static bool parse(std::string s, Rational& q);
  static Rational sum(const Rational& q1, const Rational& q2);
  static Rational difference(const Rational& q1, const Rational& q2);
  static Rational product(const Rational& q1, const Rational& q2);
  static Rational quotient(const Rational& q1, const Rational& q2);

  // methods
  Rational plus(const Rational& that) const;
  Rational minus(const Rational& that) const;
  Rational times(const Rational& that) const;
  Rational over(const Rational& that) const;
  Rational reciprocal(void) const;
  Rational minus(void) const;
  Rational operator-(void) const;
  std::string to_string(void) const;

  friend std::ostream& operator<<(std::ostream& os, const Rational& q);
  friend std::istream& operator>>(std::istream& is, Rational& q);
};

Rational operator+(const Rational& q1, const Rational& q2);
Rational operator-(const Rational& q1, const Rational& q2);
Rational operator*(const Rational& q1, const Rational& q2);
Rational operator/(const Rational& q1, const Rational& q2);

#endif
