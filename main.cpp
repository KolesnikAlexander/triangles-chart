#include <iostream>
#include <fstream>
#include "facet.h"
#include "process.h"

using namespace std;
ifstream file;

void init_file(){
    file.open ("bunny.stl");
}
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
    if ((file >> word) && (word == "endloop"))
    {
        return true;
    }
    else
        return false;
}
bool parse_endfacet(std::ifstream& file){
    std::string word;
    if ((file >> word) && (word == "endfacet"))
    {
        return true;
    }
    else
        return false;
}
bool parse_facet(std::ifstream& file, Facet& facet){
    if(parse_normal(file, facet)
            && parse_outer_loop(file)
            &&parse_vertex(1, file, facet)
            &&parse_vertex(2, file, facet)
            &&parse_vertex(3, file, facet)
            &&parse_endloop(file)
            &&parse_endfacet(file)){
        return true;
    }
    else{
        return false;
    }
}
void process_facet(Facet& facet){
    cout << std::scientific;
    std::cout.precision(6);

    cout<<"!!!!!!!!!!! FACET !!!!!!!!!!!!!!"<<endl;
    cout<<"Norm x:"<<facet.getNorm().getX()<<endl;
    cout<<"Norm y:"<<facet.getNorm().getY()<<endl;
    cout<<"Norm z:"<<facet.getNorm().getZ()<<endl;

    cout<<"Ver1 x:"<<facet.getVer1().getX()<<endl;
    cout<<"Ver1 y:"<<facet.getVer1().getY()<<endl;
    cout<<"Ver1 z:"<<facet.getVer1().getZ()<<endl;

    cout<<"Ver2 x:"<<facet.getVer2().getX()<<endl;
    cout<<"Ver2 y:"<<facet.getVer2().getY()<<endl;
    cout<<"Ver2 z:"<<facet.getVer2().getZ()<<endl;

    cout<<"Ver3 x:"<<facet.getVer3().getX()<<endl;
    cout<<"Ver3 y:"<<facet.getVer3().getY()<<endl;
    cout<<"Ver3 z:"<<facet.getVer3().getZ()<<endl;

    int angle = process::angle(facet);
    cout<<"Angle: "<<angle<<endl;

    double area = process::triangle_area(facet);
    cout<<"Area: "<<area<<endl;
    process::squares[angle+90] += area;
}

bool execute(){
    std::string word;
    if ((file >> word) && (word == "solid")){
        std::getline(file, word); //skip line
        while ((file >> word) && (word == "facet")) {
            Facet* facet = new Facet();
            if(!parse_facet(file, *facet))
                return false;
             else{
                process_facet(*facet);
            }
        }
        if(word == "endsolid"){
            return true;
        }
        else{
            return false;
        }
    }
    else
        return false;
}

int main()
{
    cout << "Hello World!" << endl;

    init_file();
    process::init();

    bool res = execute();

    for(int i = 0; i < 181;i++){
        cout << i - 90 <<": "<< process::squares[i]<<endl;
    }
    cout << "PROCESS: "<< res <<endl;

    return 0;
}
