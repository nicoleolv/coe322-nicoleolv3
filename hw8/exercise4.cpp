// Nicole Olvera
// username: nicoleolv
// uteid: no4342

#include <iostream>
using std::cin;
using std::cout;

#include <cmath>  // allows me to use the square root function
using std::sqrt;

#include <fmt/format.h>  // allows access to the fmtlibrary 
using fmt::format,fmt::print;

#include <memory>  // allows me to use smart pointers 
using std::make_shared,std::shared_ptr;  

class Point {  // defines a class named Point
protected:
  float x,y;  // that takes two input, an x and a y
public:
  Point(float ux,float uy) { x = ux; y = uy; };
  float dx( Point other ) {  // it has a method that calcukates dx, the difference between two x-values
    return other.x - x; };
  float dy( Point other ) {  // calculates dy, the difference between two y-values
    return other.y - y; };
  float distance(Point other) {  // method 'distance' calculates the distance between one point to another point in the x and y direction (making them the width and the height of the rectangle)
    float wd = dx(other), ht = dy(other);
    return sqrt( wd*wd + ht*ht );
  }
  void scale(float factor){  // function that takes a factor and returns nothing 
    x = factor*x;  // the scale function redefines x by multiplying by the factor
    y = factor*y;  // the sale function redefines y by multiplying by the factor
  }
};

class DynRectangle {  
private:
  shared_ptr<Point> bl=nullptr, tr=nullptr;  // defined our bottom left, bl, and top right, tr, as a shared pointer, initialized as a nullptr
public:
  DynRectangle( shared_ptr<Point> ibl, shared_ptr<Point> itr)  // the class will take two shared pointers
    : bl(ibl), tr(itr) {};
  float area(){
    return (bl->dx(*tr)) * (bl->dy(*tr));  // method 'area' calculates the area in the rectangle by multiplying dx and dy for the two points
  }
};

int main() {

    auto origin  = make_shared<Point>(0,0);  // define the points 
    auto fivetwo = make_shared<Point>(5,2);
    auto topright = make_shared<Point>(10,4);

    DynRectangle lielow( origin,fivetwo );  // made an instance of DynRectangle 'lielow' 
    DynRectangle shift( fivetwo,topright);  // made an instance of DynRectangle 'shift' 
    // record the area:
    cout << "Area of the first rectangle: " <<  lielow.area() << '\n';
    cout << "Area of the shifted rectangle: " << shift.area() << '\n';

    fivetwo = topright;  // shifted the point and now the topright is the first rectangles bottom left
    

    // now the area should be the same 
    cout << "Area of the first rectangle after shifting: " <<  lielow.area() << '\n';
    cout << "Area of the shifted rectangle after shift: " << shift.area()
	 << '\n'
  }
  return 0;
}
