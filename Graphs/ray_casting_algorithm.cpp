/*
Idea:
Point se ek ray daalo (right direction mein →)
Gin lo kitni baar polygon ki edges ko cross karti hai

Odd crossings  → Point ANDAR hai  ✅
Even crossings → Point BAHAR hai  ❌

        |     |
   2    |  1  |    0
 (out)  | (in)|  (out)
--------*-----*--------→ ray
*/
/*
Ray casting edge cases mein fail ho sakta hai
(jab point exactly edge pe ho) to ise solve krne k liye use hota hai Winding Number
*/
#include <bits/stdc++.h>
using namespace std;

struct Point
{
    double x, y;
};

bool pointInPolygon(vector<Point> &polygon, Point P)
{
    int n = polygon.size();
    int crossings = 0;

    for (int i = 0; i < n; i++)
    {
        Point A = polygon[i];
        Point B = polygon[(i + 1) % n]; // Next vertex (last→first)

        // Ray sirf upward edges count karo (downward skip)
        if ((A.y <= P.y && B.y > P.y) || // Upward edge
            (B.y <= P.y && A.y > P.y))
        { // Downward edge

            // Ray ka intersection x coordinate nikalo
            double xIntersect = A.x +
                                (P.y - A.y) / (B.y - A.y) * (B.x - A.x);

            // Intersection point P ke right mein hai?
            if (P.x < xIntersect)
                crossings++;
        }
    }

    return crossings % 2 == 1; // Odd → inside
}

int main()
{
    // Square polygon
    vector<Point> polygon = {
        {0, 0}, {4, 0}, {4, 4}, {0, 4}};

    Point P1 = {2, 2}; // Andar
    Point P2 = {5, 5}; // Bahar
    Point P3 = {1, 1}; // Andar

    cout << pointInPolygon(polygon, P1) << endl; // 1 (true)
    cout << pointInPolygon(polygon, P2) << endl; // 0 (false)
    cout << pointInPolygon(polygon, P3) << endl; // 1 (true)
}
