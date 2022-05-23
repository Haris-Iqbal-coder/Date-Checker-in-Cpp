
// Author: Muhammad Haris Iqbal

#include <iostream>
using namespace std;

class Date
{
    int day, month, year;
    bool isvalidDate(int, int, int);  // to check if the date is valid given the conditions
    static int daysDifference(const Date d1,const Date d2);  // helper function 

public:
    Date();
    Date(int, int, int);
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    void setAll(int, int, int);
    void showDate();
    static bool isLeapYear(const int);
    bool isLeapYear();
    static bool isLeap(const Date);
    static int daysPassed(const Date);
    static int daysPassed(const Date d1, const Date d2);
};

Date::Date()
{
    day = 1;
    month = 1;
    year = 1970;
}

bool Date ::isvalidDate(int d, int m, int y)
{
    if (y < 1970)
        return false;
    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > 31)
        return false;

    // check for february's with leap year
    if (m == 2)
    {
        if (isLeapYear(y))
            return (d <= 29);
        else
            return (d <= 28);
    }

    // months having 30 days
    if (m == 4 || m == 6 || m == 9 || m == 11)
        return (d <= 30);

    return true;
}

Date::Date(int d, int m, int y)
{
    if (isvalidDate(d, m, y))
    {
        day = d;
        month = m;
        year = y;
    }
    else
    {
        day = 1;
        month = 1;
        year = 1970;
        cout << "Date is invalid. Date set to the default 1-1-1970" << endl;
    }
}

void Date::setDay(int d)
{
    if (isvalidDate(d, month, year))
    {
        day = d;
    }
    else
    {
        cout << "Day is invalid for the current month" << endl;
    }
}

void Date::setMonth(int m)
{
    if (isvalidDate(day, m, year))
    {
        month = m;
    }
    else
    {
        cout << "Month is invalid for the current year" << endl;
    }
}

void Date::setYear(int y)
{
    if (isvalidDate(day, month, y))
    {
        year = y;
    }
    else
    {
        cout << "Year is invalid" << endl;
    }
}

void Date::setAll(int d, int m, int y)
{
    if (isvalidDate(d, m, y))
    {
        day = d;
        month = m;
        year = y;
    }
    else
    {
        cout << "Date is invalid." << endl;
    }
}

void Date::showDate()
{
    const string month_list[12] = {"Jan", "Feb", "Mar", "Apr", "May", "June", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    if (day < 10)
    {
        cout << "0" << day << '-' << month_list[month - 1] << '-' << year << endl;
    }
    else
    {
        cout << day << '-' << month_list[month - 1] << '-' << year << endl;
    }
}

bool Date::isLeapYear(const int y)
{
    if (y < 1970)
    {
        return false;
    }
    return (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
}

bool Date::isLeapYear()
{
    if (year < 1970)
    {
        return false;
    }
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

bool Date::isLeap(const Date obj)
{
    if ((obj.year < 1970))
    {
        return false;
    }
    return (obj.year % 4 == 0 && obj.year % 100 != 0 || obj.year % 400 == 0);
}

int Date::daysPassed(const Date obj)
{
    int days_passed = 0;

    for (int i = 1970; i < obj.year; i++)
    {
        if (isLeapYear(i))
        {
            days_passed += 366;   // for leap year
        }
        else
        {
            days_passed += 365;
        }
    }

    for (int j = 1; j < obj.month; j++)
    {
        if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12)   // months with 31 days
        {
            days_passed += 31;
        }
        else if (j == 4 || j == 6 || j == 9 || j == 11)
        {
            days_passed += 30;
        }
        else if (j == 2)
        {
            if (isLeapYear(obj.year))
            {
                days_passed += 29;
            }
            else
            {
                days_passed += 28;
            }
        }
    }

    for (int k = 1; k < obj.day; k++)
    {
        days_passed += 1;
    }

    cout << days_passed << endl;
    return days_passed;
}

int Date::daysDifference(const Date d1, const Date d2)
{
    int days_passed = 0;
    int current_year = d1.year;
    int month_days[13] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = d1.year; i < d2.year; i++)
    {
        if (isLeapYear(i))
        {
            days_passed += 366;
            current_year++;
        }
        else
        {
            days_passed += 365;
            current_year++;
        }
    }

    if (d1.month > d2.month)
    {
        for (int j = d1.month - 1; j >= d2.month; j--)  // calculate difference between days of months not in a full year
        {
            if (j == d2.month)
            {
                days_passed -= ((month_days[j - 1] - d2.day) + d1.day);
            }
            else
            {
                days_passed -= (month_days[j - 1]);
            }
        }

        return days_passed;
    }
    for (int k = d1.month; k < d2.month; k++)
    {

        if (k == 1 || k == 3 || k == 5 || k == 7 || k == 8 || k == 10 || k == 12)
        {
            days_passed += 31;
        }
        else if (k == 4 || k == 6 || k == 9 || k == 11)
        {
            days_passed += 30;
        }
        else if (k == 2)
        {
            if (isLeapYear(d2.year))
            {
                days_passed += 29;
            }
            else
            {
                days_passed += 28;
            }
        }
    }

    if (d2.day > d1.day)
    {
        for (int l = d1.day; l < d2.day; l++)
        {
            days_passed += 1;
        }

        return days_passed;
    }

    days_passed -= d1.day; // difference betwwen dates if d1 > d2
    days_passed += d2.day;

    return days_passed;
}

int Date::daysPassed(const Date d1, const Date d2)
{
    int total_days = 0;
    if (d1.year < d2.year)
    {
        int total_days = daysDifference(d1, d2);
        cout << total_days << endl;
    }
    else
    {
        int total_days = daysDifference(d2, d1);
        cout << '-' << total_days << endl;
    }

    return total_days;
}

int main()
{
    Date d1(6, 7, 2015);
    // creates object d1 and set to july 6 2015
    Date d2(23, 3, 2022);
    // creates object d2 and set to march 23 2022
    d1.showDate();
    // displays date d1
    d2.showDate();
    // displays date d2
    d1.setDay(20);
    // changes d1 to july 20 2015
    d1.setMonth(12);
    // changes d1 to dec 20 2015
    d1.setYear(2021);
    // changes d1 to dec 20 2021
    d1.setAll(5, 10, 2020);
    // changes d1 to oct 5 2020
    d1.showDate();
    // displays new d1 date 
   

    cout << Date::isLeapYear(1999) << endl;
    // checks if 1999 is a leap year and prints 0 as it's false
    cout << d1.isLeapYear() << endl;
    // checks d for a leap year and prints 1 as it's true 
    cout << Date::isLeap(d1) << endl;
    // checks d1 for a leap year and prints 1 as it's true

    d1.daysPassed(d1);
    // calculate days passed between jan 1 1970 and d1 (prints 18540)
    d1.daysPassed(d1, d2);  
    // calculates days passed between d1 and d2 (prints 535)
}
