#include <iostream>
#include <string>
#include "Rational.hh"

int gcd(int a, int b) {
  if (a < b) return gcd(b,a);
  if (b == 0) return a;
  return gcd(b,a%b);
}

void Rational::reduce(void) {
  int sign = (num < 0) ? -1 : 1;
  int factor = gcd(sign*num,den);
  num /= factor;
  den /= factor;
}

bool Rational::parse(std::string s, Rational& q) {

  std::string s_num = "";
  std::string s_den = "1";
  bool saw_slash = false;
  bool saw_error = false;

  //
  // Dig through the string's characters extracting the
  // numerator and denominator strings.
  //
  for (int i=0; i<s.length(); i++) {
    char c = s[i];
    if (c >= '0' && c <= '9') {
      // A digit is fine, include it.
      if (saw_slash) {
	s_den += c;
      } else {
	s_num += c;
      }
    } else if (c == '-' && i == 0) {
      s_num += c;
    } else if (!saw_slash && c == '/' && s_num != "") {
      // The first slash occurrence is fine if saw digits.
      s_den = "";
      saw_slash = true;
    } else {
      // Anything else is an error.
      saw_error = true;
    }
  }

  // If parse error then default to 0/1.
  if (saw_error) {
    s_num = "0";
    s_den = "1";
  }

  // Set numerator/denominator by strings if d is not zero.
  int n = std::stoi(s_num);
  int d = std::stoi(s_den);
  if (d == 0) {
    // Set to 0/1 if d is zero.
    saw_error = true;
    n=0;
    d=1;
  }
  q.num = n;
  q.den = d; 

  return saw_error;
} 

// Non-GCD version:
// 
// Rational::Rational(int n, int d) : num {n}, den {d} { }
//

Rational::Rational(int n, int d) { 
  if (d == 0) {
    n = 0;
    d = 1;
  }
  if (d < 0) {
    n *= -1;
    d *= -1;
  }
  num = n;
  den = d;
  reduce();
}

Rational::Rational(int n) : Rational {n,1}
{ }

Rational::Rational(void) : Rational {0}
{ }

Rational::Rational(std::string s) {
  parse(s,*this);
  reduce();
  // Should maybe check the parse flag, raise an error?
}

// This is a "copy constructor" which we'll discuss soon.                                         
Rational::Rational(const Rational& that) :  Rational {that.num,that.den}
{ }

Rational Rational::reciprocal() const {
  return Rational {den,num};
}

Rational Rational::minus(void) const {
  return Rational {-num,den};
}

Rational Rational::sum(const Rational& q1,const Rational& q2) {
  return Rational{q1.num*q2.den+q1.den*q2.num,q1.den*q2.den};
}

Rational Rational::difference(const Rational& q1,const Rational& q2) {
  return sum(q1,q2.minus());
}
  
Rational Rational::product(const Rational& q1,const Rational& q2) {
  return Rational{q1.num*q2.num,q1.den*q2.den};
}

Rational Rational::quotient(const Rational& q1,const Rational& q2) {
  return product(q1,q2.reciprocal());
}
  
Rational Rational::plus(const Rational& that) const {
  return sum(*this,that);
}

Rational Rational::minus(const Rational& that) const {
  return difference(*this,that);
}

Rational Rational::times(const Rational& that) const {
  return product(*this,that);
}

Rational Rational::over(const Rational& that) const {
  return quotient(*this,that);
}

std::string Rational::to_string(void) const {
  if (den == 1) {
    return std::to_string(num);
  } else {
    return std::to_string(num) + "/" + std::to_string(den);
  }
}  

Rational Rational::operator-(void) const {
  return minus();
}

Rational operator+(const Rational& q1, const Rational& q2) {
  return Rational::sum(q1,q2);
}

Rational operator-(const Rational& q1, const Rational& q2) {
  return Rational::difference(q1,q2);
}

Rational operator*(const Rational& q1, const Rational& q2) {
  return Rational::product(q1,q2);
}

Rational operator/(const Rational& q1, const Rational& q2) {
  return Rational::quotient(q1,q2);
}

std::ostream& operator<<(std::ostream& os, const Rational& q) {
  os << q.to_string();
  return os;
}

std::istream& operator>>(std::istream& is, Rational& q) {
  std::string s;
  is >> s;
  q = Rational {s};
  return is;
}
