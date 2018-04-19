#include <iostream>
#include "parse.h"

bool parse_normal(std::ifstream& file, Facet& facet){
    double x, y, z;
    std::string word;
    if ((file >> word) && (word == "normal")){
        if(file >> word){
            x = atof(word.c_str());
            if(file >> word){
                y = atof(word.c_str());
                if(file >> word){
                    z = atof(word.c_str());
                    facet.setNorm(x, y, z);
                    return true;
                }
            }
        }
    }
    return false;
}

bool parse_outer_loop(std::ifstream& file){
    std::string word;
    if ((file >> word) && (word == "outer")
      &&(file >> word) && (word == "loop")){
        return true;
    }
    else
        return false;
}

bool parse_vertex(int n, std::ifstream& file, Facet& facet){
    Triplet& vertex = facet.getVertex(n);
    double x, y, z;
    std::string word;
    if ((file >> word) && (word == "vertex")){
        if(file >> word){
            x = atof(word.c_str());
            vertex.setX(x);
            if(file >> word){
                y = atof(word.c_str());
                vertex.setY(y);
                if(file >> word){
                    z = atof(word.c_str());
                    vertex.setZ(z);
                    return true;
                }
            }
        }
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
