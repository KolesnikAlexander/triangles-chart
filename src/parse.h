#ifndef PARSE_H
#define PARSE_H
#include <fstream>
#include "facet.h"

namespace parse {
    bool parse_facet(std::ifstream& file, Facet& facet);
}

#endif // PARSE_H
