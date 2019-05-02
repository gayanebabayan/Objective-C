// Workshop: Lab-6
// File: Product.h
// Date: 30-Oct-2018
// Name: Gayane Babayan

#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include "iProduct.h"

namespace w6 {

   class Product :public iProduct {
   private:
      int m_prodNo;
      double m_prodPrice;
   public:
      // default constructor
      Product();
      // argument constructor
      Product(int prodNum, double prodPrice);

      // from the pure virtual class
      double getPrice() const;
      void display(std::ostream& os) const;
   };

   // end scope of the namespace
}
#endif
