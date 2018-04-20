#include <iostream>
#include "parse.h"

bool parse_double(std::string str, double& value){
    try{
         value = std::stod(str);
    }catch(const std::invalid_argument& e){
        return false;
    }
    return true;
}

bool parse_normal(std::ifstream& file, Facet& facet){
    double x, y, z;
    std::string word;
    if (((file >> word) && (word == "normal"))
        &&(file >> word)&&parse_double(word, x)
        &&(file >> word)&&parse_double(word, y)
        &&(file >> word)&&parse_double(word, z))
    {
        facet.setNorm(x, y, z);
        return true;
    }
    return false;
}

bool parse_outer_loop(std::ifstream& file){
    std::string word;
    return ((file >> word) && (word == "outer")
          &&(file >> word) && (word == "loop"));
}

bool parse_vertex(int n, std::ifstream& file, Facet& facet){
    Vector& vertex = facet.getVertex(n);
    double x, y, z;
    std::string word;
    if ((file >> word) && (word == "vertex")
        &&(file >> word)&&parse_double(word, x)
        &&(file >> word)&&parse_double(word, y)
        &&(file >> word)&&parse_double(word, z))
    {
        vertex.set_x(x);
        vertex.set_y(y);
        vertex.set_z(z);
        return true;
    }
    return false;
}

bool parse_endloop(std::ifstream& file){
    std::string word;
    return ((file >> word) && (word == "endloop"));
}

bool parse_endfacet(std::ifstream& file){
    std::string word;
    return ((file >> word) && (word == "endfacet"));
}

bool parse::parse_facet(std::ifstream& file, Facet& facet){
    return (parse_normal(file, facet)
            && parse_outer_loop(file)
            &&parse_vertex(1, file, facet)
            &&parse_vertex(2, file, facet)
            &&parse_vertex(3, file, facet)
            &&parse_endloop(file)
            &&parse_endfacet(file));
}
