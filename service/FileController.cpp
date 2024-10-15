#include "FileController.h"
#include <sstream>
#include <chrono>

// Funkcja do zapisu wyników do pliku CSV
void FileController::saveResultsToCSV(
        const std::string& outputFileName,
        const std::string& inputFileName,
        int inputOptimalCost,
        const std::string& optimalPath,
        int foundCost,
        const std::string& foundPath,
        std::chrono::duration<double> executionTime
) {
    std::ofstream file(outputFileName);

    // Sprawdzanie, czy plik został poprawnie otwarty
    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku do zapisu: " << outputFileName << std::endl;
        return;
    }

    // Obliczanie błędów
    int absoluteError = std::abs(foundCost - inputOptimalCost);
    double relativeError = (static_cast<double>(absoluteError) / inputOptimalCost) * 100;

    // Zapis nagłówka
    file << "Nazwa instancji,Wynik optymalny,Ścieżka optymalna,Znaleziony wynik,Znaleziona ścieżka,"
         << "Czas wykonania (s),Błąd bezwzględny,Błąd względny (%)\n";

    // Zapis danych
    file << inputFileName << ","
         << inputOptimalCost << ",\""
         << optimalPath << "\","
         << foundCost << ",\""
         << foundPath << "\","
         << executionTime << ","
         << absoluteError << ","
         << relativeError << "\n";

    // Zamknięcie pliku
    file.close();
    std::cout << "Wyniki zapisano do pliku: " << outputFileName << std::endl;
}



// Implementacja funkcji readDataFromFile
Graph FileController::readDataFromFile(const std::string& fileName) {
    std::ifstream file(fileName);

    if (!file.is_open()) {
        throw std::runtime_error("Nie udało się otworzyć pliku: " + fileName);
    }

    std::string line;
    int vertices = 0;

    // Odczyt liczby wierzchołków
    if (std::getline(file, line)) {
        std::istringstream iss(line);
        iss >> vertices;
    }

    // Inicjalizacja obiektu grafu
    Graph graph(vertices);

    int i = 0;
    while (std::getline(file, line) && i < vertices) {
        std::istringstream iss(line);
        int j = 0, weight = 0;

        // Wczytywanie wagi krawędzi
        while (iss >> weight && j < vertices) {
            graph.setEdge(i, j, weight);
            ++j;
        }
        ++i;
    }

    file.close();
    return graph;
}


// Funkcja pomocnicza do pobrania wartości z pliku konfiguracyjnego
std::string FileController::getConfigValue(const std::string &configFileName, const std::string &key) {
    std::ifstream configFile(configFileName);
    if (!configFile.is_open()) {
        throw std::runtime_error("Nie udało się otworzyć pliku konfiguracyjnego.");
    }

    std::string line;
    while (std::getline(configFile, line)) {
        std::istringstream iss(line);
        std::string configKey;
        if (std::getline(iss, configKey, '=')) {
            std::string value;
            if (std::getline(iss, value) && configKey == key) {
                return value;
            }
        }
    }

    throw std::runtime_error("Nie znaleziono klucza: " + key);
}

// Funkcja do zapisu wyników do pliku CSV
// Funkcja do zapisu wyników do pliku CSV
void saveResultsToCSV(
        const std::string& outputFileName,
        const std::string& inputFileName,
        int inputOptimalCost,
        const std::string& optimalPath,
        int foundCost,
        const std::string& foundPath,
        double executionTime
) {
    std::ofstream file(outputFileName);

    // Sprawdzanie, czy plik został poprawnie otwarty
    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku do zapisu: " << outputFileName << std::endl;
        return;
    }

    // Obliczanie błędów
    int absoluteError = std::abs(foundCost - inputOptimalCost);
    double relativeError = (static_cast<double>(absoluteError) / inputOptimalCost) * 100;
    // Zapis nagłówka
    file << "Nazwa instancji,Wynik optymalny,Ścieżka optymalna,Znaleziony wynik,Znaleziona ścieżka,"
         << "Czas wykonania (s),Błąd bezwzględny,Błąd względny (%)\n";

    // Zapis danych
    file << inputFileName << ","
         << inputOptimalCost << ",\""
         << optimalPath << "\","
         << foundCost << ",\""
         << foundPath << "\","
         << executionTime << ","
         << absoluteError << ","
         << relativeError << "\n";

    // Zamknięcie pliku
    file.close();
    std::cout << "Wyniki zapisano do pliku: " << outputFileName << std::endl;
}



// Odczyt nazwy pliku wejściowego
std::string FileController::getInputFileName(const std::string &configFileName) {
    return getConfigValue(configFileName, "input_file");
}

// Odczyt nazwy pliku wyjściowego
std::string FileController::getOutputFileName(const std::string &configFileName) {
    return getConfigValue(configFileName, "output_file");
}

// Odczyt wartości display_results
bool FileController::fileGetDisplay(const std::string &configFileName) {
    std::string value = getConfigValue(configFileName, "display_results");
    return (value == "true");
}

// Odczyt wartości show_progress
bool FileController::fileGetProgress(const std::string &configFileName) {
    std::string value = getConfigValue(configFileName, "show_progress");
    return (value == "true");
}

// Odczyt wartości iterations
int FileController::fileGetIterations(const std::string &configFileName) {
    std::string value = getConfigValue(configFileName, "iterations");
    return std::stoi(value);
}

int FileController::fileGetOptimalCost(std::string basicString) {
    std::string value = getConfigValue(basicString, "sum_min");
    return std::stoi(value);
}

std::string FileController::fileGetOptimalPath(std::string basicString) {
    return getConfigValue(basicString, "optimal_path");
}

std::string FileController::getInstanceName(const std::string &configFileName) {
    return getConfigValue(configFileName, "name");
}

