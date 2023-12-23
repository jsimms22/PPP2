#ifndef ARC_GUARD
#define ARC_GUARD

#include "Point.h"
#include<vector>
//#include<string>
//#include<cmath>
#include "fltk.h"
#include "std_lib_facilities.h"
#include "Graph.h"

namespace Graph_lib {

struct Arc : Shape {
    Arc(Point xy, int width, int height, double begin_angle, double end_angle) 
        :w{ width }, h{ height }, a1{ begin_angle }, a2{ end_angle }
    {
        if (begin_angle > end_angle) { error("Bad arc: beginning angle must be smaller or equal to end angle"); }
        add(Point{xy.x,xy.y}); 
    }

    void draw_lines() const;
    //double radius() const { return r; }
    double begin_angle() const { return a1; }
    double end_angle() const { return a2; }

private:
    int w;      // bounding box of complete circle
    int h;      
    double a1;  // begin angle of the arc
    double a2;  // end angle of the arc
};

} // namespace Graph_lib

#endif
