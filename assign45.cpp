/***********************************************************************
* Program:
*    Assignment 45, Iterators
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
using namespace std;

/**********************************************************************
 * Instructions: Please fill in the code below the comments to demonstrate
 * three ways to walk through a string object
 ***********************************************************************/
int main()
{
   // fetch the text
   string text;
   cout << "What is the text: ";
   getline(cin, text);

   // display the text using the array notation
   cout << "Array:    ";
   // <your code goes here>

   
   for (int i = 0; text[i]; i++)
   {
      cout << text[i];
   }
   cout << endl;
   
   // display the text using the pointer notation
   cout << "Pointers: ";
   // <your code goes here>
   
   for (const char * p = text.c_str(); *p; p++)
   {
      cout << *p;
   }
   cout << endl;

   // display the text using the iterator notation
   cout << "Iterator: ";
   // <your code goes here>
   for (string::iterator it = text.begin(); it != text.end(); ++it)
   {
      cout << *it;
   }
   cout << endl;
   return 0;
}
