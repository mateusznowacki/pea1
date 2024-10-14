//
// Created by matty on 14.10.2024.
//

#ifndef PEA11_BRUTEFORCE_H
#define PEA11_BRUTEFORCE_H


#include <vector>
#include "Graph.h"

class Bruteforce {
public:
    // Konstruktor, który przyjmuje referencję do obiektu klasy Graph
    Bruteforce(const Graph& graph);

    // Funkcja do rozwiązania problemu TSP przy użyciu algorytmu brute-force
    int solve();

private:
    const Graph& graph;  // Referencja do obiektu klasy Graph

    // Funkcja do obliczania kosztu trasy dla danej permutacji
    int calculateRouteCost(const std::vector<int>& route) const;
};

#endif // BRUTEFORCE_H
