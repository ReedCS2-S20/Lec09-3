CXX=g++
CXX_FLAGS=-g -std=c++11
.PHONY: all clean
TARGETS=test_rational

all: $(TARGETS)


Rational.o: Rational.hh
Rational.o: Rational.cc
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

test_rational.o: Rational.hh
test_rational.o: test_rational.cc
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

test_rational: test_rational.o Rational.o
	$(CXX) $(CXX_FLAGS) -o $@ $^

clean:
	rm -f *~ *.o $(TARGETS)