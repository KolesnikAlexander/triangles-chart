#include <iostream>
#include <fstream>
#include "facet.h"
#include "process.h"
#include "parse.h"

using namespace std;

string OUTPUT_FILE_PATH = "out.csv";
string INPUT_FILE_PATH = "bunny.stl";

ifstream input_file;
ofstream output_file;

bool open_inp_file(){
    input_file.open (INPUT_FILE_PATH.c_str(), ios::in);
    if(!input_file)
     {
         return false;
     }
     return true;
}

void process_facet(Facet& facet){
    int angle = process::angle(facet); //degrees
    double area = process::area(facet);
    process::squares[angle+90] += area;//from -90 to 90, shifted right in the array
}

bool execute(){
    std::string word;
    if ((input_file >> word) && (word == "solid")){
        std::getline(input_file, word); //skip line
        while ((input_file >> word) && (word == "facet")) {
            Facet* facet = new Facet();
            if(parse::parse_facet(input_file, *facet))
                process_facet(*facet);
             else
                return false;
        }
        return (word == "endsolid");
    }
    else
        return false;
}
bool makeCSV(){
    std::ofstream output_file(OUTPUT_FILE_PATH.c_str(), std::ios::out); // | std::ios::app);
    if (!output_file){
        return false;
    }
    for(int i = 0; i < 181;i++){
        output_file<< i - 90 <<", "<< process::squares[i]<<endl;
    }
    output_file.close();
    return true;
}
int main(){
    if(!open_inp_file()){
        cout<<"Put \""<<INPUT_FILE_PATH<<"\" in a current dirrectory"<<endl;
        return -1;
    }
    process::init();
    if(!execute()){
        cout<<"Corrupted format"<<endl;
        return -1;
    }
    if(!makeCSV()){
        cerr<< "Failed to create an output file"<<endl;
        return -1;
    }
    for(int i = 0; i < 181;i++){
        cout << i - 90 <<": "<< process::squares[i]<<endl;
    }
    return 0;
}
