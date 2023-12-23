#ifndef ARC_GUARD
#define ARC_GUARD

#include "include/Point.h"
#include<vector>
//#include<string>
//#include<cmath>
#include "include/fltk.h"
#include "include/std_lib_facilities.h"
#include "include/Graph.h"

namespace Graph_lib {

struct Arc : Shape {
    Arc(Point xy, double radius, double begin_angle, double end_angle) 
        :r{ radius }, a1{ begin_angle }, a2{ end_angle }
    {
        if (begin_angle >= end_angle || 
            end_angle <= 0 || 
            begin_angle <= 0 ||
            end_angle > 360 ||
            begin_angle > 360) 
        {
            error("Bad arc: non-sense angles");
        }
        add(xy); 
    }

    void draw_arc() const;
    double radius() const { return r; }
    double begin_angle() const { return a1; }
    double end_angle() const { return a2; }

private:
    double r;      // radius
    double a1;  // begin angle of the arc
    double a2;  // end angle of the arc
};

} // namespace Graph_lib

#endif
