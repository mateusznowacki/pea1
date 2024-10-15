#ifndef PEA11_FILECONTROLLER_H
#define PEA11_FILECONTROLLER_H

#include <string>
#include <fstream>
#include <stdexcept>
#include <chrono>
#include "Graph.h"

class FileController {
public:
    // Funkcja do odczytu danych z pliku i zwrócenia obiektu Graph
    static Graph readDataFromFile(const std::string &fileName);

    // Funkcje do odczytu z pliku konfiguracyjnego
    bool fileGetDisplay(const std::string &configFileName);
    bool fileGetProgress(const std::string &configFileName);

    std::string getInputFileName(const std::string &configFileName);
    std::string getOutputFileName(const std::string &configFileName);
    std::string getInstanceName(const std::string &configFileName);

    int fileGetIterations(const std::string &configFileName);

    int fileGetOptimalCost(std::string basicString);

    std::string fileGetOptimalPath(std::string basicString);

    void saveResultsToCSV(
            const std::string& outputFileName,
            const std::string& inputFileName,
            int inputOptimalCost,
            const std::string& optimalPath,
            int foundCost,
            const std::string& foundPath,
            std::chrono::duration<double> executionTime
    );
private:
    // Pomocnicza funkcja do odczytu wartości z pliku konfiguracyjnego
    std::string getConfigValue(const std::string &configFileName, const std::string &key);
};

#endif // PEA11_FILECONTROLLER_H
