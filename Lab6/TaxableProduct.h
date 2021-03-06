#ifndef _TAXABLEPRODUCT_H_
#define _TAXABLEPRODUCT_H_

#include "iProduct.h"
#include "Product.h"

namespace w6 {
   
   class TaxableProduct :public Product {
   private:
      char m_taxed;
   public:
      // default constructor
      TaxableProduct();
      // argument constructor
      TaxableProduct(int prodNum, double prodPrice, char Tax);
      // from the pure virtual class
      double getPrice() const;
      void display(std::ostream& os) const;
   };

   // end scope of the namespace
}

#endif 
