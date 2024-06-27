# CPP08
Templated containers, iterators, algorithms

## ex 00

## Vectores
### ¿que es un vector?
- Un array dinámico que puede cambiar de tamaño. Es eficiente para el acceso aleatorio y para agregar o eliminar elementos al final.
```c++
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for (int val : vec) {
        std::cout << val << std::endl;
    }
    return 0;
}
```
- Utilizando la palabra clave `std::vector<int>` y el nombre de la variable crearemos un vector de int
- con  el for recorremos cada elemento del vector vec , en cada iteracion del bucle val toma el valor del elemento actual

### iteradores 

- Un iterador es un objeto que apunta a un elemento dentro de un contenedor y puede ser usado para recorrer el contenedor. Cada contenedor de la STL proporciona tipos de iteradores.

```c++
#include <iostream>
#include <vector>

int main() {
	std::vector<int> numbers = {1, 2, 3, 4, 5};

	// Utilizando un iterador para recorrer el vector
	for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
		std::cout << *it << " ";
	}

	return 0;
}
```

- El interador se inicializa con `numbers.begin()` que apunta al primer elemento del vector y lo recorre hasta `numbers.end()`

- Igual que un puntero en  c si queremos sacar el contenido donde apunta it usaramos `*it`

### algoritmos 
- Algoritmos en la STL

	- La STL proporciona una serie de algoritmos que operan sobre contenedores. Para este ejercicio,usare  `std::find`.

#### std::find

Busca un valor en un rango de elementos y devuelve un iterador al primer elemento encontrado.
```c++
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), 3);

    if (it != vec.end()) {
        std::cout << "Found value: " << *it << std::endl;
    } else {
        std::cout << "Value not found" << std::endl;
    }
    return 0;
}
```

### Cositas de c98

- En c98 no podemos inicializar los vectores de esta forma
- `std::vector<int> vec = {1, 2, 3, 4, 5};`

- Podemos hacerlo asi 
```c++
#include <iostream>
#include <vector>
#include "EasyFind.hpp"

int main() {
	int arr [] = {1, 2, 3, 4, 5};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
}
```

- Donde vec recibe el puntero al primer elemento del array y el tamaño total de elementos en el array;

- Otra forma de añadir numeros a nuestro vector seria:
```c++
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
}
```

## ex 01

## Mas algoritmos 

- Estos Iteradores de Contenedor (begin() y end()):
	- Son métodos que devuelven iteradores que apuntan al primer elemento (begin()) y más allá del último elemento (end()) del contenedor respectivamente. 

### std::sort() 
- Ordena los elementos en el rango especificado usando el operador <. En mi caso, lo he utilizado para ordenar los números almacenados para calcular el rango más corto.
`std::sort(sortedNumbers.begin(), sortedNumbers.end());`
### std::min_element() y std::max_element()
- Encuentran el mínimo y el máximo elemento en un rango de iteradores respectivamente
```c++
int minElement = *std::min_element(numbers.begin(), numbers.end());
int maxElement = *std::max_element(numbers.begin(), numbers.end());
```
### std::distance():
- Calcula la distancia entre dos iteradores, que es útil para determinar cuántos elementos hay entre dos puntos en un contenedor.
`std::distance(begin, end);`

## Puntos claves del ejercicicio

1. El contructor de la clase es
```cpp    
Span(unsigned int N); 
```
- Donde N va a ser el tamaño de nuestro Vector

```cpp
#pragma once

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span {
public:
    Span(unsigned int N); 
    Span(const Span& other); 
    Span& operator=(const Span& other);
    ~Span(); 

    void addNumber(int number);
    void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int shortestSpan() const;
    int longestSpan() const;

    class SpanFullException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Span is already full";
        }
    };

    class NoSpanFoundException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "No span can be found";
        }
    };

private:
    std::vector<int> numbers;
    unsigned int maxSize;
};
```
- A la hora de añadir un numero llamaremos a addNumber

```cpp
void Span::addNumber(int number) {
    if (numbers.size() >= maxSize) {
        throw SpanFullException();
    }
    numbers.push_back(number);
}
```
- tiraremos una excepcion si nos pasamos del tamaño maxSize , que es el parametro que le pasamos al constructor previamente

- Uso el metodo push_back de la clase vectores para añadir el numero

- A la hora de añadir varios numeros es decir un array como nos indica el subject donde le pasaremos los iteradores/punteros begin y end de el array de ints para que los recorra y los inserte en nuestro vector 

```cpp
void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (numbers.size() + std::distance(begin, end) > maxSize) {
        throw SpanFullException();
    }
    numbers.insert(numbers.end(), begin, end);
}
```
-  El insert nos introducira todos los numeros del array desde el final del vector gracias al metodo end(), desde el begin del array al puntero final end;