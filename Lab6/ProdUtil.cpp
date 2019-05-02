// Workshop: Lab-6
// File: ProdUtil.cpp
// Date: 30-Oct-2018
// Name: Gayane Babayan

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <typeinfo>

#include "ProdUtil.h"
#include "iProduct.h"
#include "Product.h"
#include "TaxableProduct.h"

using namespace std;

namespace w6 {

   // helper function: displays the product's content
   //----------------------------------------------------------------------------------------------
   std::ostream& operator<<(std::ostream& os, const iProduct& P) {
      // display the product
      P.display(os);

      // handle the new line, with comparing the instance's type
      if (typeid(P) == typeid(Product)) {
         os << endl;
      }

      return os;
   }

   // helper function: returns either Product or TaxableProduct, handles the exception
   //----------------------------------------------------------------------------------------------
   iProduct* readProduct(std::ifstream& is) {
      // declare local variables
      int t_prodNum;
      double t_prodPrice;
      char t_tax;
      iProduct* product = nullptr;

      // read prodNum and prodPrice
      is >> t_prodNum >> t_prodPrice;

      // check for new line or EOF
      if (is.get() != '\n' && !(is.eof())) {

         // read tax
         is.get(t_tax);

         if (t_tax == 'H' || t_tax == 'P') {
            // create new TaxableProduct
            product = new TaxableProduct(t_prodNum, t_prodPrice, t_tax);
         }
         else
         {
            throw "Unrecognizable Tax Code!";
         }
      }
      else if (!is.eof()) {
         // create new Product
         product = new Product(t_prodNum, t_prodPrice);
      }

      // return new product
      return product;
   }

   // end scope of the namespace
}
