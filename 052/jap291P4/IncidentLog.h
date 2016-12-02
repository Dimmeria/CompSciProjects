/*
 *  IncidentLog.h                                 
 *
 *  COSC 052 Fall 2016                          
 *  Project #4                                   
 *                                                
 *  Due on: NOV 17, 2016                  
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


//Obligatory header guards
#ifndef IncidentLog_test
#define IncidentLog_test

//Including necessary bits and bobs
#include "PHMSA7000.h"
#include "LL.h"



//Class declaration
class IncidentLog
{
private:
    LL<HazMat7k*> allIncidents;
    
public:
    IncidentLog();
    
    ~IncidentLog();
    //Default constructor and destructor
    
    void displayReport() const;
    //Loops through the vector of objects and outputs thier data to 
    //  the terminal in a nice clean format
    
    void appendObject(HazMat7k* ptr7k) { allIncidents.push_back(ptr7k); }
    //Accepts a HazMat7k object or one of its derived objects and adds it to the internal LL
    
    unsigned long size() const { return allIncidents.size(); }
    //returns the total number of reports

};


/**********************
 *    Definitions     *
 **********************/

//Default constructor
IncidentLog::IncidentLog()
{
}

//Destructor
IncidentLog::~IncidentLog()
{
    allIncidents.clear();
}

    
void IncidentLog::displayReport() const
{
    
   /**************************************
    * Try block for catching out_of_range*
    **************************************/
   try {
        //Holding the number of each type of object
        int numOfFatal=0,numOfLoss=0;
        
        ///*
        //looping through each of the logs and printing it
        for(int i = 0; i < size(); i++) {
            //Calling the summaryReport function of the underlying object
            // this does most of the pretty formatting for us
            if(allIncidents.at(i)->getIncidentCode() == 'f') {
                numOfFatal+=1;
            }
            else if(allIncidents.at(i)->getIncidentCode() == 'l'){
                numOfLoss+=1;
            }
        }
        //*/
        
        /*
        //Making iterators to be the beginning, current, and the last node
        LL_iterator<HazMat7k*> itrB;
        LL_iterator<HazMat7k*> itrC;
        LL_iterator<HazMat7k*> itrE;
        
        //Starting at the beginning
        itrB = allIncidents.begin();
        itrC = allIncidents.begin();
        itrE = allIncidents.end();
        
        while(itrC != itrE) {
            //Calling the summaryReport function of the underlying object
            // this does most of the pretty formatting for us
            if((*itrC)->getIncidentCode() == 'f') {
                numOfFatal+=1;
            }
            else if((*itrC)->getIncidentCode() == 'l'){
                numOfLoss+=1;
            }
            ++itrC;
        }
        //Going back to the beginning
        itrC = itrB;
        */
        
        //Beginning message of the report on fatalities
        std::cout << "Form PHMSA F 7000-1 Accident Report - Hazardous Liquid Pipeline Systems (";
        std::cout << numOfFatal << ") records with fatality or injury:";
        std::cout << std::endl << std::endl;
        
        ///*
        //looping through each of the logs and printing it
        for(int i = 0; i < size(); i++) {
            //Calling the summaryReport function of the underlying object
            // this does most of the pretty formatting for us
            if(allIncidents.at(i)->getIncidentCode() == 'f') {
                allIncidents.at(i)->summaryReport();
            }
        }
        //*/
        
        /*
        //Looping through all objects and outputting if it's a fatal incident
        while(itrC != itrE) {
            if ((*itrC)->getIncidentCode() == 'f') {
                (*itrC)->summaryReport();
            }
            ++itrC;
        }
        //Going back to the beginning
        itrC = itrB;
        */
        
        //Spacing to make it look pretty
        std::cout << std::endl << std::endl;
    
        //Beginning message of the report on material loss
        std::cout << "Form PHMSA F 7000-1 Accident Report - Hazardous Liquid Pipeline Systems (";
        std::cout << numOfLoss << ") records with only material loss or damage:";
        std::cout << std::endl << std::endl;
        
        ///*
        for(int i = 0; i < size(); i++) {
            //Calling the summaryReport function of the underlying object
            // this does most of the pretty formatting for us
            if(allIncidents.at(i)->getIncidentCode() == 'l') {
                allIncidents.at(i)->summaryReport();
            }
        }
        //*/
        
        /*
        //Looping through all incidents and outputting if not fatal
        while (itrC != itrE) {
            if ((*itrC)->getIncidentCode() == 'l') {
                (*itrC)->summaryReport();
            }
            ++itrC;
        }
        */
        
    } catch(std::out_of_range) {
       throw;
    } //rethrowing to main
    
    //More pretty formatting
    std::cout << "End Report." << std::endl;
}




#endif
