/*
 *  LL.h                               
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

#ifndef Linked_List
#define Linked_List
#include <iostream>
#include <stdexcept>
#include "DateTime.h"
#include "PHMSA7000.h"


//The class template for a generic node
// Contains a pointer to another node 
// of the same type and a data member to
// cotain the information of the node
template <typename T>
class Node
{
private:
    
public:
    T info;
    Node<T> *next;
    
     //Default constructor
    Node(T=T(),Node<T>* = NULL);
     //Instantiates a default object
     // of the correct type and sets
     // next to null, if nothing is
     // supplied.
};


/****************************************************************************
 *                                                                          *
 *                   class LL_iterator declaration                          *
 *                                                                          *
 ****************************************************************************/

// new for P4
template <typename T>
class LL_iterator
{
    
private:
    Node<T> *current;
    //pointer to point to the current 
    //node in the linked list
    
public:
    
    LL_iterator();
    //default constructor
    //Postcondition: current = NULL;
    
    LL_iterator(Node<T> *ptr);
    //constructor with parameter
    //Postcondition: current = ptr;
    
    T& operator*();
    //overloaded dereferencing operator *
    //Postcondition: Returns the info contained in the node
    
    LL_iterator operator++();
    //overloaded pre-increment operator
    //Postcondition: The iterator is advanced to the next node in the linked list
    
    bool operator==(const LL_iterator &rhsObj) const;
    //overloaded equality operator
    //Postcondition: Returns true if this iterator is equal to the 
    //               iterator specified on the right hand side
    //               otherwise returns false
    
    bool operator!=(const LL_iterator &rhsObj) const;
    //overloaded equality operator
    //Postcondition: Returns true if this iterator is NOT equal to the 
    //               iterator specified on the right hand side       
    //               otherwise returns false
    
    LL_iterator operator=(const LL_iterator<T> &rhsObj);
    //overloaded assignment operator
    //Postcondition: Returns an iterator with current pointing at
    //              rhsObj.current
    
}; //END class LL_iterator 


//The class template for a generic single-linked list
// Contains a pointer to a node of the type it was
// created with and generic single linked list methods
template <typename T>
class LL
{
    template<typename F>
    friend std::ostream &operator<<(std::ostream &os, const LL<F> &);
     //Overloaded stream insertion for testing purposes
    
private:
    unsigned long count;
     //Data member to hold the number of objects
     // in the list
     
    Node<T> *head;
     //Pointer to the head of the list
    
    void copyList(const LL<T> &listToCopy);
     //Private method called by the =operator and the
     // copy constructor to ensure deep copy

public:
    LL();
     //Default constructor
     // Initializes the list with a null pointer and
     // a zero-d counter
    
    ~LL();
     //Destructor
     // Ensures all memory is deallocated
    
    LL(const LL<T> &otherLinkedList);
     //Copy constructor
    
    LL<T> &operator=(const LL<T> &rhsobj);
     //Overloaded assignment operator
    
    void push_back(T);
     //pushback functionality
     // Inserts given object at the end of the list
    
    void insert(T);
     //Inserts an obect in ascending order (smallest
     // to largest)
    
    void pop_back();
     //popback functionality
     // removes the last member of the list
    
    void clear();
     //Removes all components of the linked list and
     // deallocates memory
    
    unsigned long size() const { return count; }
     //Returns the size of the LL stored in count
     
    T &at(int ndx) const;
     //Returns a reference to the object at the given position
    
    LL_iterator<T> begin() const;
     //Returns an iterator pointing at the first node in the list
    
    LL_iterator<T> end() const;
     //Same as above but for the end of the list
    

};


/****************************************************************************
 ^^                                                                        ^^
 ^^            SPECIALIZED    class Node declaration                       ^^
 ^^                                                                        ^^
 ****************************************************************************/

// new for P4 (template specialization)
template <>
class Node<HazMat7k*>
{
public:
    HazMat7k *info;
    Node<HazMat7k*> *next;
    
    //specialized to dynamically allocate memory, we will
    //discuss in class why this would be prudent to do
    //(afterall, a pointer was passed in, so why allocate memory again?)
    Node(HazMat7k*, Node<HazMat7k*> *n = NULL);
    
    //specialization to deallocate memory
    ~Node();
    
}; //END declaration for template specialization of class Node



/****************************************************************************
 ^^^^                                                                    ^^^^
 ^^^^                      BEGIN                                         ^^^^
 ^^^^                                                                    ^^^^
 ^^^^       SPECIALIZED    class Node implementation                     ^^^^
 ^^^^                                                                    ^^^^
 ****************************************************************************/

