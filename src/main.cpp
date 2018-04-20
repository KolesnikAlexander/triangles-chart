#include <iostream>
#include <fstream>
#include "facet.h"
#include "process.h"
#include "parse.h"

using namespace std;

string INPUT_FILE_PATH = "in.stl";
string OUTPUT_FILE_PATH = "out.csv";

bool open_inp_file(ifstream& input_file){
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

bool execute(ifstream& input_file){
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
    ifstream input_file;
    if(!open_inp_file(input_file)){
        cout<<"Put \""<<INPUT_FILE_PATH<<"\" in a current directory"<<endl;
        return -1;
    }
    process::init();
    if(!execute(input_file)){
        cout<<"Corrupted format"<<endl;
        return -1;
    }
    input_file.close();
    if(!makeCSV()){
        cerr<< "Failed to create an output file"<<endl;
        return -1;
    }
    cout<<"Handling \""<<INPUT_FILE_PATH<<"\"..."<<endl;
    cout<<"Done. The result is in \""<<OUTPUT_FILE_PATH<<"\"."<<endl;
    return 0;
}
