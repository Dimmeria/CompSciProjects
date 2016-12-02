/*
 *  DateTime.h                                 
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

#ifndef COSC052Fall2016P01MileStone2_DateTime_h
#define COSC052Fall2016P01MileStone2_DateTime_h

//#define DEBUG_DATE

#include <iostream>

/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class Date declaration                                 **
 **                                                                        **
 **                 You will write the Date class declaration.             **
 **                 Do not make another file, put the Date                 **
 **                 class declaration in this file along                   **
 **                 with the provided Time class declaration.              **
 **                                                                        **
 **                                                                        **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/

class Date
{
    //Overloaded stream extraction and insertion operators
    friend std::istream& operator>>(std::istream &in, Date &d);
    
    friend std::ostream& operator<<(std::ostream &os, const Date &d);
    
    
private:
    //Initializing the data members of date
    int yyyy;
    int mm;
    int dd;
    
public:

/************************
 * Various Constructors *
 ************************/
    //Default Constructor
    Date(int y = 1923, int m = 1, int d = 1);
    
    //Copy Constructor
    Date(const Date &d);
    
/*********************
 * Mutator Functions *
 *********************/
    void setDate(int y, int m, int d);
    
    void setDate(const Date &d);
    
/**********************
 * Accessor Functions *
 **********************/
    int getYear() const { return yyyy; }
    int getMonth() const { return mm; }
    int getDay() const { return dd; }
    
/************************
 * Operator Overloading *
 ************************/
    bool operator==(const Date &rhs);
    bool operator!=(const Date &rhs);
    bool operator<=(const Date &rhs);
    bool operator<(const Date &rhs);
    bool operator>=(const Date &rhs);
    bool operator>(const Date &rhs);
    Date& operator=(const Date &d);
    
    
};




/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class Time declaration                                 **
 **                                                                        **
 **                 This code is provided to students                      **
 **                 in COSC 052 Summer 2016 to use in                      **
 **                 part or in total for class projects.                   **
 **                 Students may use this code as their                    **
 **                 own, without any attribution.                          **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/

class Time 
{
    friend std::istream& operator>>(std::istream &in, Time &t);
        //Overloaded stream extraction operator
        //Postcondition: Extracts values for each data member from 
        //the input stream.  Format of the data in the stream 
        //is assumed to be:  hh:mm:ss.sssZ
        //The delimiting characters are read and discarded.
        //The decimal point is read and discarded.  The fractional
        //seconds are stored as an integer. 
    
    friend std::ostream& operator<<(std::ostream &os, const Time &t);
        //Overloaded stream insertion operator.
        //Postcondition: The time is output to the steam.  Delimiting 
        //characters are replaced and the decimal point is added
        //between the seconds and fraction sections.  The result
        //is a time value output in the same format as was read in.
    
private:
    int hh;   //two digit integer for hour of day
    int mm;   //two digit integer for minute of day
    
    
public:
    Time(int = 0, int = 0);
        //constructor with parameters, with default values
        //This constructor calls the member function setTime()
        //and passes the same arguments as were passed in to
        //the constructor, function setTime() updates the data members.
        //Postcondition: Sets the values of hh and mm
        //according to the values of the arguments passed in.
        //If no values are passed, this acts as the default constructor
        //all integer data members are set to zero  
    
    void setTime(int, int);
        //Function to set the values of the object data members,
        //can be called directly or by a constructor.
        //Postcondition: Data members are set to the values
        //of the respective arguments passed in.
    
    int getHour() const {return hh;}
        //In-line function to return the hour value.
        //Postcondtion: The value of data member hh is retured. 
    
    int getMinute() const {return mm;}
        //In-line function to return the minute value.
        //Postcondtion: The value of data member mm is retured.
    
    Time& operator=(const Time &rhs);
        //Overloaded assignment operator.
        //Postcondtion: The values of right hand side object's
        //data members are copied to the respective data
        //members of the left hand side object.
    
}; //END class Time declaration



/****************************************************************************
 **                                                                        **
 **                    class ProcessTimer declaration                      **
 **                                                                        **
 **                  This code is provided to students                     **
 **                  in COSC 052 Fall 2016 to use in part                  **
 **                  or in total for class projects.                       **
 **                  Students may use this code as their                   **
 **                  own, without any attribution.                         **
 **                                                                        **
 ****************************************************************************/
 
class ProcessTimer
{
    friend std::ostream& operator<<(std::ostream&, const ProcessTimer&);
    
private:
    clock_t timeStart; //start time
    clock_t timeEnd; //end time
    
public:
    ProcessTimer();
    ProcessTimer(clock_t);
    ~ProcessTimer();
    void setTimeStart(clock_t);
    void setTimeEnd(clock_t);
    clock_t getTimeStart();
    clock_t getTimeEnd();
    clock_t getTimeElapsed();
    
}; //end class ProcessTimer





#endif
