#pragma once
#include <iostream>
#include <algorithm>
#include <vector>


class EasyFind {

	public:
		class NotFoundException : public std::exception {
			public:
				virtual const char* what() const throw() { return ("Value not found in the container"); }
		};
};

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw EasyFind::NotFoundException();
    }
    return it;
}
