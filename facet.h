#ifndef FACET_H
#define FACET_H

#include "triplet.h"

class Facet
{
public:
    Triplet norm;
    Triplet ver1;
    Triplet ver2;
    Triplet ver3;

    Facet();
    ~Facet();

    Triplet& getNorm();
    void setNorm(double x, double y, double z);

    Triplet& getVer1();
    void setVer1(double x, double y, double z);

    Triplet& getVer2();
    void setVer2(double x, double y, double z);

    Triplet& getVer3();
    void setVer3(double x, double y, double z);

    Triplet& getVertex(int n);
};

#endif // FACET_H
