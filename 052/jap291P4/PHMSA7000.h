/*
 *  PHMSA7000.h                                 
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


//Header Guards just in case
#ifndef PHMSA
#define PHMSA

//Including the header for the Date and time Classes
#include <string>
#include "DateTime.h"

/****************************************************************************
 ****************************************************************************                                                                       
 **                                                                        **
 **               struct HazMatData declaration                            **
 **                                                                        **
 **            This code is provided to students                           **
 **            in COSC 052 Fall 2016 to use in part                        **
 **            or in total for class projects.                             **
 **            Students may use this code as their                         **
 **            own, without any attribution.                               **
 **                                                                        **
 ****************************************************************************                                                                       
 ****************************************************************************/


struct HazMatData
{
    Date report_received_date;
    char report_number[10+1];
    char supplemental_number[7+1];
    char report_type[20+1];
    char operator_id[7+1];
    char name[55+1];
    char operator_street_address[57+1];
    char operator_city_name[18+1];
    char operator_state_abbreviation[4+1];
    char operator_postal_code[12+1];
    Date local_date;
    Time local_time;
    char commodity_released_type[84+1];
    double unintentional_release_bbls;
    double intentional_release_bbls;
    double recovered_bbls;
    int fatal;
    int injure;
    char ignite_ind[5+1];
    char explode_ind[5+1];
    Date prepared_date;
    char authorizer_name[45+1];
    char authorizer_email[42+1];
    char narrative[4000+1];
    
}; //END struct HazMatData declaration




/****************************************************************************
 ****************************************************************************                                                                       
 **                                                                        **
 **               HazMat7k class declaration                               **
 **                                                                        **
 **        Contains all of the data for each log entry                     **
 **                                                                        **
 ****************************************************************************                                                                       
 ****************************************************************************/

class HazMat7k
{
    friend std::ostream& operator<<(std::ostream &os, const HazMat7k &h);
    //Outputs all the data from the object on one line
    
private:
    Date reportReceivedDate;
    std::string reportNumber;
    std::string supplementalNumber;
    std::string reportType;
    std::string operatorID;
    std::string name;
    std::string operatorStreetAddress;
    std::string operatorCityName;
    std::string operatorStateAbbreviation;
    std::string operatorPostalCode;
    Date localDate;
    Time localTime;
    std::string commodityReleasedType;
    double unintentionalReleaseBbls;
    double intentionalReleaseBbls;
    double recoveredBbls;
    std::string igniteInd;
    std::string explodeInd;
    Date preparedDate;
    std::string authorizerName;
    std::string authorizerEmail;
    char incidentCode;
    
public:
/************************
 * Various Constructors *
 ************************/

    //Default Constructor
    HazMat7k();
    
    //Copy Constructor
    HazMat7k(const HazMatData &h);
    
    //Destructor
    virtual ~HazMat7k();
    
/********************
 * Member Functions *
 ********************/

