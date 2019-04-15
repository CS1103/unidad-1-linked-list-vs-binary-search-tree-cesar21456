//
// Created by ruben on 4/5/19.
//

#include "Location.h"

int Location::get_id(){
    return position_id;
}
string Location::get_state_code(){
    return state_code;
}
string Location::get_county(){
    return county;
}
double Location::get_latitude(){
    return latitude;
}
double Location::get_longitude(){
    return longitude;
}
string Location::get_line(){
    return line;

}
string Location::get_construction(){
    return construction;
}
string Location::get_all(){
    string a;
    a+=position_id;
    a+=",";
    a+=state_code;
    a+=",";
    a+=to_string(latitude);
    a+=",";
    a+=to_string(longitude);
    a+=",";
    a+=line;
    a+=",";
    a+=construction;
    return a;
}
