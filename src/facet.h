#ifndef FACET_H
#define FACET_H

#include "vector.h"

class Facet
{
public:
    Vector norm;
    Vector ver1;
    Vector ver2;
    Vector ver3;

    Facet();

    Vector& getNorm();
    void setNorm(double x, double y, double z);

    Vector& getVer1();
    void setVer1(double x, double y, double z);

    Vector& getVer2();
    void setVer2(double x, double y, double z);

    Vector& getVer3();
    void setVer3(double x, double y, double z);

    Vector& getVertex(int n);
};

#endif // FACET_H
