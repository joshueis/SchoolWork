#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class Pair
{
private:
   T1 left;
   T2 right;

public:
   T1 getLeft() const { return left; }
   T2 getRight() const { return right; }

   void setLeft(const T1 & left) { this->left = left; }
   void setRight(const T2 & value) { right = value; }

   void displayMultipleLefts(int numTimes)
   {
      for (int i = 0; i < numTimes; i++)
      {
         cout << left << endl;
      }
   }

   void display() const;
};

template <class T1, class T2>
void Pair<T1, T2> :: display() const
{
   cout << "(" << left << ", " << right << ")\n";
}

int main()
{
   Pair<int, int> numbers;
   Pair<string, int> words;
   
   numbers.setLeft(3);
   numbers.setRight(4);
   numbers.display();

   words.setLeft("cat");
   //words.setRight("hat");
   words.setRight(4);
   words.display();

   return 0;
}
