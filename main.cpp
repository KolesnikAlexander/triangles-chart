#include <iostream>
#include <fstream>

using namespace std;
ifstream file;

struct Facet
{
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
    std::string word;

// read "solid"
    std::getline(file, word);
    cout << "HEADER: "<<word<<endl;
//end read "solid"

//    while (file >> word)
//    {
//        cout <<"WRD: "<< word <<endl;
//    }
}

/*
 * res_code:
 *      0 - ok
 *     -1 - end of steam
 *     -2 - corrupted format
*/
void read_facet(std::ifstream& file, Facet& facet, int& res_code){
    std::string word;
    if (file >> word)
    {
        res_code = 0;
        cout <<"TKN: "<< word <<endl;
    }
    else{
        res_code = -1;
    }
}

//void make_csv(){
//    std::fstream file(CSV_PATH, std::ios::out); // | std::ios::app);
//    if (!file){
//        cerr<< "Failed to open a file"<<endl;
//        return;
//    }
//      double step = (xArray[N]-xArray[0])/NUM_OF_SEG_CSV;
//      for(int i = 1; i <= N; i++){
//          double x = xArray[i-1];
//          file<<x<<" "<<s(i, x)<<endl;
//          x+=step;
//          while(x < xArray[i]){
//              file<<x<<" "<<s(i, x)<<endl;
//              x+=step;
//          }
//      }
//      file<<xArray[N]<<" "<<s(N, xArray[N])<<endl;
//      file.close();

//}

void write_to_csv(double angle, double square){

}


int main()
{
    cout << "Hello World!" << endl;

    init_file();

    Facet facet;
    int res_code;
    read_facet(file, facet,res_code);
    cout << res_code;

    return 0;
}
