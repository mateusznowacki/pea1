#include "FileController.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

// Funkcja do wczytywania grafu z pliku tekstowego
Graph FileController::loadGraphFromFile(const std::string& filename) {
    std::ifstream file(filename);  // Otwieramy plik do odczytu
    if (!file.is_open()) {
        throw std::runtime_error("Nie można otworzyć pliku: " + filename);
    }

    int V;
    file >> V;  // Czytamy rozmiar macierzy (liczba wierzchołków)

    if (file.fail()) {
        throw std::runtime_error("Błąd podczas wczytywania rozmiaru grafu.");
    }

    // Tworzymy graf o rozmiarze VxV
    Graph graph(V);

    // Wczytujemy macierz sąsiedztwa
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            int weight;
            file >> weight;  // Czytamy wagę krawędzi

            if (file.fail()) {
                throw std::runtime_error("Błąd podczas wczytywania wagi krawędzi.");
            }

            // Dodajemy wszystkie krawędzie, nawet te z wagą -1
            graph.addEdge(i, j, weight);
        }
    }

    file.close();  // Zamykamy plik
    return graph;
}
