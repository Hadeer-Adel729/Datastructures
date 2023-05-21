#ifndef PHONEDIRECTORY_H
#define PHONEDIRECTORY_H
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class PhoneDirectory
{
    public:

    PhoneDirectory();
    ~PhoneDirectory();

    vector<string>firstName;
    vector<string>lastName;
    vector<string>phonenumber;

    void setlast_Name(string LN);
    void setfirst_Name(string FN);
    void setphone_Number(string PN);
    string getfirst_Name();
    string getlast_Name();
    string getphone_Number();

    void Add_entry();
    void List_all_entries();
    void LookUp_phoneNumber();
    void Search_by_firstName();
    void Delete_Entry_by_firstNname();
    void Sort_Directory_By_Insertion_Sort();
    void Sort_Directory_By_Selection_Sort();


    protected:

    private:
        string first_Name;
        string last_Name;
        string phone_Number;
};

#endif // PHONEDIRECTORY_H
