#include <iostream>
#include "FileController.h"
#include "Bruteforce.h"
#include "ConsolePrinter.h"

int main() {
    ConsolePrinter consolePrinter;
    FileController fileController;
    try {
        std::string configFileName = "config.txt";
        std::string inputFileName = fileController.getInputFileName(configFileName);
        std::string outputFileName = fileController.getOutputFileName(configFileName);
        std::string getInputOptimalPath = fileController.fileGetOptimalPath(inputFileName);
        bool displayResults = fileController.fileGetDisplay(configFileName);
        bool showProgress = fileController.fileGetProgress(configFileName);
        int iterations = fileController.fileGetIterations(configFileName);
        int inputOptimalCost = fileController.fileGetOptimalCost(inputFileName);


        Graph graph = fileController.readDataFromFile(inputFileName);

        consolePrinter.printStartInfo(inputFileName, outputFileName, displayResults,
                                      showProgress, iterations, inputOptimalCost, getInputOptimalPath);

        for (int i = 0; i < iterations; i++) {
            Bruteforce bruteForceSolver(graph, showProgress);

            bruteForceSolver.solve();
            if (displayResults) {
                consolePrinter.printEndInfo(bruteForceSolver.getMinCost(), bruteForceSolver.getBestPath(),
                                            bruteForceSolver.getExecutionTime(), inputOptimalCost);
                fileController.saveResultsToCSV(outputFileName, inputFileName, inputOptimalCost,
                                                bruteForceSolver.getBestPath(), bruteForceSolver.getMinCost(),
                                                bruteForceSolver.getBestPath(), bruteForceSolver.getExecutionTime());


            }
        }

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

