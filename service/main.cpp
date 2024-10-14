#include "Graph.h"
#include "Algorithm.h"
#include "FileController.h"

int main() {
    // Tworzymy obiekt FileController
    FileController fileController;

    // Wczytujemy graf z pliku "graph.txt"
    Graph g = fileController.loadGraphFromFile("data.txt");

    // Wyświetlamy macierz sąsiedztwa
    g.display();

//    // Tworzymy obiekt algorytmu i przekazujemy graf
//    Algorithm alg(g);
//
//    // Wywołujemy funkcję brute-force TSP z miastem startowym 0
//    int result = alg.tspBruteForce(0);
//
//    // Wyświetlamy wynik
//    std::cout << "Minimalny koszt trasy: " << result << std::endl;

    return 0;
}
