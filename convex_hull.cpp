#include <bits/stdc++.h> // convex hell calculate kar rha hai grahms scan algorithm se
using namespace std;

// POINT STRUCTURE - x aur y coordinates store karne ke liye
struct Point
{
    int x, y; // x = horizontal position, y = vertical position
};

// ORIENTATION FUNCTION - 3 points ka geometric relationship check karta hai
// p -> c -> n ke sequence mein check karte hain ki turn kaisa hai
// Return values:
// 0 → collinear (teeno points same line par hain)
// 1 → clockwise turn (right turn, CW direction)
// 2 → counterclockwise turn (left turn, CCW direction)
int orientation(Point p, Point c, Point n)
{
    // CROSS PRODUCT FORMULA use kar rahe hain
    // Formula: (c.y - p.y) * (n.x - c.x) - (c.x - p.x) * (n.y - c.y)
    // Ye formula vector cross product se aata hai
    // Vector PC = (c.x - p.x, c.y - p.y)
    // Vector CN = (n.x - c.x, n.y - c.y)
    // Cross product = PC.x * CN.y - PC.y * CN.x
    long long val = 1LL * (c.y - p.y) * (n.x - c.x) - // Pehla part
                    1LL * (c.x - p.x) * (n.y - c.y);  // Dusra part

    // 1LL use kar rahe hain long long mein convert karne ke liye (overflow avoid karne ke liye)

    if (val == 0)
        return 0;             // Zero means collinear (same line par)
    return (val > 0) ? 1 : 2; // Positive = clockwise, Negative = counterclockwise
}

// DISTANCE SQUARE FUNCTION - do points ke beech distance ka square nikalta hai
// Square root nahi lete kyunki comparison ke liye square hi kaafi hai
// Distance formula: sqrt((x2-x1)² + (y2-y1)²) but hum square return karte hain
long long distSq(Point a, Point b)
{
    return 1LL * (a.x - b.x) * (a.x - b.x) + // (x2-x1)²
           1LL * (a.y - b.y) * (a.y - b.y);  // (y2-y1)²
}

// GLOBAL VARIABLE - reference point store karta hai polar angle sorting ke liye
Point p0; // Sabse neeche wala point jo sorting ka center banega

// POLAR ANGLE COMPARATOR FUNCTION - sorting ke liye custom comparison
// p0 ke relative polar angle ke hisaab se points ko sort karta hai
bool polarSort(Point c, Point n)
{
    // p0 se c aur n ka orientation check karo
    int o = orientation(p0, c, n);

    if (o == 0)
    {
        // Agar collinear hain (same angle par) toh jo closer hai wo pehle aaye
        // Distance ke hisaab se sort karo - nearest first
        return distSq(p0, c) < distSq(p0, n);
    }

    // Counterclockwise (left turn) ko priority do
    // Graham scan mein counterclockwise order chahiye
    return (o == 2); // 2 = counterclockwise, true return karo
}

// MAIN CONVEX HULL FUNCTION - Graham's Scan Algorithm implement karta hai
vector<Point> convexHull(vector<Point> &pts)
{
    int n = pts.size(); // Total points count

    // EDGE CASE: Agar 3 se kam points hain toh convex hull nahi ban sakta
    // Convex hull banane ke liye minimum 3 points chahiye
    if (n < 3)
        return {}; // Empty vector return kar do

    // STEP 1: BOTTOMMOST POINT FIND KARO
    // Sabse neeche wala point find karo jo starting reference banega
    int minIdx = 0; // Assume karo pehla point sabse neeche hai

    for (int i = 1; i < n; i++)
    {
        // Y-coordinate compare karo (neeche wala chahiye)
        if (pts[i].y < pts[minIdx].y ||
            // Agar y same hai toh x-coordinate check karo (left wala chahiye)
            (pts[i].y == pts[minIdx].y && pts[i].x < pts[minIdx].x))
        {
            minIdx = i; // Naya minimum point mil gaya
        }
    }

    // Sabse neeche wale point ko 0th position par move kar do
    swap(pts[0], pts[minIdx]);
    p0 = pts[0]; // Global reference point set kar do sorting ke liye

    // STEP 2: POLAR ANGLE SORTING
    // Starting point (pts[0]) ko chhod kar baaki sab points ko polar angle se sort karo
    // Counterclockwise order mein arrange honge
    sort(pts.begin() + 1, pts.end(), polarSort);

    // Sorting ke baad points p0 se counterclockwise order mein arranged hain
    // p0 -> nearest point -> next nearest point -> ... -> farthest point

    // STEP 3: GRAHAM SCAN MAIN ALGORITHM
    // Stack-based approach use karte hain
    vector<Point> hull; // Ye hamara stack hai jo convex hull points store karega

    // Pehle 3 points add kar do hull mein (initial triangle)
    hull.push_back(pts[0]); // Starting point (bottommost)
    hull.push_back(pts[1]); // First sorted point
    hull.push_back(pts[2]); // Second sorted point

    // Ab baaki points ko ek ek karke process karo
    for (int i = 3; i < n; i++)
    {
        // STACK PROPERTY MAINTAIN KARO
        // Hull mein sirf left turns (counterclockwise) allow hain
        // Jab tak right turn mil raha hai, points remove karte raho

        while (hull.size() > 1 &&
               orientation(hull[hull.size() - 2], hull.back(), pts[i]) != 2)
        {
            // hull[size-2] = second last point (p)
            // hull.back() = last point (c)
            // pts[i] = current point (n)

            // Agar orientation 2 nahi hai (means left turn nahi hai)
            // Toh last point ko remove kar do kyunki wo convex hull ka part nahi
            hull.pop_back(); // Stack se top element remove kar do
        }

        // Current point ko hull mein add kar do
        // Yahan tak pahunchne ka matlab hai ki current point valid hai
        hull.push_back(pts[i]);
    }

    // Final convex hull return kar do
    // Hull mein points counterclockwise order mein arranged hain
    return hull;
}

// MAIN FUNCTION - Testing aur output ke liye
int main()
{
    // TEST CASE: Sample points define kar rahe hain
    // Ye points 2D plane mein scattered hain
    vector<Point> pts = {
        {0, 0}, // Origin
        {1, 1}, // Diagonal point
        {2, 2}, // Collinear with (1,1)
        {3, 1}, // Right side point
        {4, 3}, // Upper right
        {5, 5}, // Farthest upper right
        {1, 4}, // Upper left
        {3, 3}, // Middle upper
        {7, 2}, // Farthest right
        {6, 1}  // Right side
    };

    // CONVEX HULL COMPUTE KARO
    vector<Point> hull = convexHull(pts);

    // RESULT PRINT KARO
    cout << "Convex Hull points (in counterclockwise order):\n";
    for (auto &p : hull)
    {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    // OUTPUT: Hull mein sirf wo points honge jo actual boundary banate hain
    // Interior points (jo hull ke andar hain) include nahi honge

    return 0;
}