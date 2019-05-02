// Workshop: Lab-6
// File: ProdUtil.h
// Date: 30-Oct-2018
// Name: Gayane Babayan
// ID:   107-061-160

#ifndef W6_PRODUTIL_H
#define W6_PRODUTIL_H

#include <iostream>
#include <fstream>
#include "iProduct.h"

namespace w6
{
   // helper functions
   std::ostream& operator<<(std::ostream& os, const iProduct& P);
   iProduct* readProduct(std::ifstream& is);

   // end scope of the namespace
}
#endif