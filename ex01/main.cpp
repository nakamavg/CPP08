#include <iostream>
#include <vector>
#include "Span.hpp"

int main() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    try {
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	//probar la copia
	Span sp2 = sp;
	try {
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	//generar 10000 numeros
	Span sp3 = Span(10000);
	for (int i = 0; i < 10000; i++) {
		sp3.addNumber(i);
	}
	try {
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	//probar excepcion de span lleno
	try
	{
		sp3.addNumber(10000);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//ad num con iteradores
	Span sp4 = Span(10);
	std::vector<int> vec;
	for (int i = 0; i < 10; i++) {
		vec.push_back(i);
	}
	sp4.addNumber(vec.begin(), vec.end());
	try {
		std::cout << sp4.shortestSpan() << std::endl;
		std::cout << sp4.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	

    return 0;
}