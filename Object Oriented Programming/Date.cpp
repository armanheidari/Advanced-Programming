#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

//! INT DATE
class IntDate
{
private:
    int day, month, year;

public:
    IntDate(int = 1, int = 1, int = 0);
    void put()
    {
        cout << year << " /" << month << " /" << day << endl;
    }
    bool operator>(IntDate d2);
    bool operator<=(IntDate d2);
};

IntDate::IntDate(int d, int m, int y)
{
    if (y < 0 || m < 1 || d < 1 || (d > 30 && m > 6) || d > 31)
    {
        day = 1, month = 1, year = 0;
    }
    else
    {
        day = d, month = m, year = y;
    }
}

bool IntDate::operator>(IntDate d2)
{
    if (year > d2.year)
        return true;
    else if (year == d2.year && month > d2.month)
        return true;
    else if (year == d2.year && month == d2.month && day > d2.day)
        return true;
    else
        return false;

    /* //* Pro Edition :
    return (year > d2.year) || (year == d2.year && month > d2.month) || (year == d2.year && month == d2.month && day > d2.day);
    */
}

bool IntDate::operator<=(IntDate d2)
{
    IntDate temp(day, month, year);
    return !(temp > d2);

    /*
    return !operator>(d2); // .!(d1.operator>(d2))

    return !(*this > d2);
    */
}

//! Char Date
class CharDate
{
private:
    int day, year;
    char month[20];
    int monthcheck(const char *);

public:
    CharDate(int = 1, const char * = "Farvardin", int = 0);
    void put()
    {
        cout << year << " /" << month << " /" << day << endl;
    }
    CharDate operator>(CharDate d2);
};

int CharDate::monthcheck(const char *m)
{
    const char months[][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i < 12; i++)
    {
        if (!strcmp(months[i], m))
        {
            return i + 1;
        }
    }
    return 0;
}

CharDate::CharDate(int d, const char *m, int y)
{
    int mn = monthcheck(m);
    if (y < 0 || mn < 1 || d < 1 || (d > 30 && mn > 6) || d > 31)
    {
        day = 1, year = 0;
        strcpy(month, "January");
    }
    else
    {
        day = d, year = y;
        strcpy(month, m);
    }
}

CharDate CharDate::operator>(CharDate d2)
{
    CharDate d3(day, month, year);
    if (year == d2.year)
    {
        if (monthcheck(month) == monthcheck(d2.month))
        {
            if (day >= d2.day)
            {
                return d3;
            }
            else
                return d2;
        }
        else
        {
            if (monthcheck(month) > monthcheck(d2.month))
            {
                return d3;
            }
            else
                return d2;
        }
    }
    else
    {
        if (year > d2.year)
        {
            return d3;
        }
        else
            return d2;
    }
}

//! String Date
int TF = 1;
string mo[13] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
class StringDate
{
    unsigned int d, y;
    string m;

public:
    StringDate(unsigned int a = 0, string b = "January", unsigned int c = 0)
    {
        for (int i = 0; i < 12; i++)
        {
            if (a <= 31 && b == mo[i])
            {
                d = a, m = b, y = c;
                TF = 0;
                break;
            }
        }
    }
    void put();
    bool isOk();
};

void StringDate::put()
{
    cout << m << " / " << d << " / " << y << endl;
}

bool StringDate::isOk()
{
    if (TF == 0)
        return true;
    else
        return false;
}

int main()
{
    //! Int Date
    // IntDate d1(1, 1, 1400);
    // IntDate d2(1, 2, 1401);
    // d1.put(), d2.put();
    // cout << (d1 > d2) << endl;
    // cout << (d1 <= d2) << endl;

    //! Char Date
    // CharDate d1(31, "January", 1400);
    // CharDate d2(29, "January", 0);
    // (d2 > d1).put();

    //! String Date
    // unsigned int a, c;
    // string b;
    // cout << "Please Enter your date : (Exmp: 4 April 2022)" << endl;
    // cin >> a >> b >> c;
    // StringDate d1(a, b, c);
    // if (d1.isOk() == false)
    // {
    //     cout << "Try again !! \n";
    //     main();
    // }
    // else
    //     d1.put();

    getch();
}