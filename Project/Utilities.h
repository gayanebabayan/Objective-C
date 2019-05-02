// Final Project:       MS-1
// File:                Utilities.h
// Name:                Gayane Babayan
// Seneca Student ID:   107-061-160
// Seneca email:        gbabayan@myseneca.ca
// Date of completion:  08-Nov-2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

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
