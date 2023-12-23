#include "include/Simple_window.h"
#include "include/Graph.h"
#include "arc.h"

constexpr int window_width = 800;
constexpr int window_height = 1000;

int main()
{
    Simple_window win = {Graph_lib::Point{0,0},window_width,window_height,"Window for Exercise 1"};
    Graph_lib::Arc a = Graph_lib::Arc(Point{100,100},50,50,0,360);

    win.attach(a);

    win.wait_for_button();
}