#include "Bruteforce.h"
#include <algorithm>
#include <limits>
#include <iostream>
#include <sstream>  // Do konwersji ścieżki na string

Bruteforce::Bruteforce(const Graph &graph, bool showProgress)
        : graph(graph), showProgress(showProgress), minCost(std::numeric_limits<int>::max()) {
}

// Funkcja do obliczania kosztu trasy dla danej permutacji
int Bruteforce::calculateRouteCost(const std::vector<int> &route) const {
    int cost = 0;

    for (size_t i = 0; i < route.size() - 1; ++i) {
        cost += graph.getEdge(route[i], route[i + 1]);
    }

    cost += graph.getEdge(route.back(), route[0]);

    return cost;
}

// Rozwiązywanie problemu TSP brute-force
int Bruteforce::solve(int optimalCost, const std::vector<int> &optimalPath) {
    int vertices = graph.getVertices();
    std::vector<int> vertexOrder(vertices);
    for (int i = 0; i < vertices; ++i) {
        vertexOrder[i] = i;
    }

    auto start = std::chrono::high_resolution_clock::now();
    size_t permutationCount = 0;
    size_t totalPermutations = 1;

    if (showProgress) {
        std::cout << "Trwa obliczanie";
    }

    // Obliczamy liczbę wszystkich permutacji
    for (int i = 2; i <= vertices; ++i) {
        totalPermutations *= i;
    }

    // Generowanie wszystkich permutacji i obliczanie kosztów tras
    do {
        int currentCost = calculateRouteCost(vertexOrder);
        if (currentCost < minCost) {
            minCost = currentCost;
            bestPath = vertexOrder;  // Zapisz aktualnie najlepszą ścieżkę
        }

        if (showProgress) {
            ++permutationCount;
            if (permutationCount % 100 == 0) {
                std::cout << ".";
            }
        }

    } while (std::next_permutation(vertexOrder.begin(), vertexOrder.end()));

    auto end = std::chrono::high_resolution_clock::now();
    executionTime = end - start;

    return minCost;
}

// Funkcja zwracająca najlepszą ścieżkę jako string
std::string Bruteforce::getBestPath() {
    std::ostringstream oss;
    for (const auto& node : bestPath) {
        oss << node << " ";
    }
    return oss.str();
}

// Funkcja zwracająca czas wykonania
std::chrono::duration<double> Bruteforce::getExecutionTime() {
    return executionTime;
}

// Funkcja zwracająca minimalny koszt
int Bruteforce::getMinCost() {
    return minCost;
}
