// Workshop: Lab-6
// File: TaxableProduct.h
// Date: 30-Oct-2018
// Name: Gayane Babayan
// ID:   107-061-160

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

#include "Product.h"
#include "iProduct.h"
#include "TaxableProduct.h"

using namespace std;


namespace w6 {

   // default constructor of the TaxableProduct class
   //----------------------------------------------------------------------------------------------
   TaxableProduct::TaxableProduct() :Product() {
      m_taxed = '\0';
   };

   // argument constructor of the TaxableProduct class
   //----------------------------------------------------------------------------------------------
   TaxableProduct::TaxableProduct(int prodNum, double prodPrice, char Tax)
      :Product(prodNum, prodPrice) {
      m_taxed = Tax;
   }

   // returns the chargeable price of the product
   double TaxableProduct::getPrice() const {

      // declare local variable
      double rate;

      // check the tax type and set the rate
      if (m_taxed == 'H' || m_taxed == 'P') {
         if (m_taxed == 'H')
            rate = 1.13;
         else
            rate = 1.08;
      }
      // not taxable
      else {
         rate = 1;
      }

      return Product::getPrice() * rate;
   }

   // displays the TaxableProduct info in the form of a single line
   //----------------------------------------------------------------------------------------------
   void TaxableProduct::display(std::ostream& os) const {

      // displays m_prodNum and m_prodPrice from Product
      Product::display(os);

      // checks for the tax type
      if (m_taxed == 'H') {
         os << " HST";
      }
      else if (m_taxed == 'P') {
         os << " PST";
      }
      os << endl;
   }

   // end scope of the namespace
}