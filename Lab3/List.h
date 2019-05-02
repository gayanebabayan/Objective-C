#ifndef SICT_LIST_H
#define SICT_LIST_H

   template <typename T, int N>
   class List {
   private:
      T m_Array[N];
      size_t m_count;
   public:
      // default constructor
      List() {
         m_count = 0;
      }   

      // returns number of entires in the array
      size_t size() const {
         return m_count;
      }

      // overloaded operator, returns the requested array index
      const T& operator [] (int index) const {
            return m_Array[index];
      }

      // overloaded operator that adds an element to the array if space is available
      void operator +=(const T& src) {
         if (size() < N) {
            m_Array[size()] = src;
            m_count++;
         }
      }
   };
#endif 
