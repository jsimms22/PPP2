#include "arc.h"

namespace Graph_lib {

void Arc::draw_arc() const
{
    if (color().visibility()) {
        fl_arc(point(0).x,point(0).y,r,a1,a2);
    }
}

} // Graph_lib