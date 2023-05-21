#include "PhoneDirectory.h"

PhoneDirectory::PhoneDirectory()
{
    //ctor
}

PhoneDirectory::~PhoneDirectory()
{
    //dtor
}
void PhoneDirectory::setfirst_Name(string FN)
{
    first_Name = FN;
}
void PhoneDirectory::setlast_Name(string LN)
{
    last_Name = LN;
}
void PhoneDirectory::setphone_Number(string PN)
{
    phone_Number = PN;
}
string PhoneDirectory::getfirst_Name()
{
    return first_Name;
}
string PhoneDirectory::getlast_Name()
{
    return last_Name;
}
string PhoneDirectory::getphone_Number()
{
    return phone_Number;
}
void PhoneDirectory::Add_entry()
{
    string f_Name ;
    cout << "Enter First Name   : ";
    cin >> f_Name;
    setfirst_Name(f_Name);
    firstName.push_back(getfirst_Name());
    cout << endl;

    string L_Name ;
    cout << "Enter Last Name    : ";
    cin >> L_Name;
    setlast_Name(L_Name);
    lastName.push_back(getlast_Name());
    cout << endl;

    string p_Number ;
    cout << "Enter Phone number : ";
    cin >> p_Number;
    setphone_Number(p_Number);
    phonenumber.push_back(getphone_Number());
    cout << endl;

    for(int i = 0 ; i < firstName.size(); i++)
    {
        cout << "Entry Added successfully ! .. And This its Info .." << endl << endl;
        cout << "Your Information  .." << endl;
        cout << "First Name   : "<<firstName[i]<<endl;
        cout << "Last name    : "<<lastName[i]<<endl ;
        cout << "Phone number : "<<phonenumber[i]<<endl << endl;
        cout << "*------------------------------------------------------------*"<< endl << endl;
    }
}



void PhoneDirectory::LookUp_phoneNumber()
{
    bool found = false ;
    string phone;
    cout << "Enter the Phone number you searching for : " << endl;
    cin >> phone;

    for(int i = 0 ; i < phonenumber.size(); i++)
    {
        if(phonenumber[i] == phone)
        {
            found = true;
            cout << "Entry is found and This its Info .."<< endl;
            cout << "First Name    : "<<firstName[i]<<endl;
            cout << "Last Name     : "<<lastName[i]<<endl ;
            cout << "Phone number : "<<phonenumber[i]<<endl << endl;
            cout << "*------------------------------------------------------------*"<< endl << endl;
        }
    }
    if(!found)
    {
        cout << "Entry Not Found !"<<endl<<endl ;
        cout << "------------------------------------------------------------"<< endl << endl;

    }
}

void PhoneDirectory::Search_by_firstName()
{
    string FIRSTNAME;
    bool found = false ;
    cout << "Enter the first name of Entry you searching for : " << endl ;
    cin >> FIRSTNAME;
    for(int i = 0 ; i < firstName.size(); i++)
    {
        if(firstName[i] == FIRSTNAME)
        {
            found = true;
            cout << "Entry is found and This its Info .."<< endl;
            cout << "First Name   : "<<firstName[i]<<endl;
            cout << "Last name    : "<<lastName[i]<<endl ;
            cout << "Phone number : "<<phonenumber[i]<<endl << endl;
            cout << "*------------------------------------------------------------*"<< endl << endl;
        }
    }
    if(!found)
    {
        cout << "Entry Not Found !"<<endl<<endl ;
        cout << "*-------------------------------------------------------*"<< endl << endl;
    }
}

void PhoneDirectory::Delete_Entry_by_firstNname()
{
    bool found = false ;
    string FIRSTNAME;
    cout << "Enter the First Name of the entry you want to delete: " << endl; ;
    cin >> FIRSTNAME;

    for(int i = 0 ; i < firstName.size(); i++)
    {
        if(firstName[i] == FIRSTNAME)
        {
            found = true;
            phonenumber.erase(phonenumber.begin()+i);
            firstName.erase(firstName.begin()+i);
            lastName.erase(lastName.begin()+i);
            cout << "Done! .. Entry is deleted successfuly" << endl << endl;
            cout << "*------------------------------------------------------------*"<< endl << endl;
            break;
        }
    }
    if(!found)
    {
        cout << "Entry Not Found !"<<endl<<endl ;
        cout << "*------------------------------------------------------------*"<< endl << endl;
    }

}

// List the directory in alphabetical order by first name

void PhoneDirectory::Sort_Directory_By_Insertion_Sort()
{
    //Using Insertion Sort.

    for (int i = 1, j; i < firstName.size(); i++)
    {
        string temp_first_name = firstName[i];
        string temp_last_name = lastName[i];
        string temp_phone_num = phonenumber[i];

        for (j = i; j > 0 && temp_first_name < firstName[j - 1]; j--)
        {
            firstName[j] = firstName[j - 1];
            lastName[j] = lastName[j - 1];
            phonenumber[j] = phonenumber[j - 1];
        }
        firstName[j] = temp_first_name;
        lastName[j] = temp_last_name;
        phonenumber[j] = temp_phone_num;
    }
    cout << endl << endl;
    cout << "Your Directory After Sorting :" << endl;
    for (int i = 0; i < firstName.size(); i++)
    {
        cout << "First Name   : " << firstName[i] << endl;
        cout << "Last Name    : " << lastName[i] << endl;
        cout << "Phone number : " << phonenumber[i] << endl;
        cout << endl;
    }
    cout << "*------------------------------------------------------------*"<< endl << endl;
}

//Function to print all Entries.
void PhoneDirectory::List_all_entries()
{
    cout << "All Entries in Phone Directory .." << endl << endl;
    for (int i = 0; i < firstName.size(); i++)
    {
        cout << "First Name   : " << firstName[i] << endl;
        cout << "Last Name    : " << lastName[i] << endl;
        cout << "Phone number : " << phonenumber[i] << endl;
        cout << endl;
    }
    cout << "*------------------------------------------------------------*"<< endl << endl;
}
// List the directory in alphabetical order by first name
void PhoneDirectory::Sort_Directory_By_Selection_Sort()

//using selection sort
{
    for (int i=0; i<firstName.size()-1; i++)
    {

        int Smallest = i;
        for (int j=i+1; j<firstName.size(); j++)
        {
            if (firstName[j] < firstName[Smallest])
            {

                Smallest = j;

            }

        }

        string temp_first_name = firstName[i];
        firstName[i] = firstName[Smallest];
        firstName[Smallest] = temp_first_name;


        string temp_last_name = lastName[i];
        lastName[i] = lastName[Smallest];
        lastName[Smallest] = temp_last_name ;


        string temp_phone_num = phonenumber[i];
        phonenumber[i] = phonenumber[Smallest];
        phonenumber[Smallest] = temp_phone_num;


    }
    cout << endl << endl;
    cout << "Your Directory After Sorting :" << endl;
    for (int i = 0; i < firstName.size(); i++)
    {
        cout << "First Name   : " << firstName[i] << endl;
        cout << "Last Name    : " << lastName[i] << endl;
        cout << "Phone number : " << phonenumber[i] << endl;
        cout << endl;
    }
    cout << "*------------------------------------------------------------*"<< endl << endl;

}

