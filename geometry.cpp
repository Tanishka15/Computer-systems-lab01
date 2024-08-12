/* 
#include <iostream>
#include "geometry.h"

using namespace std;

Point create_point(double x, double y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

void print(Point p) {
    cout << "(" << p.x << ", " << p.y << ")" << endl;
}

double sqroot(double x) {
    if (x < 0) 
        return -1; 
    if (x == 0) 
        return 0;

    double stop = 1e-10; // Precision of the result
    double guess = x; // Initial guess
    while (abs_custom(guess * guess - x) > stop) {
        guess = (guess + x / guess) / 2.0;
    }
    return guess;
}

double abs_custom(double x) {
   if (x < 0) {
       return -x;
   } else {
       return x;
   }
}

double distance(Point a, Point b) {
    return sqroot((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double cross_product(Point a, Point b, Point c) {
    return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}

int orientation(Point a, Point b, Point c) {
    double val = cross_product(a, b, c);
    if (val == 0)
        return 0;
    else if (val > 0) {
        return 1;
    } else {
        return 2;
    }
}

void convex_hull(Point points[], int n, Point hull[], int* m) {
    if (n < 3) {
        *m = 0;
        return;
    }
    int l = 0; // the leftmost point
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[l].x) {
            l = i;
        }
    }
    int p = l, q;
    *m = 0;
    do {
        hull[(*m)++] = points[p];
        q = (p + 1) % n; // the next point in the array
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2) {
                q = i;
            }
        }
        p = q;
    } while (p != l);
   
    for (int i = 0; i < *m; i++) {
        print(hull[i]);
    }
}
 */
#include "geometry.hpp"
#include <iostream>

using namespace std;

Point create_point(double x, double y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

void print(Point p) {
    cout << "(" << p.x << ", " << p.y << ")" << endl;
}

double sqroot(double x) {
    if (x < 0) 
        return -1; 
    if (x == 0) 
        return 0;

    double stop = 1e-10; // Precision of the result
    double guess = x; // Initial guess
    while (abs_custom(guess * guess - x) > stop) {
        guess = (guess + x / guess) / 2.0;
    }
    return guess;
}

double abs_custom(double x) {
   if (x < 0) {
       return -x;
   } else {
       return x;
   }
}

double distance(Point a, Point b) {
    return sqroot((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double cross_product(Point a, Point b, Point c) {
    return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}

int orientation(Point a, Point b, Point c) {
    double val = cross_product(a, b, c);
    if (val == 0.0)
        return 0; // collinear
    return (val > 0.0) ? 1 : 2; // 1 = clockwise, 2 = counterclockwise
}



void convex_hull(Point points[], int n, Point hull[], int* m) {
    if (n < 3) {
        *m = 0;
        return;
    }

    int l = 0; // the leftmost point
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[l].x) {
            l = i;
        }
    }

    int p = l, q;
    *m = 0;

    do {
        hull[(*m)++] = points[p];
        q = (p + 1) % n; // the next point in the array

        for (int i = 0; i < n; i++) {
            int o = orientation(points[p], points[i], points[q]);
            if (o == 2 || (o == 0 && distance(points[p], points[i]) > distance(points[p], points[q]))) {
                q = i;
            }
        }

        p = q;

    } while (p != l);
    /* std::cout << "Current point: ";
print(points[p]);
std::cout << "Next point: ";
print(points[q]);
std::cout << "Orientation: " << orientation(points[p], points[q], points[l]) << std::endl;

 */
    std::cout << "Convex Hull Points:" << std::endl;
    for (int i = 0; i < *m; i++) {
        print(hull[i]);
    }
}
