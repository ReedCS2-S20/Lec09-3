#include <iostream>
#include <string>
#include "Rational.hh"

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
}

Rational::Rational(void) : Rational {0,1}
{ }

Rational::Rational(const Rational& q) :  Rational {q.num,q.den}
{ }

Rational::Rational(std::string s) {

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

  num = n;
  den = d; 
} 

Rational Rational::plus(Rational q) {
  return Rational{num*q.den+den*q.num,den*q.den};
}

Rational Rational::times(Rational q) {
  return Rational{num*q.num,den*q.den};
}
  
std::string Rational::to_string(void) const {
  if (den == 1) {
    return std::to_string(num);
  } else {
    return std::to_string(num) + "/" + std::to_string(den);
  }
}  

Rational operator+(Rational q1, Rational q2) {
  return q1.plus(q2);
}

Rational operator*(Rational q1, Rational q2) {
  return q1.times(q2);
}

Rational Rational::operator-(void) {
  return Rational {-num,den};
}

int Rational::operator[](std::string s) {
  if (s == "numerator") return num;
  if (s == "denominator") return den;
  return 0;
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
