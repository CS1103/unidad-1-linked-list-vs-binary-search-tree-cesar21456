#include <iostream>
#include <sstream>
#include <string>

#include <vector>
#include <fstream>
#include "LinkedList.h"
#include "BinarySearchTree.h"
#include <chrono>
// Nombres de archivos
const std::string LOCATION_FILE = "Locations.csv";
const std::string SEARCH_FILE = "Search.txt";
using namespace std;
using namespace UTEC;

void funciona(vector<int>& i,string search_file){
    ifstream archivo2(search_file);
    int a=0;
    string palabra;
    for (int j=0;j<100;j++){
        getline(archivo2,palabra,'\n');
        istringstream(palabra)>>a;
        i.push_back(a);
    }

}



int main() {

    // Declarando variables
    LinkedList ll;
    BinarySearchTree bst;
    vector<int> vsearch;


    // Grabar Datos del archivo "Locations.csv" en bst

    load_locations(&bst,LOCATION_FILE);

    // Grabar Datos del archivo "Locations.csv" en ll
    load_locations2(&ll,LOCATION_FILE);

    // Leer los datos del archivo "Search.txt" y grabarlos en vsearch
    funciona(vsearch,SEARCH_FILE);


    double avgtime_ll = 0;
    double avgtime_bst = 0;

    // Utilizar cada item de vsearch para buscar los lugares en ll y bsd
    // Calcular los tiempos promedios en cada caso
    for (int i=0;i<vsearch.size();i++) {
        // Buscar en bst

        auto start_point1= std::chrono::system_clock::now();
        bst.search(vsearch[i]);
        auto final_point1=std::chrono::system_clock::now();
        std::chrono::duration<double,std::nano>duration1=(final_point1-start_point1);
        avgtime_bst+=duration1.count();


        //buscar en ll
        auto start_point= std::chrono::system_clock::now();
        ll.search(vsearch[i]);
        auto final_point=std::chrono::system_clock::now();
        std::chrono::duration<double,std::nano>duration=(final_point-start_point);
        avgtime_ll+=duration.count();
    }
    cout<<"el tiempo promedio del linked list en nanosegundos="<<avgtime_ll/100<<endl;
    cout<<"el tiempo promedio del arbol binario en nanosegundos="<<avgtime_bst/100<<endl;
    bst.deletear_nodos(bst.get_root());
    ll.deletear_nodos(ll.get_head());
    return 0;
}
