#include "FractionCalculator.h"
#include "Fraction.h"

FractionCalculator::FractionCalculator()
{
    //ctor
}

FractionCalculator::~FractionCalculator()
{
    //dtor
}
void FractionCalculator::calculator()
    {
        int x;
        while(true)
        {
            cout << "Welcome to Fraction_Calculator .. Choose Operation to perform: "<< endl<<endl;
            cout<<"1. Adding"<<endl;
            cout<<"2. Subtracting"<<endl;
            cout<<"3. Multiplication"<<endl;
            cout<<"4. Dividing"<<endl;
            cout<<"5. Reduce Fraction" << endl;
            cout<<"6. Exit"<<endl << endl;
            cout <<"------------------------------"<<endl;
            cin>>x;
            if(x==1)
            {
                Fraction f1,f2;
                cout<<"Enter First fraction " << endl << endl;
                cin>>f1;
                cout<<"Enter Second fraction "<< endl <<endl;
                cin>>f2;

                Fraction f3;
                f3 = f1+f2;

                cout<<"f1+f2= "<<f3<<endl;
                cout <<"------------------------------"<<endl;

            }
            else if(x==2)
            {
                Fraction f1,f2;
                cout<<"Enter First fraction " << endl << endl;
                cin>>f1;
                cout<<"Enter Second fraction "<< endl <<endl;
                cin>>f2;

                Fraction f3;
                f3 = f1-f2;
                cout<<"f1-f2= "<<f3<< endl;
                cout <<"------------------------------"<<endl;

            }
            else if(x==3)
            {
                Fraction f1,f2;
                cout<<"Enter First fraction " << endl << endl;
                cin>>f1;
                cout<<"Enter Second fraction "<< endl <<endl;
                cin>>f2;

                Fraction f3;
                f3 = f1*f2;

                cout<<"f1*f2= "<<f3<< endl;
                cout <<"------------------------------"<<endl;

            }
            else if(x==4)
            {
                Fraction f1,f2;
                cout<<"Enter First fraction " << endl << endl;
                cin>>f1;
                cout<<"Enter Second fraction "<< endl <<endl;
                cin>>f2;

                Fraction f3;
                f3 = f1/f2;
                cout<<"f1/f2= "<<f3<<endl;
                cout <<"------------------------------"<<endl;

            }
            else if(x==5)
            {
                Fraction f1;
                cout<<"Enter fraction " << endl << endl;
                cin>>f1;
                cout << "Reduced fraction = "<< f1<<endl << endl;
                cout <<"------------------------------"<<endl;
            }


            else
            {
                cout<<"Exit!"<<endl;
                cout <<"------------------------------"<<endl;
                break;

            }
        }
    }
