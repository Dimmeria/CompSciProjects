/*
 *  DateTime.cpp                                 
 *
 *  COSC 052 Fall 2016                          
 *  Project #5                                   
 *                                                
 *  Due on: Dec 1, 2016                  
 *  Author: Andrew Paliotta                           
 * 
 *
 *  In accordance with the class policies and Georgetown's
 *  Honor Code, I certify that, with the exception of the 
 *  class resources and those items noted below, I have neither
 *  given nor received any assistance on this project. 
 *
 *  References not otherwise commented within the program source code.
 *  Note that you should not mention any help from the TAs, the professor, 
 *  or any code taken from the class textbooks.
 */


#include <iomanip>
#include <iostream>
#include "DateTime.h"

using std::cout;
using std::endl;


/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class Date implementation code                         **
 **                                                                        **
 **                 You will write all of the Date class                   **
 **                 implementation code.  Do not make another              **
 **                 file, put your code for the Date class                 **
 **                 in this file along with the provided                   **
 **                 Time class implementation code.                        **
 **                                                                        **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/
/************************
 * Various Constructors *
 ************************/

//Default Constructor
Date::Date(int y, int m, int d)
{
    yyyy = y;
    
    mm = m;
    
    dd = d;
}
    
//Copy Constructor
Date::Date(const Date &d)
{
    yyyy = d.getYear();
    
    mm = d.getMonth();
    
    dd = d.getDay();
}
    
    
    
/*********************
 * Mutator Functions *
 *********************/
void Date::setDate(int y, int m, int d)
{
    yyyy = y;
    
    mm = m;
    
    dd = d;
}
    
void Date::setDate(const Date &d)
{
    yyyy = d.getYear();
    
    mm = d.getMonth();
    
    dd = d.getDay();
}



/************************
 * Operator Overloading *
 ************************/

//Overloaded equality operator
bool Date::operator==(const Date &rhs)
{
    //If the years are not equal returns false
    // otherwise continues as this means
    // they must be equal
    if (yyyy != rhs.getYear()){
        return 0;
    }
    
    //If the months are not equal returns false
    // otherwise continues as this means they
    // must be equal
    if (mm != rhs.getMonth()) {
        return 0;
    }
    
    //If the days are not equal returns false
    // otherwise continues as this means they
    // are ultimately equal
    if (dd != rhs.getDay()) {
        return 0;
    }
    
    //returning true if all tests were passed
    return 1;
}


//Overloaded not equal operator
bool Date::operator!=(const Date &rhs)
{
    //If the years are not equal returns true
    //  otherwise continues
    if (yyyy != rhs.getYear()){
        return 1;
    }
    
    //If the months are not equal returns true
    //  otherwise continues
    if (mm != rhs.getMonth()) {
        return 1;
    }
    
    //If the days are not equal returns true
    //  otherwise continues
    if (dd != rhs.getDay()) {
        return 1;
    }
    
    //returning false if all tests were failed
    return 0;
}


//Overloaded less than or equal to operator
bool Date::operator<=(const Date &rhs)
{
    //Using already defined operators to speed things up
    if (*this == rhs) {
        return 1;
    }
    
    if (*this < rhs){
        return 1;
    }
    
    
    return 0;
}


//Overloaded less than operator
bool Date::operator<(const Date &rhs)
{
    //If the lhs year is greater than the rhs year
    //  (Meaning that it not less than)
    //  returns false
    //  otherwise continues
    if (yyyy < rhs.getYear()){
        return 1;
    }
    
    //If the years are equal we must also test that the month
    // is less than the rhs month
    if (yyyy == rhs.getYear() && mm < rhs.getMonth()) {
        return 1;
    }
    
    //Finally test that if the years and months are equal, that
    // the day is less than the rhs day
    if (yyyy == rhs.getYear() && mm == rhs.getMonth() && dd < rhs.getDay()) {
        return 1;
    }
    
    //returning false if all tests were failed
    return 0;
}


//Overloaded greater than or equal to operator
bool Date::operator>=(const Date &rhs)
{
    //If the lhs date is less than the rhs by the previously
    // defined operator then it is not greater than or equal
    // to so return false
    if (*this < rhs){
        return 0;
    }
    
    //If it is not less than, then it must be greater than
    // or equal to so return true
    return 1;
}


//Overloaded greater than operator
bool Date::operator>(const Date &rhs)
{
    //If the dates are equal by the previously defined
    // operator then return false as lhs not greater than
    // rhs
    if (*this == rhs){
        return 0;
    }
    
    //If rhs less than lhs by the previously defined
    // operator then return flase
    if (*this < rhs){
        return 0;
    }
    return 1;
}


Date& Date::operator=(const Date &d)
{
    if (this != &d){
        yyyy = d.getYear();
    
        mm = d.getMonth();
    
        dd = d.getDay();
    }
    
    return *this;
}

