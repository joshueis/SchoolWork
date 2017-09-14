/***********************************************************************
* Program:
*    Assignment 46, Reverse file
*    Brother Burton, CS165
* Author:
*    Israel Carvajal
* Summary: 
*    This program is designed to demonstrate using iterators to walk
*    through a container or collection of elements.
*
*    Estimated:  0.5 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


void readFile(string file, vector<string> & temp)
{
   
   ifstream inFile(file.c_str());
   if (inFile.fail())
      cout << "error";
   string str;
   
   while(getline(inFile, str))
   {
      temp.push_back(str);
   }
   inFile.close();
}
/**********************************************************************
 * Instructions: Please fill in the code below the comments to demonstrate
 * three ways to walk through a string object
 ***********************************************************************/
int main()
{
   // fetch the text
   vector<string> text;
   string file;
   cout << "Enter the name of the file: ";
   getline(cin, file);

   readFile(file, text);
   for (vector<string>::reverse_iterator rit = text.rbegin();
        rit != text.rend(); rit++)
   {
      cout << *rit;
      cout << endl;
      
   }
   return 0;
}
