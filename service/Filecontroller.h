#ifndef PEA11_FILECONTROLLER_H
#define PEA11_FILECONTROLLER_H

#include <string>
#include "Graph.h"

class FileController {
public:
    // Funkcja do wczytywania grafu z pliku tekstowego
    Graph loadGraphFromFile(const std::string& filename);
};

#endif // FILECONTROLLER_H
