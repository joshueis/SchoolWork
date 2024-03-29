/***********************************************************************
* Program:
*    Assignment 41, Callback functions and void data types
*    Brother Burton, CS165
* Author:
*    Israel Carvajal
* Summary: 
*    This program is designed to demonstrate how callback functions
*    work so, coupled with void data types, a given function can be
*    agnostic of the passed data type.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/

#include <iostream>                         // need this for CIN and COUT
#include <string.h>                         // need this for strcmp()
using namespace std;

template <class T>
void sort(void *data[],                     // data to be sorted
          int num,                     // number of items in the list
          int (*compare)(void *, void *),   // compare first with second
          void (*swap)(void *, void *))    // swap first with second
{
   for (int i = 0; i < num; i++)
   {
      for (int j = (num - 1); j > (i + 1); j--)
      {
         if(compare(data[j] < 0 && data[j - 1] < 0)
            {
               swap
}
int  compareInt(int  *p1,  int  *p2);
void swapInt(   int  *p1,  int  *p2);
void swapWords( char *s1,  char *s2);
// using strcmp() for the compareWords() function

/**********************************************************************
 * MAIN.  Driver program to test our callback functions
 *        You are not allowed to modify MAIN in any way.
 ***********************************************************************/
int main()
{
   int numbers[5];
   char words[7][256];

   //
   //  First fill the arrays of words and numbers
   //
   
   // fill the numbers
   int *pNumbers[5]; // each slot needs to be a pointer to the data
   cout << "Specify 5 numbers: ";
   for (int i = 0; i < 5; i++)
   {
      cin >> numbers[i];
      pNumbers[i] = &(numbers[i]);  // set up the pointers
   }

   // fill the text
   char *pWords[7];
   cout << "Specify 7 words of text: ";
   for (int i = 0; i < 7; i++)
   {
      cin >> words[i];
      pWords[i] = words[i]; // set up the pointers
   }

   //
   // Next, sort them.  Note how we use exactly the same sorting routine.
   // sort() has no idea what data type it is using.
   //
   
   // sort numbers
   sort((void **)pNumbers, 5,
        (int  (*)(void *, void *))compareInt,
        (void (*)(void *, void *))swapInt  );

   // sort the c-strings
   sort((void **)pWords,   7,
        (int  (*)(void *, void *))strcmp,
        (void (*)(void *, void *))swapWords);

   //
   // Finally, display the results.
   //
   
   // display the numbers
   cout << "Sorted numbers: ";
   for (int i = 0; i < 4; i++)
      cout << numbers[i] << ", ";
   cout << numbers[4] << endl;

   // display the text
   cout << "Sorted words: ";
   for (int i = 0; i < 6; i++)
      cout << words[i] << ", ";
   cout << words[6] << endl;
   
   return 0;
}

/******************************************
 * COMPARE INT: determine if x1 > x2
 *  INPUT   x1, x2:    Two numbers to compare
 *  OUTPUT  return  1:  x1 >  x2
 *          return  0:  x1 == x2
 *          return -1:  x1 <  x2
 *****************************************/
int compareInt(int *p1, int *p2)
{
   if (*p1 == *p2)
      return 0;
   return (*p1 > *p2) ? 1 : -1;
}

/******************************************
 * SWAP INT.  Swap these two integers
 *  INPUT   x1, x2:   Two integers to be swapped
 *  OUTPUT  x2, x1
 ******************************************/
void swapInt(int *p1, int *p2)
{
   // hehehe.  This is a trip.  how does this work?
   *p1 ^= *p2;
   *p2 ^= *p1;
   *p1 ^= *p2;
}

/****************************************
 * SWAP WORDS.  Swap two strings
 *  INPUT   s1, s2:   Two words to be swapped
 *  OUTPUT  s2, s1
 ******************************************/
void swapWords(char *s1, char *s2)
{
   char temp[256];
   strcpy(temp, s1);
   strcpy(s1, s2);
   strcpy(s2, temp);
}
