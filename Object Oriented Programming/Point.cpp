#include <iostream>
#include <conio.h>
using namespace std;

class point
{
    double x, y;

public:
    point(double = 0, double = 0);
    point(const point &);                                    // copyconstructor: point p1 = p2 - ACTUALLY NOT NEEDED
    void print();                                            // print
    friend ostream &operator<<(ostream &os, const point &p); // cout << p1
    bool operator<(const point &);                           // p1 <  p2
    bool operator>=(const point &);                          // p1 >= p2
    bool operator>(const point &);                           // p1 >  p2
    bool operator<=(const point &);                          // p1 <= p2
    bool operator==(const point &);                          // p1 == p2
    const point operator+(const point &);                    // p1+p2
    const point operator-(const point &);                    // p1-p2
    point add(point);                                        // p1.add(p2)
    const point &operator=(const point &);                   // p1 = p2
    const point &operator++();                               // ++p1 - //- &: to simulate lvalue
    const point operator++(int);                             // p1++ - //- int = dummy variable - NO &
};

point::point(double x, double y)
{
    this->x = x;
    this->y = y;
}

point::point(const point &temp)
{
    x = temp.x;
    y = temp.y;
}

void point::print()
{
    cout << "( " << x << "," << y << " )" << endl;
}

ostream &operator<<(ostream &os, const point &p)
{
    os << "( " << p.x << "," << p.y << " )" << endl;
    return os;
}

bool point::operator<(const point &p2)
{
    return (x + y < p2.x + p2.y);
}

bool point::operator>=(const point &p2)
{
    return !(*this < p2);
}

bool point::operator>(const point &p2)
{
    return (x + y > p2.x + p2.y);
}

bool point::operator<=(const point &p2)
{
    return !(*this > p2);
}

bool point::operator==(const point &p2)
{
    return ((x == p2.x) && (y == p2.y));
}

const point point::operator+(const point &p2)
{
    /* point p3;
     p3.x = x + p2.x;
     p3.y = y + p2.y;
     return p3; */
    return point(x + p2.x, y + p2.y);
}

const point point::operator-(const point &p2)
{
    /* point p3;
     p3.x = x - p2.x;
     p3.y = y - p2.y;
     return p3; */
    return point(x - p2.x, y - p2.y);
}

point point::add(point p2)
{
    x += p2.x;
    y += p2.y;
    return *this;
}

const point &point::operator=(const point &temp)
{
    if (this != &temp) // NO selfassignment
    {
        x = temp.x;
        y = temp.y;
    }
    return *this;
}

const point &point::operator++()
{
    ++x, ++y;
    return *this;
}

const point point::operator++(int)
{
    /* point temp = *this;
     x++, y++;
     return temp; */
    return point(x++, y++);
}

int main()
{
    point p1, p2(1, 2), p3 = p2++;
    cout << p3 << p2 << p1 << (p3 < p2) << (p3 == p2) << (p3 + p2) << (p3 - p2);
}