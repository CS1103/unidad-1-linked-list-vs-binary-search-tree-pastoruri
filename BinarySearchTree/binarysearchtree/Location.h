
//
// Created by ruben on 4/5/19.
//

#ifndef LINKEDLISTVSBINARYTREE_LOCATION_H
#define LINKEDLISTVSBINARYTREE_LOCATION_H
#include <string>
#include <ostream>


class Location {
    std::string position_id;
    std::string state_code;
    std::string county;
    double latitude;
    double longitude;
    std::string line;
    std::string construction;
public:
    Location()=default;
    Location(
            std::string position_id,
            std::string state_code,
            std::string county,
            double latitude,
            double longitude,
            std::string line,
            std::string construction): position_id{position_id}, state_code{state_code}, county{county}, latitude{latitude}, longitude{longitude}, line{line}, construction{construction} {};

    friend std::ostream &operator<<(std::ostream &os, const Location &location) {
        os << "Position ID: " << location.position_id << " | State Code: " << location.state_code << " | County: "
           << location.county << " | Latitude: " << location.latitude << " | Longitude: " << location.longitude << " | Line: "
           << location.line << " | Construction: " << location.construction << "\n";
        return os;
    }
   std::string get_position_id();
    // Cree que sea necesario agregar destructor, justifique
    //no creo que sea necesario pues ningun dato de la clase es dinamico

};

#endif //LINKEDLISTVSBINARYTREE_LOCATION_H
