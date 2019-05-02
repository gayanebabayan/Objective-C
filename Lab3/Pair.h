#ifndef SICT_PAIR_H
#define SICT_PAIR_H

template <typename A, typename B>
class Pair {
private:
   A m_key1;
   B m_key2;
public:
   // default construction - adopts a safe empty state
   Pair() {}

   // overloaded constructor that sets the key-value pair elements of the class
   Pair(const A& value1, const B& value2) {
      m_key1 = value1;
      m_key2 = value2;
   }

   // returns a read-only version of the stored key information
   const A& getKey() const {
      return m_key1;
   }

   // returns a read-only version of the stored value information
   const B& getValue() const {
      return m_key2;
   }
};
#endif 
