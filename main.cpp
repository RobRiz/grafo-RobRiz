#include <iostream>
#define MAX_NODI 100
#define INF 1000000000 // Valore per indicare assenza di connessione

class Grafo {
private:
    int matrice[MAX_NODI][MAX_NODI]; // Matrice di adiacenza
    bool esisteNodo[MAX_NODI]; // Indica se un nodo esiste
    int numeroNodi; // Numero attuale di nodi

public:
    Grafo() : numeroNodi(0) {
        for (int i = 0; i < MAX_NODI; ++i) {
            esisteNodo[i] = false;
            for (int j = 0; j < MAX_NODI; ++j) {
                matrice[i][j] = INF;
            }
        }
    }

    void aggiungiNodo(int nodo) {
        if (numeroNodi >= MAX_NODI || esisteNodo[nodo]) {
            std::cout << "Errore: Nodo non valido o già esistente.\n";
            return;
        }
        esisteNodo[nodo] = true;
        matrice[nodo][nodo] = 0; // Distanza nodo a se stesso
        numeroNodi++;
    }

    void aggiungiArco(int da, int a, int peso) {
        if (!esisteNodo[da] || !esisteNodo[a]) {
            std::cout << "Errore: Uno o entrambi i nodi non esistono.\n";
            return;
        }
        matrice[da][a] = peso;
    }

    void stampa() {
        std::cout << "Matrice di adiacenza:\n";
        for (int i = 0; i < MAX_NODI; ++i) {
            if (!esisteNodo[i]) continue;
            for (int j = 0; j < MAX_NODI; ++j) {
                if (!esisteNodo[j]) continue;
                if (matrice[i][j] == INF) {
                    std::cout << "INF ";
                } else {
                    std::cout << matrice[i][j] << " ";
                }
            }
            std::cout << "\n";
        }
    }
};

int main() {
    Grafo grafo;

    grafo.aggiungiNodo(0);
    grafo.aggiungiNodo(1);
    grafo.aggiungiNodo(2);

    grafo.aggiungiArco(0, 1, 10);
    grafo.aggiungiArco(1, 2, 20);

    std::cout << "Grafo:\n";
    grafo.stampa();

    return 0;
}
