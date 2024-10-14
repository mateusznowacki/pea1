
#ifndef PEA11_GRAPH_H
#define PEA11_GRAPH_H



#include <vector>
#include <iostream>

class Graph {
private:
    int vertices;  // Liczba wierzchołków
    std::vector<std::vector<int>> adjacencyMatrix;  // Macierz sąsiedztwa

public:
    // Konstruktor inicjujący liczbę wierzchołków i tworzący pustą macierz sąsiedztwa
    Graph(int vertices);

    // Ustawianie wagi krawędzi między wierzchołkami
    void setEdge(int i, int j, int weight);

    // Pobranie wagi krawędzi między wierzchołkami
    int getEdge(int i, int j) const;

    // Pobranie liczby wierzchołków
    int getVertices() const;

    // Funkcja pomocnicza do wyświetlania grafu
    void display() const;
};

#endif // GRAPH_H
