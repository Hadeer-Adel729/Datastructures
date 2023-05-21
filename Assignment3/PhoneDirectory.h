#ifndef PHONEDIRECTORY_H
#define PHONEDIRECTORY_H
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class PhoneDirectory
{
    public:

    //constructor and destructor
    PhoneDirectory();
    ~PhoneDirectory();

    //// Create empty vectors
    vector<string>firstName;
    vector<string>lastName;
    vector<string>phonenumber;

    //setters and getters
    void setlast_Name(string LN);
    void setfirst_Name(string FN);
    void setphone_Number(string PN);
    string getfirst_Name();
    string getlast_Name();
    string getphone_Number();

    void Add_entry();

    //functions to List the directory
    void List_all_entries();

    //function to Lookup an entry by phone number
    void LookUp_phoneNumber();

    //function to Lookup an entry by first name
    void Search_by_firstName();

    //function to  Delete an entry by first name
    void  Delete_Entry_by_firstNname();

    //functions to sort the directory in alphabetical order by first name using Insertion sort
    void Sort_Directory_By_Insertion_Sort();

    //functions to sort the directory in alphabetical order by first name using Selection sort
    void Sort_Directory_By_Selection_Sort();


    protected:

    private:
        string first_Name;
        string last_Name;
        string phone_Number;
};

#endif // PHONEDIRECTORY_H
