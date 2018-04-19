#include "process.h"
#include "math.h"
#include "triplet.h"
#include <iostream>
#include "string.h"
using namespace std;

double process::squares[181];

void process::init(){
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
        teta = 3.1415926/2; // PI/2
        cout<<"LOL"<<endl;
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
    double a = sqrt(ax*ax + ay*ay + az*az);

    double bx = facet.getVer2().getX();
    double by = facet.getVer2().getY();
    double bz = facet.getVer2().getZ();
    double b = sqrt(bx*bx + by*by + bz*bz);

    double cx = facet.getVer3().getX();
    double cy = facet.getVer3().getY();
    double cz = facet.getVer3().getZ();
    double c = sqrt(cx*cx + cy*cy + cz*cz);

    double p = (a + b + c)/2;
    double area = sqrt(p*(p-a)*(p-b)*(p-c));
    cout<<"A: "<<a<<endl;
    cout<<"B: "<<b<<endl;
    cout<<"C: "<<c<<endl;
    cout<<"Area:"<<area<<endl;

   // return area;

    Triplet* v1 = new Triplet();
    v1->setX(bx - ax);
    v1->setY(by - ay);
    v1->setZ(bz - az);

    Triplet* v2 = new Triplet();
    v2->setX(cx - ax);
    v2->setY(cy - ay);
    v2->setZ(cz - az);

    //Cross procduct
    Triplet* v3 = new Triplet();
    v3->setX((v1->getY())*(v2->getZ()) - (v1->getZ())*(v2->getY()));
    v3->setY((v1->getZ())*(v2->getX()) - (v1->getX())*(v2->getZ()));
    v3->setZ((v1->getX())*(v2->getY()) - (v1->getY())*(v2->getX()));

//    v3->setX(6);
    cout<<"!!!!!!!!:"<<v3->getX()<<endl;
    cout<<"XXXXXXX:"<<v3->getX()<<endl;
    cout<<"XXXXXXX:"<<v3->getY()<<endl;
    cout<<"XXXXXXX:"<<v3->getZ()<<endl;

    return 0.5*sqrt(v3->getX()*v3->getX()
                    +v3->getY()*v3->getY()
                    +v3->getZ()*v3->getZ());




    //return abs((ax*(by - cy) + bx*(cy - ay) + cx*(ay - by))/2);
}
