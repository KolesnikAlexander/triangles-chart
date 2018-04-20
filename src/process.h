#ifndef PROCESS_H
#define PROCESS_H
#include "facet.h"
namespace process {
    extern double squares[181];// from -90 to 90
    void init();
    double angle(Facet &facet);
    double area(Facet &facet);
}
#endif // PROCESS_H
