#ifndef MS1_UTILITIES_H
#define MS1_UTILITIES_H

   // define the utilities class
   class Utilities {
   private:
      size_t m_widthField;
      static char m_delimiter;
   public:
      Utilities();
      void setFieldWidth(size_t pSize);
      size_t getFieldWidth() const;
      const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
      static void setDelimiter(const char pDelim);
      const char getDelimiter() const;
   };

#endif // !MS1_UTILITIES_H
