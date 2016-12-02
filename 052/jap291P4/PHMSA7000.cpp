/*
 *  PHMSA7000.cpp                                 
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




/****************************************
 *                                      *
 * Implementation file for the HazMat7k *
 *              object                  *
 *      and its derived classes         *
 *                                      *
 ****************************************/

//Including the string object and the header file
#include <iostream>
#include <string>
#include "PHMSA7000.h"


/************************
 * Various Constructors *
 ************************/

//Default Constructor
HazMat7k::HazMat7k()
{
    //Setting all the data members to default values
    reportReceivedDate.setDate(1861, 1, 1);
    reportNumber = "0";
    supplementalNumber = "0";
    reportType = "";
    operatorID = "";
    name = "";
    operatorStreetAddress = "";
    operatorCityName = "";
    operatorStateAbbreviation = "";
    operatorPostalCode = "";
    localDate.setDate(1861, 1, 1);
    localTime.setTime(0, 00);
    commodityReleasedType = "";
    unintentionalReleaseBbls = 0;
    intentionalReleaseBbls = 0;
    recoveredBbls = 0;
    igniteInd = "";
    explodeInd = "";
    preparedDate.setDate(1861, 1, 1);
    authorizerName = "";
    authorizerEmail = "";
    incidentCode = 'l';
}

    
//Convert Constructor
HazMat7k::HazMat7k(const HazMatData& h)
{
    //Setting all the data members to the values of the struct
    reportReceivedDate = h.report_received_date;
    reportNumber = h.report_number;
    supplementalNumber = h.supplemental_number;
    reportType = h.report_type;
    operatorID = h.operator_id;
    name = h.name;
    operatorStreetAddress = h.operator_street_address;
    operatorCityName = h.operator_city_name;
    operatorStateAbbreviation = h.operator_state_abbreviation;
    operatorPostalCode = h.operator_postal_code;
    localDate = h.local_date;
    localTime = h.local_time;
    commodityReleasedType = h.commodity_released_type;
    unintentionalReleaseBbls = h.unintentional_release_bbls;
    intentionalReleaseBbls = h.intentional_release_bbls;
    recoveredBbls = h.recovered_bbls;
    igniteInd = h.ignite_ind;
    explodeInd = h.explode_ind;
    preparedDate.setDate(h.prepared_date);
    authorizerName = h.authorizer_name;
    authorizerEmail = h.authorizer_email;
    incidentCode = 'l';
}

    
//Destructor
HazMat7k::~HazMat7k()
{
}

    
/********************
 * Member Functions *
 ********************/

//Summary report functions
void HazMat7k::summaryReport() const
{
    std::cout << "Report Number and Date:\t\t";
    std::cout << reportNumber << "\t";
    std::cout << reportReceivedDate << std::endl;
    
    std::cout << "Local Date and Time:\t\t";
    std::cout << localDate << "\t";
    std::cout << localTime << std::endl;
    
    std::cout << "Barrels unintentionally released:\t";
    std::cout << unintentionalReleaseBbls << std::endl;
    
    std::cout << "Barrels intentionally released:\t\t";
    std::cout << intentionalReleaseBbls << std::endl;
    
    std::cout << "Barrels recovered:\t\t\t";
    std::cout << recoveredBbls << std::endl;
    
    std::cout << "commodity release type:\t";
    std::cout << commodityReleasedType << std::endl;
    
    std::cout << "authorizer email:\t";
    std::cout << authorizerEmail << std::endl;
    
    std::cout << std::endl;
}
//Outputs the objects data to the terminal
//  nicely formatted


//Stream Insertian operator
// Outputs all data fields on one line
std::ostream& operator<<(std::ostream &os, const HazMat7k &h)
{
    //Outputting all data members
    os << h.reportReceivedDate;
    os << h.reportNumber;
    os << h.supplementalNumber;
    os << h.reportType;
    os << h.operatorID;
    os << h.name;
    os << h.operatorStreetAddress;
    os << h.operatorCityName;
    os << h.operatorStateAbbreviation;
    os << h.operatorPostalCode;
    os << h.localDate;
    os << h.localTime;
    os << h.commodityReleasedType;
    os << h.unintentionalReleaseBbls;
    os << h.intentionalReleaseBbls;
    os << h.recoveredBbls;
    os << h.igniteInd;
    os << h.explodeInd;
    os << h.preparedDate;
    os << h.authorizerName;
    os << h.authorizerEmail;
    os << h.incidentCode;
    
    os << std::endl;
    
    return os;
}



/*******************************
 *                             *
 * LossOrDamage Implementation *
 *                             *
 *******************************/


/************************
 * Various Constructors *
 ************************/

//Default Constructor
LossOrDamage::LossOrDamage()
{
}

//Convert Constructor
LossOrDamage::LossOrDamage(const HazMatData& h):
HazMat7k(h)
{
}




/***********************************
 *                                 *
 * FatalityOrInjury Implementation *
 *                                 *
 ***********************************/

/************************
 * Various Constructors *
 ************************/

//Default constructor
FatalityOrInjury::FatalityOrInjury()
{
    fatal = 0;
    injure = 0;
    narrative = "";
}

    
//Convert constructor
FatalityOrInjury::FatalityOrInjury(const HazMatData& h):
HazMat7k(h)
{
    fatal = h.fatal;
    injure = h.injure;
    narrative = h.narrative;
}



/********************
 * Member Functions *
 ********************/

//Overriden summaryReport function
void FatalityOrInjury::summaryReport() const
{
    std::cout << "Report Number and Date:\t\t";
    std::cout << getReportNumber() << "\t";
    std::cout << getReportReceivedDate() << std::endl;
    
    std::cout << "Local Date and Time:\t\t";
    std::cout << getLocalDate() << "\t";
    std::cout << getLocalTime() << std::endl;
    
    std::cout << "Number of Injuries:\t";
    std::cout << injure << std::endl;
    
    std::cout << "Number of Fatalities:\t";
    std::cout << fatal << std::endl;
    
    std::cout << "Narrative Length:\t";
    std::cout << narrative.size() << std::endl;
    
    std::cout << "Narrative:   ";
    std::cout << narrative << std::endl;
    
    std::cout << std::endl;
}


