
#ifndef PEA11_ALGORITHM_H
#define PEA11_ALGORITHM_H

#include "Graph.h"
#include <vector>

class Algorithm {
private:
    const Graph& graph;  // Referencja do obiektu klasy Graph

    // Funkcja do zamiany dwóch elementów
    void swap(int& a, int& b);

    // Funkcja generująca kolejną permutację leksykograficzną
    bool nextPermutation(std::vector<int>& sequence);

    // Funkcja do odwrócenia elementów wektora od pozycji `start` do `end`
    void reverse(std::vector<int>& sequence, int start, int end);

public:
    // Konstruktor przyjmujący referencję do grafu
    Algorithm(const Graph& g);

    // Funkcja do obliczenia najkrótszej trasy metodą brute-force
    int tspBruteForce(int start);
};

#endif // ALGORITHM_H

