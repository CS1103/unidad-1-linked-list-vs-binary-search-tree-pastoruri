//CODIGO REALIZADO EN GRUPO POR BENJAMIN DIAZ, GABRIEL SPRANGER Y RODRIGO CESPEDES
#include <iostream>
#include <sstream>
#include <string>
#include "Location.h"
#include <vector>
#include <fstream>
#include <chrono>
#include "LinkedList.h"
#include "BinarySearchTree.h"



// Nombres de archivos
const std::string LOCATION_FILE = "Locations.csv";
const std::string SEARCH_FILE = "Search.txt";

int main() {


    // Declarando variables

    auto* ll =  new LinkedList();
    auto* bst = new BinarySearchTree();

    std::vector<int> vsearch;

    // Grabar Datos del archivo "Locations.csv" en ll

    load_ll_locations(ll, LOCATION_FILE);

    // Grabar Datos del archivo "Locations.csv" en bst

    load_bst_locations(bst, LOCATION_FILE);

    // Leer los datos del archivo "Search.txt" y grabarlos en vsearch

    std::ifstream search_data_source;
    search_data_source.open("Search.txt");

    std::string search_item;

    if (search_data_source.is_open()) {
        while (search_data_source.good()) {
            getline(search_data_source, search_item);
            vsearch.push_back(atoi(search_item.c_str()));
        }
    } else {
        std::cout << "No se pudo abrir el archivo Search.txt" << std::endl;
    }

    // Utilizar cada item de vsearch para buscar los lugares en ll y bst
    // Calcular los tiempos promedios en cada caso

    double avgtime_ll = 0;
    double avgtime_bst = 0;

    auto inicio = std::chrono::high_resolution_clock::now();
    for (const auto &id: vsearch) {
        // Buscar en ll
        ll->search(std::to_string(id));
    }
    auto fin = std::chrono::high_resolution_clock::now();
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio);

    std::cout << "El tiempo que demora la busqueda en LinkedList es: " << duracion.count() << " microsegundos." << std::endl;

    auto inicio2 = std::chrono::high_resolution_clock::now();
    for (const auto &id: vsearch){
        // Buscar en bst
        bst->search(std::to_string(id));
    }
    auto fin2 = std::chrono::high_resolution_clock::now();
    auto duracion2 = std::chrono::duration_cast<std::chrono::microseconds>(fin2 - inicio2);
    std::cout << "El tiempo que demora la busqueda en BinarySearchTree es: " << duracion2.count() << " microsegundos." << std::endl;


    delete ll;
    delete bst;

    return 0;
}