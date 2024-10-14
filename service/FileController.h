#ifndef PEA11_FILECONTROLLER_H
#define PEA11_FILECONTROLLER_H

#include <string>
#include "Graph.h"

class FileController {
public:
    // Funkcja do odczytu danych z pliku i zwrócenia obiektu Graph
    static Graph readDataFromFile(const std::string& fileName);
};

#endif // FILECONTROLLER_H
