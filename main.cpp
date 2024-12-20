#include <iostream>
#include "Grafo.cpp" 





int main() {
    // Creazione del grafo
    Grafo<int> rete;
    // Aggiunta dei nodi (numeri interi)
    rete.aggiungiNodo(10);
    rete.aggiungiNodo(20);
    rete.aggiungiNodo(30);
    rete.aggiungiNodo(40);
    rete.aggiungiNodo(50);
    // Aggiunta degli archi con pesi
    rete.aggiungiArco(10, 20, 8);
    rete.aggiungiArco(10, 30, 6);
    rete.aggiungiArco(20, 40, 4);
    rete.aggiungiArco(30, 50, 7);
    rete.aggiungiArco(40, 50, 2);
    rete.aggiungiArco(50, 20, 9);
    // Stampa della matrice di adiacenza del grafo
    rete.stampa();
    // Verifica se un nodo esiste
    std::cout << "Esiste il nodo 30? " << (rete.verificaNodo(30) ? "Sì" : "No") << std::endl;
    // Verifica se un arco esiste
    std::cout << "Esiste un arco tra 10 e 20? " << (rete.verificaArco(10, 20) ? "Sì" : "No") << std::endl;
    std::cout << "Esiste un arco tra 10 e 40? " << (rete.verificaArco(10, 40) ? "Sì" : "No") << std::endl;
    // Visualizza i nodi adiacenti a un nodo
    rete.nodiAdiacenti(10);
    // Rimuove un arco
    rete.rimuoviArco(10, 20);
    std::cout << "Matrice di Adiacenza dopo la rimozione dell'arco tra 10 e 20:" << std::endl;
    rete.stampa();
    // Rimuove un nodo
    rete.rimuoviNodo(30);
    std::cout << "Matrice di Adiacenza dopo la rimozione del nodo 30:" << std::endl;
    rete.stampa();
    // Aggiunta di un nuovo nodo e arco
    rete.aggiungiNodo(60);
    rete.aggiungiArco(50, 60, 12);
    std::cout << "Matrice di Adiacenza dopo l'aggiunta del nodo 60 e dell'arco tra 50 e 60:" << std::endl;
    rete.stampa();
    // Verifica connettività tra due nodi
    std::cout << "Il nodo 10 è connesso al nodo 50? " << (rete.verificaArco(10, 50) ? "Sì" : "No") << std::endl;
    // Trova l'arco con peso minore per un nodo
    int arcoMinimo = rete.arcoConPesoMinore(50);
    if (arcoMinimo != -1) {
        std::cout << "L'arco con il peso minimo da 50 ha peso: " << arcoMinimo << std::endl;
    } else {
        std::cout << "Non ci sono archi uscenti da 50." << std::endl;
    }
    return 0;
}
