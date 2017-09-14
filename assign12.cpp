/***********************************************************************
* Program:
*    Assignment 12, Exception Handling
*    Brother Burton, CS165
* Author:
*    Israel Carvajal
* Summary: 
*    This program is designed to illustrate the types of information that
*    we can send through the exception handling mechanism.
*
*    Estimated:  0.5 hrs   
*    Actual:     0.3 hrs
*      The hardest part was to learn how to use switch with catch and all that
************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/***********************************************************
 * READ DATA: Read the data from a file
 *   INPUT:  fileName. the file to be read
 *   OUTPUT: data.  The data from the file
 * IMPORTANT: You are not allowed to change readData() in any way
 ***********************************************************/
string readData(const string & fileName) throw (string, bool, int)
{
   // missing file case
   if (fileName.size() == 0)
      throw true;             // "ERROR: No filename specified\n"

   // attempt to open the file
   ifstream fin(fileName.c_str());
   if (fin.fail())
      throw fileName;         //  "ERROR: Invalid filename \"" << s << "\"\n"

   // attempt to read the data
   string data;
   getline(fin, data);
   bool moreData = !fin.eof();
   fin.close();

   // empty file
   if (data.size() == 0)
      throw 0;                // "ERROR: The file was empty\n"

   // message too long
   if (data.size() > 140)
      throw 1;                // "ERROR: The message exceeded 140 characters\n"

   // more than one line of data
   if (moreData)
      throw 2;                // "ERROR: The message was longer than 1 line\n"

   // success
   return data;
}

/**********************************************************************
 * MAIN: This function will prompt the user for the file and display the
 *       contents on the screen.
 ***********************************************************************/
int main()
{
   // get the filename
   string fileName;
   cout << "What is the filename? ";
   getline(cin, fileName);

   try
   {
      // read the data
      string data = readData(fileName);   
      // display the results: 
      cout << "The important fact: \""
           << data
           << "\"\n";
   }
   catch (bool x)
   {
      cout << "ERROR: No filename specified\n";
   }
   catch (string fileName)
   {
      cout << "ERROR: Invalid filename \"" << fileName << "\"\n";
   }
   catch (int integer)
   {
      switch (integer)
      {
         case 0:
            cout << "ERROR: The file was empty\n";
            break;
         case 1:
            cout << "ERROR: The message exceeded 140 characters\n";
            break;
         default:
            cout << "ERROR: The message was longer than 1 line\n";
      }
   }
   return 0;
}
