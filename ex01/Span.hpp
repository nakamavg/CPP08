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
