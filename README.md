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

    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found value: " << *it << std::endl;
        
        it = easyfind(vec, 10);
        std::cout << "Found value: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
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

