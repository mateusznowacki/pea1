#include "Algorithm.h"

// Konstruktor
Algorithm::Algorithm(const Graph& g) : graph(g) {}

// Funkcja do zamiany dwóch elementów
void Algorithm::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Funkcja generująca kolejną permutację leksykograficzną
bool Algorithm::nextPermutation(std::vector<int>& sequence) {
    int n = sequence.size();
    int i = n - 2;

    // Znalezienie pierwszej pozycji i, gdzie sequence[i] < sequence[i + 1]
    while (i >= 0 && sequence[i] >= sequence[i + 1]) {
        i--;
    }

    // Jeśli i jest mniejsze od 0, to nie ma już więcej permutacji
    if (i < 0) return false;

    // Znalezienie pierwszego elementu sequence[j] większego niż sequence[i]
    int j = n - 1;
    while (sequence[j] <= sequence[i]) {
        j--;
    }

    // Zamiana sequence[i] z sequence[j]
    swap(sequence[i], sequence[j]);

    // Odwrócenie kolejności elementów po pozycji i
    reverse(sequence, i + 1, n - 1);

    return true;
}

// Funkcja do odwrócenia elementów wektora od pozycji `start` do `end`
void Algorithm::reverse(std::vector<int>& sequence, int start, int end) {
    while (start < end) {
        swap(sequence[start], sequence[end]);
        start++;
        end--;
    }
}

// Funkcja brute-force do rozwiązywania problemu TSP
int Algorithm::tspBruteForce(int start) {
    int V = graph.getVerticesCount();  // Pobranie liczby wierzchołków
    std::vector<int> vertices;

    // Zbieramy wszystkie wierzchołki poza wierzchołkiem startowym
    for (int i = 0; i < V; ++i) {
        if (i != start) {
            vertices.push_back(i);
        }
    }

    // Inicjalizacja zmiennej przechowującej minimalny koszt
    int minPathCost = INT_MAX;

    // Generowanie permutacji ręcznie i obliczanie kosztów ścieżki
    do {
        int currentPathCost = 0;
        int k = start;

        // Obliczamy koszt obecnej ścieżki
        for (int i = 0; i < vertices.size(); i++) {
            currentPathCost += graph.getEdgeWeight(k, vertices[i]);
            k = vertices[i];
        }

        // Dodajemy koszt powrotu do miasta początkowego
        currentPathCost += graph.getEdgeWeight(k, start);

        // Aktualizacja minimalnej ścieżki
        minPathCost = std::min(minPathCost, currentPathCost);

    } while (nextPermutation(vertices));

    return minPathCost;
}
