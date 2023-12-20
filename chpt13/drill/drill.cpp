#include "include/Simple_window.h"
#include "include/Graph.h"

constexpr int window_width = 800;
constexpr int window_height = 1000;

int main( )
{
    Simple_window win = {Graph_lib::Point{100,200},window_width,window_height,"Window for Chapter Drill"};

    int x_size = win.x_max();   // get horizontal window size
    int y_size = win.y_max();   // get vertical window size
    int x_grid = 100;           // set grid box width
    int y_grid = 100;           // set grid box height

    Graph_lib::Lines grid;      // create Lines Shape called grid

    // generate a "_|" looking pair of lines to form graph
    for (int x = x_grid; x < x_size; x += x_grid) {
        grid.add(Graph_lib::Point{x,0},Graph_lib::Point{x,y_size}); // add a vertical line
    }
    for (int y = y_grid; y < y_size; y += y_grid) {
        grid.add(Graph_lib::Point{0,y},Graph_lib::Point{x_size,y}); // add a horizontal line
    }

    win.attach(grid);

    Graph_lib::Vector_ref<Graph_lib::Rectangle> rect;
    Graph_lib::Vector_ref<Graph_lib::Image> images;
    for (int i = 0; i < x_size/x_grid && i < y_size/y_grid; i++) {
        // we attach the image first so the rectangle can be drawn on top of the image
        images.push_back(new Graph_lib::Image{Point{i*x_grid,i*y_grid},"image/snip.jpg"});
        images[i].set_mask(Point{0,0},x_grid,y_grid);   // Point is relative to the image file itself, not the window
        win.attach(images[i]);

        rect.push_back(new Graph_lib::Rectangle{Point{i*x_grid,i*y_grid},x_grid,y_grid});
        rect[i].set_color(Color::red);
        win.attach(rect[i]);
    }

    // i,j defines which box we want to occupy for the image
    for (int i = 0; i < x_size/x_grid; i++) {
        // iterate vertically first, then horizontally
        for (int j = 0; j < y_size/y_grid; j++) {
            Graph_lib:Image moving_img = Graph_lib::Image{Point{i*x_grid,j*y_grid},"image/snip.jpg"};
            moving_img.set_mask(Point{0,0},x_grid,y_grid);
            win.attach(moving_img);

            // wait for button before moving on and updating moving_img location
            win.wait_for_button();
        }
    }
}