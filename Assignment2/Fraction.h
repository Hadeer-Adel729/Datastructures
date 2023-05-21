#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std;


class Fraction
{
    public:

        //Constructors and destructors
        Fraction();
        Fraction(int x , int y);
        virtual ~Fraction();

        //setters and getters
        void setDenominator(int demo);
        void setDivisor(int Div);
        int getDivisor();
        int getDenominator();

        //Helper Functions:
        int find_GCD(int x, int y);
        void reduceFraction();

/* * * * Operator Overloading * * * */

        //Addition and Subtraction
        Fraction operator+ (Fraction obj);
        Fraction operator-(Fraction obj);

        //Multiplication and Division
        Fraction operator*(Fraction obj);
        Fraction operator/(Fraction obj);

        //Comparison operators
        bool operator> (Fraction obj);
        bool operator< (Fraction obj);
        bool operator == (Fraction obj);
        bool operator<= (Fraction obj);
        bool operator>=(Fraction obj);

        //Read and Write
        friend istream & operator >> (istream &input, Fraction &obj);
        friend ostream & operator << (ostream &output,const Fraction  &obj);



    private:
    int denominator;
    int Divisor;
};

#endif // FRACTION_H
