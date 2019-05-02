#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H                                                              

#include <iostream>
#include <fstream>
#include <utility>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>

namespace w7 {

   // define class template - DataTable
   template <class T>

   class DataTable {
   private:
      std::vector <T> m_vectX;
      std::vector <T> m_vectY;

      // field width and number od decimals
      int m_FW;
      int m_ND;

   public:
      // constructor with three arguments
      //********************************************************************************
      DataTable(std::ifstream& is, const int& FW, const int& ND) {
         
         // loop through the file
         while (is.good()) {

            // declare local variables
            std::string line;
            std::stringstream ss;
            T temp_X, temp_Y;

            // get line from the file
            std::getline(is, line);

            // check if line is not empty
            if (!line.empty()) {
               // search for '\r' and remove it
               auto cr = line.find('\r');
               if (cr != std::string::npos)
                  line.erase(cr);

               // make line a stream
               ss.str(line);

               // read X and Y from the line
               ss >> temp_X >> temp_Y;

               // insert X and Y values inside the vectors
               m_vectX.push_back(temp_X);
               m_vectY.push_back(temp_Y);
            }
         }
         // set values for field width and decimal numbers
         m_FW = FW;
         m_ND = ND;
      };


      // calculates and returns the mean
      //********************************************************************************
      T mean() const {

         // temporarily variables to return the mean
         T mean;
         
         // calculate mean
         mean = std::accumulate(m_vectY.begin(), m_vectY.end(), 0.0) / getSize();

         return mean;
      };


      // calculates and returns sigma    CALCULATION -#1
      //********************************************************************************
      T sigma() const {

         // temp variable to keep sigma value
         T sigma;

         // does it destroy the idea of Template ?
         double sum = 0.0;

         // loop the vector and calculate the SUM of (Y-mean)*(Y-mean)
         std::for_each(m_vectY.begin(), m_vectY.end(), [&](T m_vectY) { sum += pow(m_vectY - mean(), 2); });

         // finish the calculation for the sigma(standard deviation)
         sigma = sqrt(sum / (getSize() - 1));

         return sigma;
      };


      // calculates and returns median
      //********************************************************************************
      T median() const {

         // copy Y values inside of the local sort_Y vector
         vector<T> sort_Y = m_vectY;

         // local variable for calculating the median
         T median;

         // by using numeric/algorithms sort_Y vector
         std::sort(sort_Y.begin(), sort_Y.end());

         // calculate median as required for this workshop
         median = sort_Y.at(sort_Y.size() / 2);
  
/*       
         // standard median calculation, which I didn't use because of the workshop requirements
         if (sort_Y.size() % 2 == 0)
            median = (sort_Y.at(getSize() / 2-1) + sort_Y.at(getSize() / 2 )) / 2;
         else
            median = sort_Y.at(sort_Y.size() / (2));
*/     
         return median;
      };


      // sets slope and intercept
      //********************************************************************************
      void regression(T& slope, T& y_intercept) const {

         // local variables for calculating the slope and y_iteration
         vector <T> vect_denomin1(getSize());
         T XY, sumX, sumY, sumXX;
         T numerator1, numerator2;
         T denominator1, denominator2;

         // slope and y_intercept calculation
         // for formula refer to the workshop instructions

         // step #1: local variable to hold size
         size_t N = getSize();

         // step #2: calculate SUM of the X*Y vectors
         XY = std::inner_product(m_vectX.begin(), m_vectX.end(), m_vectY.begin(), (T) 0.0);

         // step #3: calculate SUM of the X vector
         sumX = std::accumulate(m_vectX.begin(), m_vectX.end(), 0.0);

         // step #4: calculate SUM of the Y vector
         sumY = std::accumulate(m_vectY.begin(), m_vectY.end(), 0.0);

         // step #5: store X*X in a local vector and calculate SUM of that vector
         std::transform(m_vectX.begin(), m_vectX.end(), vect_denomin1.begin(),
            [&](T m_vectX) {return (m_vectX * m_vectX); });

         sumXX = std::accumulate(vect_denomin1.begin(), vect_denomin1.end(), 0.0);

         // step #6: calculate nominators and denominators
         numerator1 = N * XY;
         numerator2 = sumX * sumY;
         denominator1 = N * sumXX;
         denominator2 = pow(sumX, 2);

         // step #7: calculate slope
         slope = (numerator1 - numerator2) / (denominator1 - denominator2);

         // step #8: calculate y_intercept
         y_intercept = (sumY - slope * sumX) / N;
      };


      // displays data pairs
      //********************************************************************************
      void display(std::ostream& os) const {

         os << "       x       y" << std::endl;

         // display elements of the X and Y vectors
         for (auto i = 0u; i < getSize(); i++) {
            os << setw(m_FW) << fixed << setprecision(m_ND) << m_vectX[i];
            os << setw(m_FW) << fixed << setprecision(m_ND) << m_vectY[i] << std::endl;
         }
      };


      // returns number of pairs
      //********************************************************************************
      size_t getSize() const {

         // temp variable to return vector size 
         size_t vectSize;

         // throws an exception if size of two vectors are inequal
         if (m_vectX.size() != m_vectY.size()) {
            throw "Error Message: Size of 'X' and 'Y' vectors are not equal!";
         }
         else {
            vectSize = m_vectX.size();
         }
         return vectSize;
      };
      // end scope of the DataTable class
   };

   // helper function
   template <class T>
   std::ostream& operator<< (std::ostream& os, const DataTable<T>& DT) {
      
      // display DT object
      DT.display(os);
      
      return os;
   }
   // end scope of the namespace
}

#endif 
