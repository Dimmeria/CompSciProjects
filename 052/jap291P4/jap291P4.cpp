/*
 * jap291P4.cpp                               
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

//Inclusion of all the requisite objects
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include "DateTime.h"
#include "PHMSA7000.h"
#include "IncidentLog.h"
#include "LL.h"

using namespace std;


//function to load data from the provided file
void loadData (const string ifname, IncidentLog &logs, const char fType);


/*****************
 * Main function *
 *****************/
int main(int argc, char **argv) {
    
    //Checking if the user provided the correct number of arguments
    // and that the flag is provided properly. 
    // Throws an error if all of these conditions are not met
    try {
        if (argc != 3 || !argv[2][1] || argv[2][0] != '-') {
            throw runtime_error("Improper Args");
        }
    
        //Instantiating the IncidentLog to hold all of the data entries
        IncidentLog allLogs;
    
        //Creating a char that is the file type from the cmd line
        // argument
        char fType = argv[2][1];
         //!!!!MUST USE [2][1] AS [2][0] SHOULD BE A HYPHEN IF
         // PROGRAM WAS CALLED CORRECTLY!!!!
    
        if (fType == 'b') {
            //...output status message...
            cout << "Binary file type selected";
            cout << endl << endl;
            
            //...and attempt to load data from it...
            loadData(argv[1], allLogs, fType);
             //Loading data from the file
            
            //Timing the process
            ProcessTimer p1(clock());
            
            //Checking to see whether or not any records were added
            // and outputting if so
            if (allLogs.size() > 0) {
                //calling the function to display reports
                allLogs.displayReport();
            }
            
            //Letting it know the process ended
            p1.setTimeEnd(clock());
            
            //Outputting the process time
            cout << endl << endl;
            cout << p1 << endl << endl;
        }
        //Otherwise report lack of implementation
        else {
            cout << "Case: " << argv[2];
            cout << " currently not implemented";
            cout << "\n\nExiting Now" << endl;
        }
    } 
    //Catching out of range errrors from possible over index
    catch(out_of_range) {
        cout << "LL index out of range" << endl;
        cout << "Exiting now.";
        cout << endl << endl;
    }
    //Handling user defined runtime errors
    catch(exception &e) {
        //Defining the errors being caught here
        string file_fail = "File_Fail";
        string improper_args = "Improper Args";
        
        //Block to handle to te invalid_argument throw statement in first if clause
        // Outputs an error message to the console and exits
        if (!improper_args.compare(e.what())) {
            cout << "Error: Wrong Number of arguments provided or improper flag identified.";
            cout << endl << endl;
            cout << "\tApplication expects execution as follows:" << endl;
            cout << "\texecutable <file_path> [-btf]" << endl;
            cout << "\t(Note flags must be preced by a '-')";
            cout << endl << endl;
        }
        
        //Block to handle if the file failed to open in loadData
        else if (!file_fail.compare(e.what())) {
            //Outputting error message if the file didn't open
            cout << "File failed to open! Check file: " << argv[1];
            cout << endl << endl;
            cout << "Exiting now.";
            cout << endl << endl;
        }
        else {
            cout << "Standard Error Message" << endl;
            cout << e.what() << endl;
            cout << "Thrown by driver or dependencies." << endl;
            cout << "Exiting" << endl;
            cout << endl;
        }
    }
    
    //End of main
    return 0;
} //End main



void loadData(const string ifname, IncidentLog& logs, const char fType)
{
    //Instantiating an input file stream
    fstream inFile;
    
    //A switch designed to determine the file type
    // and open the file with the correct protocol
    switch (fType) {
        //Binary file
        // **only type implemented thus far
        case 'b': {
            inFile.open(ifname.c_str(), ios::in | ios::binary);
            break;
        }
        default: {
            cout << "Unknown File type" << endl;
            break;
        }
    }
    
    //Checking that the file opened properly
    // and throwing an exception if not.
    try {
        if (!inFile) {
            //Throwing an error to be caught by the main function
            throw runtime_error("File_Fail");
        }
    } catch(exception& e) {
        //rethrowing to the main function
        throw;
    }
    
    /****************************************
     * If the file opened properly continue *
     ****************************************/
        
    //Instantiating a HazMat struct to serve as the data buffer
    HazMatData h;
        
    //Reading the first entry
    inFile.read(reinterpret_cast<char *>(&h), sizeof(h));
    
    //Looping through the rest of the file
    // and extracting the data entries
    while (!inFile.eof()) {
            
        //Calling the copy constructor of the correct object on the buffer
        // and appending it to the vectors
        if (h.injure || h.fatal) {
            FatalityOrInjury log(h);
            //Setting the incident code
            log.setIncidentCode('f');
            //Appending the created log object to the LL
            logs.appendObject(&log);
        }
            
        else {
            LossOrDamage log(h);
            //Setting the incident code
            log.setIncidentCode('l');
            //Appending the created log object to the LL
            logs.appendObject(&log);
        }
        
        //Reading the next entry into the buffer struct
        inFile.read(reinterpret_cast<char *>(&h), sizeof(h));
    }
    
    //Closing the file after the use of it is through
    inFile.close();
    
} //End loadData



