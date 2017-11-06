/**
  * Assignment 5 : Roman Numerals
  * Name : Tejas Panchal
  * SID : 012432680
*/

#include<string>
#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_

using namespace std;

class RomanNumeral
{
public:
    /**
     * Default constructor.
     */
    RomanNumeral();

    /**
     * constructor : creates object from string value
     */
    RomanNumeral(string roman);

    /**
     * constructor : creates object from integer value
     */
    RomanNumeral(int decimal);

    /**
     * Gets decimal value of the RomanNumeral object
     */
    int get_decimal();

    /**
     * Gets roman value of the RomanNumeral object
     */
    string get_roman();

    /**
     * Overloading operator + to perform addition on roman numbers
     */
    friend string operator +(const RomanNumeral& num1, const RomanNumeral& num2);

    /**
     * Overloading operator - to perform subtraction on roman numbers
     */
    friend string operator -(const RomanNumeral& num1, const RomanNumeral& num2);

    /**
     * Overloading operator * to perform multiplication on roman numbers
     */
    friend string operator *(const RomanNumeral& num1, const RomanNumeral& num2);

    /**
     * Overloading operator / to perform division on roman numbers
     */
    friend string operator /(const RomanNumeral& num1, const RomanNumeral& num2);

    /**
     * Overloading operator == to compare two roman numbers
     */
    friend bool operator ==(const RomanNumeral& num1, const RomanNumeral& num2);

    /**
     * Overloading operator != to perform inequality check on roman numbers
     */
    friend bool operator !=(const RomanNumeral& num1, const RomanNumeral& num2);

    /**
     * Overloading operator << to print Roman Numerals in specified format
     */
    friend ostream& operator <<(ostream& outs, const RomanNumeral& num2);

    /**
     * * Overloading operator >>
     */
    friend istream& operator >>(istream& ins, RomanNumeral& num2);

private:

    string roman; //stores number in Roman Numeral
    int decimal;  //stores number in decimal format

    /**
     * Converts decimal to roman format and stores in roman private variable
     */
    void to_roman();

    /**
     * * Converts roman to decimal format and stores in decimal private variable
     */
    void to_decimal();
};

#endif /* ROMANNUMERAL_H_ */
