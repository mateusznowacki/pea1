//
// Created by matty on 14.10.2024.
//
#include <iostream>
#include "FileController.h"
#include "Bruteforce.h"

int main() {
    try {
        Graph graph = FileController::readDataFromFile("data.txt");

        std::cout << "Macierz sąsiedztwa:" << std::endl;
        graph.display();

        // Tworzymy obiekt Bruteforce i rozwiązujemy problem TSP
        Bruteforce bruteForceSolver(graph);
        int minCost = bruteForceSolver.solve();

        std::cout << "Minimalny koszt trasy: " << minCost << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }


    return 0;
}
