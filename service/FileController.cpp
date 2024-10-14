#include "FileController.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

Graph FileController::readDataFromFile(const std::string& fileName) {
    std::ifstream file(fileName);

    if (!file.is_open()) {
        throw std::runtime_error("Nie udalo sie otworzyc pliku.");
    }

    std::string line;
    int vertices;

    if (std::getline(file, line)) {
        std::istringstream iss(line);
        iss >> vertices;
    }

    Graph graph(vertices);

    int i = 0;
    while (std::getline(file, line) && i < vertices) {
        std::istringstream iss(line);
        int j = 0, weight;

        while (iss >> weight && j < vertices) {
            graph.setEdge(i, j, weight);
            ++j;
        }
        ++i;
    }

    file.close();
    return graph;
}
