#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

class Graph {
private:
    std::vector<std::vector<int>> adjMatrix;  // Macierz sąsiedztwa
    int V;  // Liczba wierzchołków

public:
    // Konstruktor przyjmujący liczbę wierzchołków
    Graph(int V);

    // Funkcja do dodawania krawędzi (odległości) między wierzchołkami
    void addEdge(int u, int v, int weight);

    // Funkcja zwracająca odległość między dwoma wierzchołkami
    int getEdgeWeight(int u, int v) const;

    // Funkcja zwracająca liczbę wierzchołków
    int getVerticesCount() const;

    // Funkcja do wyświetlania macierzy sąsiedztwa
    void display() const;
};

#endif // GRAPH_H
