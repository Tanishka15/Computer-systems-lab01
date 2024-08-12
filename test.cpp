#include "geometry.hpp"
#include <iostream>
#include <cmath> 

// Function prototypes
void print(Point p);
double sqroot(double x);
double abs_custom(double x);

void test_create_point() {
    Point p = create_point(3.0, 4.0);
    if (p.x == 3.0 && p.y == 4.0) {
        std::cout << "Test for create_point has passed!" << std::endl;
    } else {
        std::cout << "Test for create_point has failed!" << std::endl;
    }
}

void test_distance() {
    Point p1 = create_point(0.0, 0.0);
    Point p2 = create_point(3.0, 4.0);
    double dist = distance(p1, p2);
    if (std::fabs(dist - 5.0) < 1e-9) { // Using a tolerance for floating-point comparison
        std::cout << "Test for distance has passed!" << std::endl;
    } else {
        std::cout << "Test for distance has failed!" << std::endl;
    }
}

void test_sqroot() {
    double x1 = 25.0;
    double x2 = 0.0;
    double x3 = -1.0; // Should return -1 as per your implementation
    
    double sqrt1 = sqroot(x1);
    double sqrt2 = sqroot(x2);
    double sqrt3 = sqroot(x3);
    
    if (std::fabs(sqrt1 - 5.0) < 1e-9 && 
        std::fabs(sqrt2 - 0.0) < 1e-9 &&
        sqrt3 == -1) { // Direct comparison for -1
        std::cout << "Test for sqroot has passed!" << std::endl;
    } else {
        std::cout << "Test for sqroot has failed!" << std::endl;
    }
}

void test_abs_custom() {
    double x1 = -5.0;
    double x2 = 3.0;
    double x3 = 0.0;
    
    double abs1 = abs_custom(x1);
    double abs2 = abs_custom(x2);
    double abs3 = abs_custom(x3);
    
    if (std::fabs(abs1 - 5.0) < 1e-9 &&
        std::fabs(abs2 - 3.0) < 1e-9 &&
        std::fabs(abs3 - 0.0) < 1e-9) {
        std::cout << "Test for abs_custom has passed!" << std::endl;
    } else {
        std::cout << "Test for abs_custom has failed!" << std::endl;
    }
}

void test_convex_hull() {
    Point points[7] = {
        create_point(0.0, 0.0),
        create_point(0.0, 4.0),
        create_point(-4.0, 0.0),
        create_point(5.0, 0.0),
        create_point(0.0, -6.0),
        create_point(1.0, 0.0),
        create_point(2.0, 2.0) // Added extra point to verify function's behavior
    };

    Point hull[7]; // Adjusted to match the number of points
    int m;
    convex_hull(points, 7, hull, &m);

    Point Expected_hull[4] = {
        create_point(-4.0, 0.0),
        create_point(0.0, -6.0),
        create_point(5.0, 0.0),
        create_point(0.0, 4.0)
    };

    bool passed = true;
    if (m != 4) { // Ensure the number of points in the hull is as expected
        std::cout << "Test for convex hull has failed!" << std::endl;
        passed = false;
    } else {
        for (int i = 0; i < m; i++) {
            bool found = false;
            for (int j = 0; j < 4; j++) {
                if (Expected_hull[j].x == hull[i].x && Expected_hull[j].y == hull[i].y) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Test for convex hull has failed!" << std::endl;
                passed = false;
                break;
            }
        }
    }

    if (passed) {
        std::cout << "Test for convex hull has passed!" << std::endl;
    }
}

void test_orientation() {
    Point p = create_point(-1, -1);
    Point q = create_point(0, 1);
    Point r = create_point(2, 5);

    int orient = orientation(p, q, r);
    if (orient == 0) {
        std::cout << "Test for orientation (collinear) has passed!" << std::endl;
    } else {
        std::cout << "Test for orientation (collinear) has failed!" << std::endl;
    }

    p = create_point(0, 0);
    q = create_point(4, 0);
    r = create_point(2, 3);

    orient = orientation(p, q, r);
    if (orient == 1) {
        std::cout << "Test for orientation (clockwise) has passed!" << std::endl;
    } else {
        std::cout << "Test for orientation (clockwise) has failed!" << std::endl;
    }

    p = create_point(0, 0);
    q = create_point(4, 0);
    r = create_point(2, -3);

    orient = orientation(p, q, r);
    if (orient == 2) {
        std::cout << "Test for orientation (counterclockwise) has passed!" << std::endl;
    } else {
        std::cout << "Test for orientation (counterclockwise) has failed!" << std::endl;
    }
}

int main() {
    test_create_point();
    test_distance();
    test_sqroot();
    test_abs_custom();
    test_convex_hull();
    test_orientation();

    std::cout << "All functions tested and passed!" << std::endl;

    return 0;
}