// new for P4 (template specialization)
Node<HazMat7k*>::Node(HazMat7k *ptr7k, Node<HazMat7k*> *n)
{
    //cout << "inside specialized version of constructor Node() " << endl;
    
    HazMat7k *addMe = NULL;
    
    FatalityOrInjury *ptrFI = NULL;
    LossOrDamage *ptrLD = NULL;
    
    try
    {
        
        if ( ptr7k->getIncidentCode() == 'f')
        {
            ptrFI = static_cast<FatalityOrInjury*>(ptr7k);
            //cout << "allocating memory for FatalityOrInjury object" << endl;
            addMe = new FatalityOrInjury(*ptrFI);
        }
        
        else if ( ptr7k->getIncidentCode() == 'l' )
        {
            ptrLD = static_cast<LossOrDamage*>(ptr7k);
            //cout << "allocating memory for LossOrDamage object" << endl;
            addMe = new LossOrDamage(*ptrLD);
        }
        else
        {
            std::cout << "something went wrong inside specialized Node constructor with parameters\n";
            std::cout << "there was no match to the Incident Code, should be either f or l\n";
            std::cout << "see Milestone 4, changes required to the loadData function\n";
        }
        
        
        info = addMe;
        
        next = n;
    }
    catch (std::bad_alloc baErr)
    {
        throw;
    }
    catch (...)
    {
        throw std::string("unknown error in constructor of specialized Node class");
    }
}



// new for P4 (template specialization)
Node<HazMat7k*>::~Node()
{
    
    //cout << "inside specialized version of destructor ~Node() " << endl;
    delete info;
    
}

/****************************************************************************
 ^^^^                                                                    ^^^^
 ^^^^                       END                                          ^^^^
 ^^^^                                                                    ^^^^
 ^^^^       SPECIALIZED    class Node implementation                     ^^^^
 ^^^^                                                                    ^^^^
 ****************************************************************************/



/********************
 * Node constructor *
 ********************/
template<typename T> 
Node<T>::Node(T obj, Node<T> *p)
{
    info = obj;
    next = p;
}


/***********************************
 ***********************************
 **                               **
 **    LL method definitions      **
 **                               **
 ***********************************
 ***********************************/

/****************************************
 *  Constructor/Destructor/Assignment   *
 ****************************************/
template<typename T>
LL<T>::LL()
{
    head = NULL;
    count = 0;
} //End constructor

template<typename T> 
LL<T>::~LL()
{
    clear();
} //End destructor


template<typename T>
void LL<T>::copyList(const LL<T> &listToCopy)
{
    if (head != NULL) {
        clear();
    }
     //If this linked list is not empty make sure
     // to clear it out first
    
    //Try block to catch bad_alloc
    try {
        //Only do something more if the list to copy is
        // non-empty. Otherwise clearing the list is enough
        if (listToCopy.size() > 0) {
            head = new Node<T>(listToCopy.at(0));
             //creating a new node that is a copy of the
             // head of the passed list and setting it to
             // this list's head
            count = 1;
             //Setting the size of this list as only one
             // node has been added so far
    
            Node<T> *current = head;
             //Starting at the beginning of this list
    
            for(int i=1; i < listToCopy.size(); i++) {
        
                current->next = new Node<T>(listToCopy.at(i));
                 //We loop through and copy each element to its
                 // proper index
                count += 1;
        
                current = current->next;
            }
        }
    } catch(std::bad_alloc) {
        std::cout << "Allocation Error" << std::endl;
    }
} //End copyList

template<typename T>
LL<T>::LL(const LL<T> &otherLinkedList)
{
    head = NULL;
    count = 0;
    
    this->copyList(otherLinkedList);
} //End copy constructor

template<typename T>
LL<T>& LL<T>::operator=(const LL<T> &rhsobj)
{
    if(this != &rhsobj) {
        copyList(rhsobj);
    }
    
    return *this;
} //End overloaded assignment operator


/*************************************
 *       Manipulation methods        *
 *************************************/
template<typename T>
void LL<T>::push_back(T obj)
{
    Node<T> *current = head;
     //starting at the beginning of the list
     // we move through to the end
    
    //Excepting for bad_alloc
    try {
        if (current == NULL) {
            head = new Node<T>(obj);
        }
         //Handles if the list is empty
        else {
            while (current->next != NULL) {
                current = current->next;
            }
             //current is now pointing at the last node
             // in the list
     
            current->next = new Node<T>(obj);
             //Creating a new node at the end of the
             // list to contain the passed element
        }
        count += 1;
         //Incrementing the size accordingly
    } catch(std::bad_alloc) {
        std::cout << std::endl << "Allocation Error" << std::endl;
    }
    
} //End push_back

template<typename T> 
void LL<T>::insert(T obj)
{
    Node<T> *current = head;
     //Starting at the beginning
    
    //Excetping bad_alloc errors
    try {
        if (current == NULL) {
            head = new Node<T>(obj);
        } //Handling if the list is empty

/*******************************
 * ASSUMES ALREADY SORTED LIST *
 *******************************/
        else {
            if (obj < current->info) {
                head = new Node<T>(obj, current);
            }
             //Handling the case if it is smaller than the
             // first object in the list
            else {
                Node<T> *tcurrent;
                 //Creating a trailing ptr so that we can insert
                 // the new node before the first node that is 
                 // bigger than it
                while (current != NULL && obj >= current->info) {
                    tcurrent = current;
                    current = current->next;
                }
                 //If the value of the passed object is less
                 // than the current node in the list then it 
                 // should be inserted before it so we wait for
                 // that to happen and stop there
        
                tcurrent->next = new Node<T>(obj,current);
                 //We then create a new node to hold the info in
                 // the passed obj and make sure its ptr is pointing
                 // to the object its coming before
            }
        } //If the list is non-empty we can move into a normal algorithm
    
        count += 1;
         //Incrementing the size accordingly
    } catch(std::bad_alloc) {
        std::cout << std::endl << "Allocation error" << std::endl;
    }
    
} //End insert


