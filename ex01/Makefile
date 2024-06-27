# Variables
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = span

# Compilación
all: $(TARGET)

$(TARGET): main.o Span.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o Span.o

main.o: main.cpp Span.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Span.o: Span.cpp Span.hpp
	$(CXX) $(CXXFLAGS) -c Span.cpp

# Limpieza
clean:
	rm -f *.o $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re