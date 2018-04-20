#include "facet.h"
#include<iostream>

Vector& Facet::getNorm()
{
    return norm;
}

void Facet::setNorm(double x, double y, double z)
{
    norm.set_x(x);
    norm.set_y(y);
    norm.set_z(z);
}

Vector& Facet::getVer1()
{
    return ver1;
}

void Facet::setVer1(double x, double y, double z)
{
    ver1.set_x(x);
    ver1.set_y(y);
    ver1.set_z(z);
}

Vector& Facet::getVer2()
{
    return ver2;
}

void Facet::setVer2(double x, double y, double z)
{
    ver2.set_x(x);
    ver2.set_y(y);
    ver2.set_z(z);
}

Vector& Facet::getVer3()
{
    return ver3;
}

void Facet::setVer3(double x, double y, double z)
{
    ver3.set_x(x);
    ver3.set_y(y);
    ver3.set_z(z);
}

Vector& Facet::getVertex(int n)
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
}

