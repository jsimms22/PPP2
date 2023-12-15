#include "include/Simple_window.h"
#include "include/Graph.h"

int main()
{
    using namespace Graph_lib;
    Point tl {100,100};

    Simple_window win {tl,600,400,"canvas"};

    Axis xa {Axis::x,Point{20,300},280,10,"x axis"};  // make an axis
        // an axis is a kind of shape
        // Axis::x means horizontal
        // starting at (20,300)
        // 280 pixels long
        // 10 "notches"
        // label the acix "x axis"

    win.attach(xa);
    win.set_label("canvas #2");

    Axis ya {Axis::y,Point{20,300},280,10,"y axis"};
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);    // choose a color for the text
    
    win.attach(ya);
    win.set_label("canvas #3");

    Function sine {sin,0,100,Point {20,150},1000,50,50};    // sine curve
        // plot sin() in the range of [0:100) with (0,0) at (20,150)
        // using 1000 points; scale x values *50, scale y values *50
        // this will extend beyond our initial window so the GUI will ignore points beyond the edge

    win.attach(sine);
    win.set_label("canvas #4");

    sine.set_color(Color::blue);

    Graph_lib::Polygon poly;
    poly.add(Point{300,200});
    poly.add(Point{350,100});
    poly.add(Point{400,200});

    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);

    win.attach(poly);
    win.set_label("canvas #5");

    Graph_lib::Rectangle r {Point{200,200},100,50}; // top left corner, width, height

    win.attach(r);
    win.set_label("canvas #6");

    r.set_fill_color(Color::yellow);    // color in the rectangle
    poly.set_style(Line_style(Line_style::dash,4));
    //poly_rect.set_style(Line_style(Line_style::dash,2));

    win.set_label("canvas #7");

    Graph_lib::Text t {Point{150,150},"Hello, graphical world!"};

    win.attach(t);
    win.set_label("canvas #8");

    t.set_font(Font::times_bold);
    t.set_font_size(20);
    
    win.set_label("canvas #9");

    Graph_lib::Image img1 {Point{100,50},"images/geeq 400x400.jpg"};

    win.attach(img1);

    win.set_label("canvas #10");

    img1.move(100,200);

    win.set_label("canvas #11");
    win.wait_for_button();
}