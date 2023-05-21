#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include "PhoneDirectory.h"

using namespace std;

int main()
{
    int test, test2;
    PhoneDirectory entry;
    while (true)
    {
        cout << "Choose from the list :" << endl ;
        cout << "--  --  --  --  --  -- " <<endl << endl;
        cout << "1. Add an Entry "<< endl;
        cout << "2. Delete an Entry " << endl;
        cout << "3. List All Entries" << endl;
        cout << "4. Sort All Entries" << endl;
        cout << "5. Look up a Phone number " << endl;
        cout << "6. Search by First name" << endl;
        cout << "7. Exit form this program" << endl << endl;

        cin >> test;

        if(test == 1)
        {
            entry.Add_entry();
        }
        else if(test == 2)
        {
            entry.Delete_Entry_by_firstNname();
        }
        else if(test == 3)
        {
            entry.List_all_entries();
        }
        else if(test == 4)
        {
            cout << "choose The Algorithm you want to sort whith :" << endl;
            cout << "1. Insertion Sort" << endl;
            cout << "2. Selection Sort" << endl << endl;
            cin >> test2;
            if (test2 == 1)
            {
                entry.Sort_Directory_By_Insertion_Sort();
            }
            else if(test2 == 2)
            {
                entry.Sort_Directory_By_Selection_Sort();
            }

        }
        else if(test == 4)
        {
            entry.LookUp_phoneNumber();
        }
        else if(test == 5)
        {
            entry.Search_by_firstName();
        }
        else
        {
            cout << "EXIT !.."<< endl;
            break;

        }
    }


    return 0;


}
