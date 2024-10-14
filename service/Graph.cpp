#include "Graph.h"

// Konstruktor
Graph::Graph(int V) {
    this->V = V;
    adjMatrix.resize(V, std::vector<int>(V, -1));  // Inicjalizacja macierzy wartościami -1 (brak połączeń)

    // Dodatkowo ustawiamy 0 na przekątnej, ponieważ brak krawędzi do samego siebie.
    for (int i = 0; i < V; ++i) {
        adjMatrix[i][i] = 0;  // Koszt połączenia do samego siebie to 0
    }
}

// Funkcja do dodawania krawędzi
void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;  // Graf nieskierowany, więc dodajemy krawędź w obu kierunkach
}

// Funkcja do pobierania wagi krawędzi
int Graph::getEdgeWeight(int u, int v) const {
    return adjMatrix[u][v];
}

// Funkcja zwracająca liczbę wierzchołków
int Graph::getVerticesCount() const {
    return V;
}

// Funkcja do wyświetlania macierzy sąsiedztwa
void Graph::display() const {
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            // Wyświetlamy -1, jeśli brak połączenia
            if (adjMatrix[i][j] == -1) {
                std::cout << "-1 ";
            } else {
                std::cout << adjMatrix[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}
