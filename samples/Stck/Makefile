CXX=g++
CXX_FLAGS=-g -std=c++11
.PHONY: all clean
TARGETS=dc

all: $(TARGETS)


Stck.o: Stck.hh
Stck.o: Stck.cc
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

dc.o: Stck.hh
dc.o: dc.cc
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

dc: dc.o Stck.o
	$(CXX) $(CXX_FLAGS) -o $@ $^

clean:
	rm -f *~ *.o $(TARGETS)