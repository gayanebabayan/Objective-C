#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {
   // CONVERT helper function
   //***************************************************************************
   void converter(char* t, char key, int n, const Cryptor& c) {
      for (int i = 0; i < n; i++)
         t[i] = c(t[i], key);
   }

   // CUSTOM CONSTRUCTOR
   //***************************************************************************
   SecureData::SecureData(const char* file, char key, ostream* pOfs)
   {
      ofs = pOfs;

      // open text file
      fstream input(file, std::ios::in);
      if (!input)
         throw string("\n***Failed to open file ") +
         string(file) + string(" ***\n");

      // copy from file into memory
      input.seekg(0, std::ios::end);
      nbytes = (int)input.tellg() + 1;

      text = new char[nbytes];

      input.seekg(ios::beg);
      int i = 0;
      input >> noskipws;
      while (input.good())
         input >> text[i++];
      text[nbytes - 1] = '\0';
      *ofs << "\n" << nbytes - 1 << " bytes copied from file "
         << file << " into memory (null byte added)\n";
      encoded = false;

      // encode using key
      code(key);
      *ofs << "Data encrypted in memory\n";
   }

   // DESTRUCTOR
   //***************************************************************************
   SecureData::~SecureData() {
      delete[] text;
   }

   // DISPLAY function
   //***************************************************************************
   void SecureData::display(std::ostream& os) const {
      if (text && !encoded)
         os << text << std::endl;
      else if (encoded)
         throw std::string("\n***Data is encoded***\n");
      else
         throw std::string("\n***No data stored***\n");
   }

   // CODE function    >>> TODO:
   //***************************************************************************
   void SecureData::code(char key)
   {
      // TODO: rewrite this function to use at least two threads
      //         to encrypt/decrypt the text.
      converter(text, key, nbytes, Cryptor());

      std::thread t1(converter, text, key, nbytes, Cryptor());

      t1.join();

      encoded = !encoded;
   }

   // BACKUP function      >>> TODO:
   //***************************************************************************
   void SecureData::backup(const char* file) {
      if (!text)
         throw std::string("\n***No data stored***\n");
      else if (!encoded)
         throw std::string("\n***Data is not encoded***\n");
      else
      {
         // TODO: open a binary file for writing
         std::fstream os(file, std::ios::out);
         if (!os)
            throw "Failed to open file " + std::string(file);

         // TODO: write data into the binary file
         //         and close the file
         for (int i = 0; i < nbytes; ++i)
            os << text[i];
         
         // fstream closes file itself when it exits its scope
      }
   }

   // RESTORE function     >>>>TODO:
   //***************************************************************************
   void SecureData::restore(const char* file, char key) {
            
      // TODO: open binary file for reading
      
      // deallocate the existing data
      delete text;
      nbytes = 0;
      
      std::fstream ifs(file, std::ios::in);
      if (!ifs)
         throw "Failed to open file " + std::string(file);

      // determines the number of bytes to be read
      // do not skip whitespaces
      ifs >> std::noskipws;
      char temp;
      while (ifs.good()) {
         ifs >> temp;
         nbytes++;
      }

      // TODO: - allocate memory here for the file content
      
      // allocate memory here
      text = new char[nbytes + 1];


      // TODO: - read the content of the binary file

      // read binary file here
      ifs.clear();
      ifs.seekg(0, std::ios::beg);

      for (int i = 0; i < nbytes; i++) {
         ifs >> text[i];
      }
      
      nbytes--;

      *ofs << "\n" << nbytes << " bytes copied from binary file "
         << file << " into memory.\n";

      encoded = true;

      // decode using key
      code(key);

      *ofs << "Data decrypted in memory\n\n";
   }

   // OPERATOR OVERLOAD helper function
   //***************************************************************************
   std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
      sd.display(os);
      return os;
   }
}
