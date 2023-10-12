#include<iostream>
#include<vector>
#include<cmath>

int f(int x) 
{
    return x += 1;
}

//------------------------------------------------------------------

void print(const std::vector<double>& v)
/*
    simple vector print
*/
{
    std::cout << "{";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if(i != v.size()-1) std::cout << ", ";
        //v[i] += 1;  // error
    }
    std::cout << " }\n";
}

//------------------------------------------------------------------

void fill_vector(std::vector<double>& v)
/*
    simply vector initialization fn
*/
{
    for (int i = 0; i < v.size(); i++) {
        v[i] = i;
    }
}

//------------------------------------------------------------------

// constexpr function example
struct Point 
{
    double x;
    double y;
};

constexpr double xscale = 10;
constexpr double yscale = 0.8;

constexpr Point scale(Point p) { return {xscale*p.x, yscale*p.y }; };

void user(Point p1) // assume input is p1 == {10,10}
/*
    simply example to highligh constexpr functions
*/
{
    constexpr Point p2 {10,10};

    Point p3 = scale(p1);           // Ok: p3 == {100,8}; run-time eval is fine
    constexpr Point p4 = scale(p2); // p4 == {100,8}

    //constexpr Point p5 = scale(p1); // error: scale(p1) is not a constant expression

    constexpr Point p6 = scale(p2);  // 6 == {100,8}
}

//------------------------------------------------------------------

int main()
/*
    notes covering part of chapter 8
*/
{   
    // pass-by-value
    int xx = 0;
    std::cout << f(xx) << '\n'; // print 1
    std::cout << xx << '\n';    // f(xx) does not change xx, print 0

    int yy = 7;
    std::cout << f(yy) << '\n'; // print 8
    std::cout << yy << '\n';    // print 7

    std::vector<double> vd1(10);
    std::vector<double> vd2(1000);
    std::vector<double> vd3(xx);
    
    // pass-by-reference
    fill_vector(vd1);
    fill_vector(vd2);
    fill_vector(vd3);

    // pass-by-const-reference
    print(vd1);
    print(vd2);
    print(vd3);

    // additional pass-by-reference example
    // any use of r is really a use of i
    int i = 7;

    int& r = i; // r is a reference to i
    r = 9;      // i becomes 9
    i = 10;

    std::cout << r << " " << i << '\n'; // prints 10 10

    // another pass-by-reference example [does not work]
    // std::vector<std::vector<double>> v;
    // double& val = v[f(xx)][f(yy)];
    // val = val / (2 * sqrt(val)); // read + write through val

    // another pass-by-reference example
    std::cout << "xx = " << xx << "\ty = " << yy << '\n';
    std::swap(xx,yy);   // swap<Type T>(T& x, T& y)
    std::cout << "xx = " << xx << "\ty = " << yy << '\n';

    


    return 0;
}