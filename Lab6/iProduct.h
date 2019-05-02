// Workshop: Lab-6
// File: iProduct.h
// Date: 30-Oct-2018
// Name: Gayane Babayan
// ID:   107-061-160

#ifndef W_IPRODUCT_H_
#define W_IPRODUCT_H_

#include <iostream>

namespace w6 {

   class iProduct {
   public:
      virtual double getPrice() const = 0;
      virtual void display(std::ostream& os) const = 0;
   };
   // end scope of the namespace
}
#endif
