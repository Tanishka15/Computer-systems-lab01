#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct {
    double x;
    double y;
} Point;

Point create_point(double x, double y);
void print(Point p);
double sqroot(double x);
double abs_custom(double x);
double distance(Point a, Point b);
double cross_product(Point a, Point b, Point c);
int orientation(Point a, Point b, Point c);
void convex_hull(Point points[], int n, Point hull[], int* m);

#endif
