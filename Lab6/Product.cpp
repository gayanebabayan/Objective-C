#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

#include "Product.h"
#include "iProduct.h"
#include "ProdUtil.h"

using namespace std;

namespace w6 {
   // default constructor of the Product class
   //----------------------------------------------------------------------------------------------
   Product::Product() {
      m_prodNo = 0;
      m_prodPrice = 0.0;
   };

   // argument constructor of the Product class
   //----------------------------------------------------------------------------------------------
   Product::Product(int prodNum, double prodPrice) {
      m_prodNo = prodNum;
      m_prodPrice = prodPrice;
   }

   // returns the Product price
   //----------------------------------------------------------------------------------------------
   double Product::getPrice() const {
      return m_prodPrice;
   }

   // displays the Product info in the form of a single line
   //----------------------------------------------------------------------------------------------
   void Product::display(std::ostream& os) const {
      // display the Product
      os << "           " << setfill('0') << setw(5) << right << m_prodNo
         << setfill(' ') << setw(16) << right << m_prodPrice;

   }

   // end scope of the namespace
}
