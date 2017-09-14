/***********************************************************************
* Program:
*    Assignment 26, 
*    Brother Neff, CS124
* Author:
*    Israel Carvajal
* Summary:
*    This program will read 10 grades from a file and display the average
*
*    Estimated:  1. hrs
*    Actual:    8pm . hrs
*     
*   It was hard to figure out how to stablish the condition of reading exactly
*   ten grades
************************************************************************/
#include<iostream>
#include<fstream>
using namespace std;
/***************************************************
 * 
 *************************************************/
void getFileName(char fileName[256])
{
   cout << "Please enter the filename: "; cin >> fileName;
}
/**************************************************
 *
 *************************************************/
float readFile(char fileName[256])
{
   //open the file
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Error reading file " << "\"" << fileName << "\"" << endl; 
      return -1;
   }  
   int sum = 0;
   int count = 0;
   float average;
   int x;
 
   while(fin >> x)
   {
      count ++;
      sum += x;
   }
   average = (sum / 10.0) + 0.5;
   if (count != 10)
   {
      cout << "Error reading file " << "\"" << fileName << "\"" << endl;
      return -1;
   }
   else
   return average;
}
/***************************************************
 * Just prototype
 *************************************************/
void display(float average);
/***************************************************
 * main
 *   
 *************************************************/
int main()
{
   char fileName[256];
   getFileName(fileName);
   float average = readFile(fileName);
   if (average >= 0)
   { 
      display(average);
   }
      return 0;
}
/***************************************************
 *
 *************************************************/
void display(float average)
{
   cout << "Average Grade: " << (int)average << "%" << endl;
}
