#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void readMove(string move[], int & size, string fileName);
void display(string move[], int size);
void writeMove(string move[], int & size, string fileName);
void getFileIn(string & fileName);
void getFileOut(string & fileName);
int main()
{
   int size = 0;
   string move[100];

   string fileName; // = "/home/cs165sb/examples/words.txt";
   getFileIn(fileName);
   readMove(move, size, fileName);
   display(move, size);
   string outFile; //"tempOut.txt";
   getFileOut(outFile);
   writeMove(move, size, outFile);
}
void getFileIn(string & fileName)
{
   cout << "Enter filename to read from: \n";
   cin >> fileName;
}
void getFileOut(string & fileName)
{
   cout << "Enter filename to write: \n";
   cin >> fileName;
}
void writeMove(string move[], int & size, string fileName)
{
   ofstream outFile(fileName.c_str());
   if (outFile.fail())
      cout << "ERROR";
   int i = 0;
   for (int i = 0; i < size; i++)
   {
      outFile << move[i] << endl;
   }

   outFile.close();
}
void display(string move[], int size)
{
   for(int i = 0; i < size; i++)
   {
      cout << move[i] << endl;
   }
}

