# Variables
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = span

# Compilación
all: $(TARGET)

$(TARGET): main.o Span.o
	$(CPP) $(CPPFLAGS) -o $(TARGET) main.o Span.o

main.o: main.cpp Span.hpp
	$(CPP) $(CPPFLAGS) -c main.cpp

Span.o: Span.cpp Span.hpp
	$(CPP) $(CPPFLAGS) -c Span.cpp

# Limpieza
clean:
	rm -f *.o $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re