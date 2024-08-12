/* #include "geometry.hpp"
#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    Point arr[n];
    for (int i = 0; i < n; i++) {
        double x, y;
        cout << "Enter point " << i + 1 << " (x y): ";
        cin >> x >> y;
        arr[i] = create_point(x, y);
    }

    Point hull[n];
    int m;
    convex_hull(arr, n, hull, &m);

    cout << "Convex Hull Points:" << endl;
    for (int i = 0; i < m; i++) {
        print(hull[i]);
    }

    return 0;
}
 */
#include "geometry.hpp"
#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    Point* arr = new Point[n];  // Dynamically allocate memory for the points
    for (int i = 0; i < n; i++) {
        double x, y;
        cout << "Enter point " << i + 1 << " (x y): ";
        cin >> x >> y;
        arr[i] = create_point(x, y);
    }

    Point* hull = new Point[n];  // Dynamically allocate memory for the convex hull points
    int m;
    convex_hull(arr, n, hull, &m);

    cout << "Convex Hull Points:" << endl;
    for (int i = 0; i < m; i++) {
        print(hull[i]);
    }

    delete[] arr;  // Free the dynamically allocated memory
    delete[] hull;

    return 0;
}