/********************
 * Friend functions *
 ********************/

//Stream extraction operator
std::istream& operator>>(std::istream &input, Date &d)
{
    input >> d.yyyy;

    input >> d.mm;
    
    input >> d.dd;

    return input;
}

//Stream insertion operator
std::ostream& operator<<(std::ostream &output, const Date &d)
{
    //Setting fill to zeroes to pad date
    output << std::setfill('0');
    
    output << d.getYear() << "/";
    output << std::setw(2) << d.getMonth() << "/";
    output << std::setw(2) << d.getDay();
    
    //seting fill back to standard value
    std::setfill(" ");
    
    return output;
}

/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class Time implementation code                         **
 **                                                                        **
 **                 This code is provided to students                      **
 **                 in COSC 052 Fall 2016 to use in                        **
 **                 part or in total for class projects.                   **
 **                 Students may use this code as their                    **
 **                 own, without any attribution.                          **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/



/****************************************************************************
 *                    Time class default constructor                        *
 ****************************************************************************/

Time::Time(int hour, int minute)
{
#ifdef DEBUG_DATE
    std::cout << "Entered constructor Time::Time(int, int, int)" << std::endl;
#endif
    
    setTime(hour, minute);
    
#ifdef DEBUG_DATE
    std::cout << "Exiting constructor Time::Time(int, int)" << std::endl;
#endif
    
} //END constructor with parameters for Time class 



/****************************************************************************
 *                  Time class member function setTime                      *
 ****************************************************************************/

void Time::setTime(int hour, int minute)
{
    hh = hour;
    mm = minute;
    
} //END member function Time::setTime



/****************************************************************************
 *                 Time class stream extraction operator                    *
 ****************************************************************************/

std::istream& operator>>(std::istream &in, Time &t)
{
    // input format is expected to be hh:mm
    // examples:
    // 2:45
    // 02:45
    // 15:30
    // 18:05
    
    char ch;
    
    in >> t.hh; //extract the hours and store them in data member hh
    
    in >> ch; //extract and discard the dilimiting character
    
    in >> t.mm; //extract the minutes and store them in data member mm
    
    return in;
    
} //END overloaded stream extraction operator for Time class



/****************************************************************************
 *                 Time class stream insertion operator                     *
 ****************************************************************************/

std::ostream& operator<<(std::ostream &os, const Time &t)
{
    os << std::setfill('0');
    
    os << std::setw(2) << t.hh << ":";
    os << std::setw(2) << t.mm; 
    
    os << std::setfill(' ');
    
    return os;
    
} //END overloaded stream insertion operator for Time class



/****************************************************************************
 *                     Time class assignment operator                       *
 ****************************************************************************/

Time& Time::operator=(const Time &rhsObj)
{
    if (this != &rhsObj)
    {
        //not a self assignment, OK to proceed
        hh = rhsObj.hh;
        mm = rhsObj.mm;
    }
    
    return *this;
    
} //END overloaded assignment operator for Time class




/****************************************************************************
 **                                                                        **
 **                class ProcessTimer implementation code                  **
 **                                                                        **
 **                  This code is provided to students                     **
 **                  in COSC 052 Fall 2016 to use in part                  **
 **                  or in total for class projects.                       **
 **                  Students may use this code as their                   **
 **                  own, without any attribution.                         **
 **                                                                        **
 ****************************************************************************/

ProcessTimer::ProcessTimer()
{
    timeStart = 0;
    timeEnd = 0;
}

ProcessTimer::ProcessTimer(clock_t tmSt)
{
    timeStart = tmSt;
    timeEnd = 0;
}

ProcessTimer::~ProcessTimer()
{
    //std::cout << "Inside destructor for ProcessTimer object" << std::endl;
}

std::ostream& operator<<(std::ostream &os, const ProcessTimer &tmStmp)
{
    std::cout << "Start time:\t" << tmStmp.timeStart << "\n";
    std::cout << "End time:\t" << tmStmp.timeEnd << "\n";
    std::cout << "Elapsed time:\t" 
    << (tmStmp.timeEnd - static_cast<double>(tmStmp.timeStart))/CLOCKS_PER_SEC;
    std::cout << "\n";
    std::cout << std::endl;
    
    return os;
}

void ProcessTimer::setTimeStart(clock_t tmStart)
{
    timeStart = tmStart;
}

void ProcessTimer::setTimeEnd(clock_t tmEnd)
{
    timeEnd = tmEnd;
}


clock_t ProcessTimer::getTimeStart()
{
    return timeStart;
}

clock_t ProcessTimer::getTimeEnd()
{
    return timeEnd;
}


clock_t ProcessTimer::getTimeElapsed()
{
    return (timeEnd - static_cast<double>(timeStart))/CLOCKS_PER_SEC;
}


