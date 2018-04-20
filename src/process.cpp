#define _USE_MATH_DEFINES
#include "process.h"
#include "math.h"
#include "vector.h"
#include <iostream>
#include "string.h"
using namespace std;

double process::squares[181];

void process::init(){
    memset(squares, 0, sizeof(squares));
}

double process::angle(Facet &facet){
    Vector& norm = facet.getNorm();
    double x = norm.get_x();
    double y = norm.get_y();
    double z = norm.get_z();

    double tanTeta;
    double teta;
    double sqrsum = sqrt(x*x + y*y);
    if(sqrsum == 0){
        teta = M_PI/2;
    }
    else{
        tanTeta = z/sqrsum;
        teta = atan(tanTeta);
    }
    int teta_degrees = round(teta * (180.0/M_PI));
    return teta_degrees;
}

double process::area(Facet &facet)
{
    double ax = facet.getVer1().get_x();
    double ay = facet.getVer1().get_y();
    double az = facet.getVer1().get_z();

    double bx = facet.getVer2().get_x();
    double by = facet.getVer2().get_y();
    double bz = facet.getVer2().get_z();

    double cx = facet.getVer3().get_x();
    double cy = facet.getVer3().get_y();
    double cz = facet.getVer3().get_z();

    Vector* v1 = new Vector();
    v1->set_x(bx - ax);
    v1->set_y(by - ay);
    v1->set_z(bz - az);

    Vector* v2 = new Vector();
    v2->set_x(cx - ax);
    v2->set_y(cy - ay);
    v2->set_z(cz - az);

    //Cross procduct
    Vector* v3 = new Vector();
    v3->set_x(v1->get_y()*v2->get_z() - v1->get_z()*v2->get_y());
    v3->set_y(v1->get_z()*v2->get_x() - v1->get_x()*v2->get_z());
    v3->set_z(v1->get_x()*v2->get_y() - v1->get_y()*v2->get_x());

    return 0.5*sqrt(v3->get_x()*v3->get_x()
                    +v3->get_y()*v3->get_y()
                    +v3->get_z()*v3->get_z());
}
