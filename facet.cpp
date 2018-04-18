#include "facet.h"
#include<iostream>

Triplet& Facet::getNorm()
{
    return norm;
}

void Facet::setNorm(double x, double y, double z)
{
    norm.setX(x);
    norm.setY(y);
    norm.setZ(z);
}

Triplet& Facet::getVer1()
{
    return ver1;
}

void Facet::setVer1(double x, double y, double z)
{
    ver1.setX(x);
    ver1.setY(y);
    ver1.setZ(z);
}

Triplet& Facet::getVer2()
{
    return ver2;
}

void Facet::setVer2(double x, double y, double z)
{//    norm = Triplet();
    //    ver1 = Triplet();
    //    ver2 = Triplet();
    //    ver3 = Triplet();
    ver2.setX(x);
    ver2.setY(y);
    ver2.setZ(z);
}

Triplet& Facet::getVer3()
{
    return ver3;
}

void Facet::setVer3(double x, double y, double z)
{
    ver3.setX(x);
    ver3.setY(y);
    ver3.setZ(z);
}

Triplet& Facet::getVertex(int n)
{
    switch (n) {
        case 1:
            return ver1;
        case 2:
            return ver2;
        case 3:
            return ver3;
        default:
            break;
        }
}

Facet::Facet()
{
//    norm = Triplet();
//    ver1 = Triplet();
//    ver2 = Triplet();
//    ver3 = Triplet();
}

