#include <iostream>
#include <fstream>

using namespace std;
ifstream file;

class Facet
{
public:
    double norm_x;
    double norm_y;
    double norm_z;

    double ver1_x;
    double ver1_y;
    double ver1_z;

    double ver2_x;
    double ver2_y;
    double ver2_z;

    double ver3_x;
    double ver3_y;
    double ver3_z;
};

void init_file(){
    file.open ("program1.stl");
}
bool parse_normal(std::ifstream& file, Facet& facet){
    std::string word;
    if ((file >> word) && (word == "normal")){
        if(file >> word){
            cout<<"DBL1:"<<word<<endl;
            facet.norm_x = atof(word.c_str());
            if(file >> word){
                cout<<"DBL2:"<<word<<endl;
                facet.norm_y = atof(word.c_str());
                if(file >> word){
                    cout<<"DBL3:"<<word<<endl;
                    facet.norm_z = atof(word.c_str());
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
    std::string word;
    if ((file >> word) && (word == "vertex")){
        if(file >> word){
            cout<<"VDBL1: --"<<n<<"--"<<word<<endl;
            facet.ver1_x = atof(word.c_str());
            if(file >> word){
                cout<<"VDBL2: --"<<n<<"--"<<word<<endl;
                facet.ver1_y = atof(word.c_str());
                if(file >> word){
                    cout<<"VDBL3: --"<<n<<"--"<<word<<endl;
                    facet.ver1_z = atof(word.c_str());
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
void process_facet(const Facet& facet){
    cout << std::scientific;
    std::cout.precision(6);

    cout<<"!!!!!!!!!!! FACET !!!!!!!!!!!!!!"<<endl;
    cout<<"Norm x:"<<facet.norm_x<<endl;
    cout<<"Norm y:"<<facet.norm_y<<endl;
    cout<<"Norm z:"<<facet.norm_z<<endl;

    cout<<"Ver1 x:"<<facet.ver1_x<<endl;
    cout<<"Ver1 y:"<<facet.ver1_y<<endl;
    cout<<"Ver1 z:"<<facet.ver1_z<<endl;

    cout<<"Ver2 x:"<<facet.ver2_x<<endl;
    cout<<"Ver2 y:"<<facet.ver2_y<<endl;
    cout<<"Ver2 z:"<<facet.ver2_z<<endl;

    cout<<"Ver3 x:"<<facet.ver3_x<<endl;
    cout<<"Ver3 y:"<<facet.ver3_y<<endl;
    cout<<"Ver3 z:"<<facet.ver3_z<<endl;

}
bool execute(){
    std::string word;
    if ((file >> word) && (word == "solid")){
        std::getline(file, word); //skip line
        cout << "SOLID: "<<word<<endl;

        while ((file >> word) && (word == "facet")) {
            Facet facet;
            if(!parse_facet(file, facet))
                return false;
             else{
                process_facet(facet);
            }
        }

        if(word == "endsolid"){
            cout << "ENDSOLID"<<endl;
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
     bool localProcess = execute();
    cout << "PROCESS: "<< localProcess <<endl;

    return 0;
}
