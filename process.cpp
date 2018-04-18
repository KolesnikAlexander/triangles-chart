#include "process.h"
#include "math.h"
#include "triplet.h"
#include <iostream>
#include "string.h"
using namespace std;

double process::squares[181];

double process::init(){
    memset(squares, 0, sizeof(squares));
}

double process::process(Facet &facet){
    double norm_angle = process::angle(facet);
}

double process::angle(Facet &facet){
    Triplet& norm = facet.getNorm();
    double x = norm.getX();
    double y = norm.getY();
    double z = norm.getZ();
    double tanTeta;
//    if(z == 0){
//        tanTeta = 1;
//    }

    double xsqr = x*x;
    double ysqr = y*y;
    double sum  = xsqr + ysqr;
    cout <<"SUM"<<sum<<endl;
    double sqrsum = sqrt(sum);
    cout <<"SQRT SUM"<<sqrsum<<endl;

    double teta;
    if(sqrsum == 0){
        teta = 90;
    }
    else{
        tanTeta = z/sqrsum;
        teta = atan(tanTeta);
    }

    cout<<"TETA"<<tanTeta<<endl;
    int teta_degrees = round(teta * (180.0/3.1415926));
//    if(z < 0)
//        teta_degrees*=-1;

    return teta_degrees;
}

double process::triangle_area(Facet &facet)
{
    double ax = facet.getVer1().getX();
    double ay = facet.getVer1().getY();
    double az = facet.getVer1().getZ();

    double bx = facet.getVer2().getX();
    double by = facet.getVer2().getY();
    double bz = facet.getVer2().getZ();

    double cx = facet.getVer3().getX();
    double cy = facet.getVer3().getY();
    double cz = facet.getVer3().getZ();

    return abs((ax*(by - cy) + bx*(cy - ay) + cx*(ay - by))/2);
}
