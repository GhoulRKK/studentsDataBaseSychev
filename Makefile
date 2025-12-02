CXX=g++
CXXFLAGS=-std=c++11 -Wall

all: students_db tests

students_db: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o students_db

tests: test_main.cpp test.cpp
	$(CXX) $(CXXFLAGS) test_main.cpp test.cpp -o tests

clean:
	rm -f students_db tests
