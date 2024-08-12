#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct {
    double x, y;
} Point;
double create_point(double x, double y);
int orientation(Point p, Point q, Point r);
void print(Point p);
double cross_product(Point p1, Point p2, Point p3);
double distance(Point p1, Point p2);
double sqroot(double num);
double abs_custom(double num);
void convex_hull(Point points[], int n, Point hull[], int *hull_size);

#endif // GEOMETRY_H
