CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = mutantstack
SRCS = main.cpp 
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

main.o: main.cpp MutantStack.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

MutantStack.o: MutantStack.cpp MutantStack.hpp
	$(CXX) $(CXXFLAGS) -c MutantStack.cpp

clean:
	rm -f *.o
fclean: clean
	rm -f $(TARGET)