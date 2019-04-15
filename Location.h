//
// Created by ruben on 4/5/19.
//

#ifndef LINKEDLISTVSBINARYTREE_LOCATION_H
#define LINKEDLISTVSBINARYTREE_LOCATION_H
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
class Location {
    int position_id;
    std::string state_code;
    std::string county;
    double latitude;
    double longitude;
    std::string line;
    std::string construction;
public:
    Location(
            int position_id1,
            string state_code1,
            string county1,
            double latitude1,
            double longitude1,
            string line1,
            string construction1):position_id{position_id1},state_code(state_code1),county(county1),latitude(latitude1),longitude(longitude1),line(line1),construction(construction1){};
    int get_id();
    string get_state_code();
    string get_county();
    double get_latitude();
    double get_longitude();
    string get_line();
    string get_construction();
    string get_all();
    ~Location(){};

    // Declare los metodos que crea necesario

    // Cree que sea necesario agregar destructor, justifique
    // No es necesario debido a que no contiene ningun elemento que se deba eliminar especialmente. Los destructores de las clases que contengan a Location, se encargaran de borrar la informacion

};


#endif //LINKEDLISTVSBINARYTREE_LOCATION_H