    //Summary report functions
    virtual void summaryReport() const;
    //Outputs the objects data to the terminal
    //  nicely formatted
    
/**********************
 * Accessor functions *
 **********************/
    Date getReportReceivedDate() const {return reportReceivedDate;}
    std::string getReportNumber() const {return reportNumber;}
    std::string getSupplementalNumber() const {return supplementalNumber;}
    std::string getReportType() const {return reportType;}
    std::string getOperatorID() const {return operatorID;}
    std::string getName() const {return name;}
    std::string getOperatorStreetAddress() const {return operatorStreetAddress;}
    std::string getOperatorCityName() const {return operatorCityName;}
    std::string getOperatorStateAbbreviation() const {return operatorStateAbbreviation;}
    std::string getOperatorPostalCode() const {return operatorPostalCode;}
    Date getLocalDate() const {return localDate;}
    Time getLocalTime() const {return localTime;}
    std::string getCommodityReleasedType() const {return commodityReleasedType;}
    double getUnintentionalReleaseBbls() const {return unintentionalReleaseBbls;}
    double getIntentionalReleaseBbls() const {return intentionalReleaseBbls;}
    double getRecoveredBbls() const {return recoveredBbls;}
    std::string getIgniteInd() const {return igniteInd;}
    std::string getExplodeInd() const {return explodeInd;}
    Date getPreparedDate() const {return preparedDate;}
    std::string getAuthorizerName() const {return authorizerName;}
    std::string getAuthorizerEmail() const {return authorizerEmail;}
    char getIncidentCode() const {return incidentCode;}

/*********************
 * Mutator functions *
 *********************/
    void setReportReceivedDate( Date value ) {reportReceivedDate=value;}
    void setReportNumber( std::string value ) {reportNumber=value;}
    void setSupplementalNumber( std::string value ) {supplementalNumber=value;}
    void setReportType( std::string value ) {reportType=value;}
    void setOperatorID( std::string value ) {operatorID=value;}
    void setName( std::string value ) {name=value;}
    void setOperatorStreetAddress( std::string value ) {operatorStreetAddress=value;}
    void setOperatorCityName( std::string value ) {operatorCityName=value;}
    void setOperatorStateAbbreviation( std::string value ) {operatorStateAbbreviation=value;}
    void setOperatorPostalCode( std::string value ) {operatorPostalCode=value;}
    void setLocalDate( Date value ) {localDate=value;}
    void setLocalTime( Time value ) {localTime=value;}
    void setCommodityReleasedType( std::string value ) {commodityReleasedType=value;}
    void setUnintentionalReleaseBbls( double value ) {unintentionalReleaseBbls=value;}
    void setIntentionalReleaseBbls( double value ) {intentionalReleaseBbls=value;}
    void setRecoveredBbls( double value ) {recoveredBbls=value;}
    void setIgniteInd( std::string value ) {igniteInd=value;}
    void setExplodeInd( std::string value ) {explodeInd=value;}
    void setPreparedDate( Date value ) {preparedDate=value;}
    void setAuthorizerName( std::string value ) {authorizerName=value;}
    void setAuthorizerEmail( std::string value ) {authorizerEmail=value;}
    void setIncidentCode( char value ) {incidentCode=value;}
    
/************************
 * Overloaded Operators *
 ************************/
    bool operator<(const HazMat7k &h) {return this->reportNumber < h.reportNumber;}
    bool operator>=(const HazMat7k &h) {return this->reportNumber >= h.reportNumber;}
};



/*****************************************************
 *                                                   *
 *            Derived Class Declarations             *
 *                                                   *
 *****************************************************/

/**********************
 * LossOrDamage class *
 **********************/
class LossOrDamage: public HazMat7k
{
public:
/************************
 * Various Constructors *
 ************************/

    //Default constructor
    LossOrDamage();
    
    //Convert constructor
    LossOrDamage(const HazMatData &h);
    
};


/**************************
 * FatalityOrInjury class *
 **************************/
class FatalityOrInjury: public HazMat7k
{
    friend std::ostream& operator<<(std::ostream &os, const HazMat7k &h);
    //Outputs all the data from the object on one line
    
private:
    //data members unique to this class
    int fatal;
    int injure;
    std::string narrative;
    
public:
/************************
 * Various Constructors *
 ************************/

    //Default constructor
    FatalityOrInjury();
    
    //Convert constructor
    FatalityOrInjury(const HazMatData& h);

/********************
 * Member Functions *
 ********************/

    //Overriden summaryReport function
    void summaryReport() const;
    //Needed to change the format for the two new data members
    
/**********************
 * Accessor functions *
 **********************/
    int getFatal() const {return fatal;}
    int getInjure() const {return injure;}
    std::string getNarrative() const {return narrative;}

/*********************
 * Mutator functions *
 *********************/
    void setFatal( int value ) {fatal = value;}
    void setInjure( int value ) {injure = value;}
    void setNarrative( std::string value ) {narrative = value;}


};
    
    


#endif
