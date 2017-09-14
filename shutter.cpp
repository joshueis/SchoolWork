#include <iostream>
#include <string>
#include <math.h> // for PI M_PI
using namespace std;
#define PI 3.14159265359
class Shutter
{
public:
   string color;
   string room;
   virtual float getArea() const  = 0;
      
};

class SquareShutter : public Shutter
{
public:
   float width;
   float height;
   virtual float getArea() const
   {
      return (width * height);
   }
   
};

class Sunburst
{
public:
   float radius;
   virtual float getArea() const
   {
      return (0.5 * PI * radius * radius);
   }
};

void displayArea(Shutter *x)
{
   cout << "For shutter in room: "
        << x->room << " the area is: " << x->getArea();
}
int main()
{
   SquareShutter sq;
   sq.room = "Kitchen";
   sq.color = "white";
   sq.width = 60;
   sq.height = 40;
   displayArea(&sq);
   return 0;
}
