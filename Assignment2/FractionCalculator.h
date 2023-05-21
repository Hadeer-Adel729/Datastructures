#ifndef FRACTIONCALCULATOR_H
#define FRACTIONCALCULATOR_H
#include <iostream>
using namespace std;

class FractionCalculator
{
    public:

        //default constructor
        FractionCalculator();

        //destructor
        virtual ~FractionCalculator();

 //function that  allows the user to input a fraction and perform calculations by adding, subtracting, etc.
        void calculator();

    protected:

    private:
};

#endif // FRACTIONCALCULATOR_H
