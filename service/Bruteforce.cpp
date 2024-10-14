#include "Bruteforce.h"
#include <algorithm>
#include <limits>

// Konstruktor, który przyjmuje graf
Bruteforce::Bruteforce(const Graph& graph) : graph(graph) {}

// Funkcja do obliczania kosztu trasy dla danej permutacji
int Bruteforce::calculateRouteCost(const std::vector<int>& route) const {
    int cost = 0;

    // Przechodzimy przez całą trasę i obliczamy sumę wag krawędzi
    for (size_t i = 0; i < route.size() - 1; ++i) {
        cost += graph.getEdge(route[i], route[i + 1]);
    }

    // Dodajemy koszt powrotu do początkowego wierzchołka
    cost += graph.getEdge(route.back(), route[0]);

    return cost;
}

// Funkcja do rozwiązania problemu TSP brute-force
int Bruteforce::solve() {
    int vertices = graph.getVertices();
    std::vector<int> vertexOrder(vertices);

    // Inicjalizacja permutacji (0, 1, 2, ..., vertices-1)
    for (int i = 0; i < vertices; ++i) {
        vertexOrder[i] = i;
    }

    int minCost = std::numeric_limits<int>::max();

    // Generowanie wszystkich permutacji i obliczanie kosztów tras
    do {
        int currentCost = calculateRouteCost(vertexOrder);
        if (currentCost < minCost) {
            minCost = currentCost;
        }
    } while (std::next_permutation(vertexOrder.begin(), vertexOrder.end()));

    return minCost;  // Zwracamy minimalny koszt
}