template<typename T> 
void LL<T>::pop_back()
{
    Node<T> *current = head;
     //Starting at the beginning of the list
     // we move to just before the end
    Node<T> *tcurrent;
     //Creating a trailing pointer so that when
     // a node is deleted we can reassign the 
     // next pointer of the previous node
    
    //If the list is empty nothing needs be done
    // so we check that first
    if (current != NULL) {
        while (current->next != NULL) {
            tcurrent = current;
            current = current->next;
        }
         //current is now pointing at the last
         // node in the list
     
        delete current;
         //Deallocating the memory associated with the
         // last node
     
        tcurrent->next = NULL;
         //Making sure the next pointer isn't dangling
        
        current = NULL;
         //Making sure current isn't dangling
     
        count -= 1;
         //Adjusting the size accordingly
    }
} //End pop_back


template<typename T>
void LL<T>::clear()
{
    Node<T> *current = head;
     //Starting at the beginning
    
    Node<T> *advance;
     //We then make a pointer so that we don't
     // lose track of the LL when we delete
     // the current object
    
    head = NULL;
     //We then insure head is not dangling
    
    while (current != NULL) {
        advance = current->next;
         //Keeping track of the next node
         // in the list
        
        delete current;
        count -= 1;
         //Deallocating the current node and
         // adjusting the size accordingly
        
        current = advance;
         //moving to the next remaining node
    }
     //At this point the list should be empty
     // with only the head pointer left pointing
     // at NULL
} //End clear


/*********************************
 *        Querying methods       *
 *********************************/
template<typename T> 
T & LL<T>::at(int ndx) const
{
    int pos = 0;
     //integer to keep track of the index we are
     // currently at
    
    Node<T> *current = head;
     //If we are currently at 0 then we should be
     // pointing at the head of the list
    
    int absndx = 0;
     //Value to store the absolute index in case of
     // negative indices being passed
    
    if (ndx < 0) {
        absndx = this->size() + ndx;
    }
    else {
        absndx = ndx;
    }
     //If its a negative index get the corresponding
     // positive index, otherwise just continue
    
    if (absndx >= size() || absndx < 0) {
        throw std::out_of_range("Improper Index");
    }
     //throwing an out of range error if the index is
     // too big/small
    
    for(; pos < absndx; pos++) {
        current = current->next;
    }
     //We should now be pointing at the node at the
     // passed index so we can just return it
     
    return current->info;
} //End at


//Returns beginning iterator
template<typename T>
LL_iterator<T> LL<T>::begin() const
{
    LL_iterator<T> l(head);
    
    return l;
} //End begin


//Returns ending 
template<typename T> 
LL_iterator<T> LL<T>::end() const
{
    //Current pointer
    Node<T> *current;
    current = head;
    
    //Excepting an empty LL
    if (current != NULL) {
        while (current->next != NULL) {
            current = current->next;
        }
         //Should be pointing at the last one 
    }
    
    //Setting the iterator to the current
    LL_iterator<T> l(current);
    
    //returning it
    return l;
} //End end


/******************************
 *      friend function       *
 ******************************/
template<typename T>
std::ostream& operator<<(std::ostream &os, const LL<T> &rhsobj) 
{
    Node<T> *current = rhsobj.head;
    
    while (current != NULL) {
        os << current->info;
         //Output the info of the current node
        
        current = current->next;
         //Advancing to the next node
    }
     //All thats left is to return the output stream
    
    return os;
}


/*******************************************
 *******************************************
 **                                       **
 **      LL_iterator implementation       **
 **                                       **
 *******************************************
 *******************************************/

template<typename T> 
LL_iterator<T>::LL_iterator()
{
    current = NULL;
}

template<typename T> 
LL_iterator<T>::LL_iterator(Node<T>* ptr)
{
    current = ptr;
}

template<typename T> 
bool LL_iterator<T>::operator==(const LL_iterator<T>& rhsObj) const
{
    return (current == rhsObj.current);
}

template<typename T> 
bool LL_iterator<T>::operator!=(const LL_iterator<T>& rhsObj) const
{
    return (current != rhsObj.current);
}

template<typename T> 
LL_iterator<T> LL_iterator<T>::operator++()
{
    current = current->next;
    
    return *this;
}

template<typename T>
T & LL_iterator<T>::operator*()
{
    return (current->info);
}

template<typename T>
LL_iterator<T> LL_iterator<T>::operator=(const LL_iterator<T> &rhsObj)
{
    current = rhsObj.current;
    
    return *this;
}



#endif
