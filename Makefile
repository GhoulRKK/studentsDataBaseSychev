CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: students_db tests

students_db: main.cpp database.cpp test.cpp
	$(CXX) $(CXXFLAGS) main.cpp database.cpp test.cpp -o students_db

tests: test_main.cpp database.cpp test.cpp
	$(CXX) $(CXXFLAGS) test_main.cpp database.cpp test.cpp -o tests

clean:
	rm -f students_db tests
