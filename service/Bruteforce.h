#ifndef PEA11_BRUTEFORCE_H
#define PEA11_BRUTEFORCE_H

#include <vector>
#include "Graph.h"
#include "ConsolePrinter.h"
#include <chrono>

class Bruteforce {
public:
    // Konstruktor, który przyjmuje referencję do obiektu klasy Graph
    Bruteforce(const Graph &graph, bool showProgress );

    // Funkcja do rozwiązania problemu TSP przy użyciu algorytmu brute-force
    int solve(int optimalCost = -1, const std::vector<int> &optimalPath = {});

    std::string getBestPath();

    std::chrono::duration<double> getExecutionTime();

    int getMinCost();

private:
    const Graph &graph;  // Referencja do obiektu klasy Graph
    bool showProgress;  // Zmienna kontrolująca wyświetlanie wyników
    ConsolePrinter consolePrinter;
    std::vector<int> bestPath;  // Przechowuje najlepszą ścieżkę
    std::chrono::duration<double> executionTime;
    int minCost;


    // Funkcja do obliczania kosztu trasy dla danej permutacji
    int calculateRouteCost(const std::vector<int> &route) const;


};

#endif // BRUTEFORCE_H
