#include "Span.hpp"
#include <iostream>
#include <limits>

Span::Span(unsigned int N) : maxSize(N) {}

Span::Span(const Span& other) {
    maxSize = other.maxSize;
    numbers = other.numbers;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        maxSize = other.maxSize;
        numbers = other.numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (numbers.size() >= maxSize) {
        throw SpanFullException();
    }
    numbers.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (numbers.size() + std::distance(begin, end) > maxSize) {
        throw SpanFullException();
    }
    numbers.insert(numbers.end(), begin, end);
}

int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw NoSpanFoundException();
    }

    std::vector<int> sortedNumbers(numbers);
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int shortest = std::numeric_limits<int>::max();
    for (std::size_t i = 1; i < sortedNumbers.size(); ++i) {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < shortest) {
            shortest = span;
        }
    }

    return shortest;
}

int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw NoSpanFoundException();
    }

    int minElement = *std::min_element(numbers.begin(), numbers.end());
    int maxElement = *std::max_element(numbers.begin(), numbers.end());

    return maxElement - minElement;
}