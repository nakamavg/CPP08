#include <iostream>
#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
	mstack.push(0);
	mstack.push(42);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
	std::cout << "Head: " << *it << std::endl; // Imprime la cabeza de la lista
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
	std::cout << "Tail: " << *(--ite) << std::endl; // Imprime el último elemento de la lista

	
	
	std::cout << "MutantStack size: " << mstack.size() << std::endl;

    std::stack<int> s(mstack); // Esto debería funcionar igual que con std::stack
	std::cout << "Stack size: " << s.size() << std::endl;
	std::cout << "Stack top: " << s.top() << std::endl;
	//quero enseñar el numero 42 que es el ultimo de msatck


    return 0;
}