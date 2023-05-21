#include "Fraction.h"


Fraction::Fraction()
{
    //ctor
}

Fraction::~Fraction()
{
    //dtor
}
Fraction:: Fraction(int x , int y)
{
        Divisor = x;
        denominator= y;
        this->reduceFraction();
}
void Fraction:: setDenominator(int demo)
{
        denominator = demo;
}
void Fraction:: setDivisor(int Div)
{
        Divisor = Div;
}
int Fraction:: getDivisor()
{
        return Divisor;
}
int Fraction:: getDenominator()
{
        return denominator;
}
/*
Using GCD to find highest denominator
-We will calculate the greatest common divisor of both numbers.

-Divide both numbers by that gcd

-Set both variables as quotient after division.

-Lowest fraction will be Num1/Num2.
*/

int Fraction:: find_GCD(int x, int y)
{
        if (y == 0)
            return x;
        return find_GCD(y, x % y);
}
void Fraction:: reduceFraction()
{
        int c;
        c = find_GCD(Divisor,denominator);

        denominator/= c;
        Divisor/= c;
}


Fraction Fraction:: operator+ (Fraction obj)
{
        Fraction test;
        test.denominator = denominator*obj.denominator;
        test.Divisor = Divisor*obj.denominator+obj.Divisor*denominator;
        test.reduceFraction();
        return test;
}
Fraction Fraction:: operator-(Fraction obj)
{
        Fraction test;
        test.denominator = denominator*obj.denominator;
        test.Divisor = Divisor*obj.denominator-obj.Divisor*denominator;
        test.reduceFraction();
        return test;
}
Fraction Fraction:: operator*(Fraction obj)
{
        Fraction test;
        test.denominator = denominator*obj.denominator;
        test.Divisor = Divisor*obj.Divisor;
        test.reduceFraction();
        return test;
}
Fraction Fraction:: operator/(Fraction obj)
{
        Fraction test;
        test.denominator = denominator*obj.Divisor;
        test.Divisor = Divisor*obj.denominator;
        test.reduceFraction();
        return test;
}
bool Fraction:: operator> (Fraction obj)
{

        if(( float )Divisor/denominator >( float )obj.Divisor/obj.denominator)
            return 1 ;
        return 0;
}
bool Fraction:: operator< (Fraction obj)
{

        if(( float )Divisor/denominator<( float )obj.Divisor/obj.denominator)
            return 1 ;
        return 0;
}
bool Fraction:: operator == (Fraction obj)
{

        if (Divisor==obj.Divisor&&denominator==obj.denominator)
            return 1;
        return 0;


}
bool Fraction:: operator<= (Fraction obj)
{

        if(( float )Divisor/denominator<=( float )obj.Divisor/obj.denominator)
            return 1 ;
        return 0;
}
bool Fraction:: operator>=(Fraction obj)

{

        if(( float )Divisor/denominator>=( float )obj.Divisor/obj.denominator)
            return 1 ;
        return 0;
}
istream & operator >> (istream &input, Fraction &obj)
{
    cout<<"Enter nominator : " << endl;
    input>>obj.Divisor;
    cout << endl;
    cout<<"Enter dominator : " << endl;
    input>>obj.denominator;
    cout << endl;
    obj.reduceFraction();
    return input;
}

ostream & operator << (ostream &output,const Fraction  &obj)
{
    if (obj.denominator==0)
        output<<"You can't divide by 0"<<endl;
    else if (obj.Divisor==0)
        output<<0<<endl << endl;
    else if ((obj.denominator==0)&&(obj.Divisor==0))
        output << "Eror!! 0/0 is not defined .. " << endl;
    else if (obj.denominator==obj.Divisor)
        output<<1<<endl << endl;
    else
        output<<obj.Divisor<<"/"<<obj.denominator;
    return output;
}
