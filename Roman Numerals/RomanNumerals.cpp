/**
  * Assignment 5 : Roman Numerals
  * Name : Tejas Panchal
  * SID : 012432680
*/

#include <iostream>
#include <cstdlib>
#include<string>
#include "RomanNumerals.h"

using namespace std;

RomanNumeral::RomanNumeral() : roman(""), decimal(0)
{
}

/***** Complete this class implementation. *****/

RomanNumeral::RomanNumeral(string rom)
{
	roman = rom;
	decimal = 0;
	this->to_decimal();
}

RomanNumeral::RomanNumeral(int dec)
{
	decimal = dec;
	roman = "";
	this->to_roman();
}

int RomanNumeral::get_decimal(){
   return decimal;
}

string RomanNumeral::get_roman(){
   return roman;
}

void RomanNumeral::to_roman(){
   string rom = "";
   int dec = decimal;
   if(dec >= 1000){     //'M' has an equivalent of 1000
      for(int i = 0; i<(dec/1000); i++){
         rom += "M";
      }
      dec %= 1000;
   }
   if(dec >= 900){
	   rom += "CM";
	   dec %= 900;
   }
   if(dec >= 500){
      rom += "D";       //'D' has an equivalent of 500
      dec %= 500;
   }
   if(dec < 500 && dec > 50){
      if(dec >= 400){
         rom += "CD";
         dec %= 100;
      }
      else if(dec >=100){     //'C' has an equivalent of 100
         for(int i=0; i < dec/100; i++){
            rom += "C";
         }
         dec %= 100;
      }
   }
   if(dec >= 50){    //'L' has an equivalent of 50
      rom += "L";
      dec %= 50;
   }
   if(dec < 50 && dec > 5){
      if(dec >= 40){
         rom += "XL";
         dec %= 10;
      }
      else if(dec >=10){      //'X' has an equivalent of 10
         for(int i=0; i < dec/10; i++){
            rom += "X";
         }
         dec %= 10;
      }
   }
   if(dec >= 9){
   	   rom += "IX";
   	   dec %= 9;
   }
   if(dec >= 5){     //'V' has an equivalent of 5
      rom += "V";
      dec %= 5;
   }
   if(dec < 5){
      if(dec >= 4){
         rom += "IV";
      }
      else{
         for(int i=0; i < dec; i++){
            rom += "I";       //'I' has an equivalent of 1
         }
      }
   }
   roman = rom;
}

void RomanNumeral::to_decimal(){
   int dec = 0;
   string rom = roman;
   for(int i = 0; i< rom.length(); i++){
      switch(rom.at(i)){
         case 'M':
            dec += 1000;
            break;
         case 'D':
        	 if(i != rom.length()-1){
				 if(rom.at(i+1)=='M')dec -= 500;
				 else dec += 500;
			 }
        	 else
        		 dec += 500;
            break;
         case 'C':
        	 if(i != rom.length()-1){
        		 if(rom.at(i+1)=='M' || rom.at(i+1)=='D')dec -= 100;
        		 else dec += 100;
        	 }
        	 else
        		 dec += 100;
            break;
         case 'L':
        	 if(i != rom.length()-1){
				 if(rom.at(i+1)=='M' || rom.at(i+1)=='D' || rom.at(i+1)=='C')dec -= 50;
				 else dec += 50;
			 }
        	 else
        		 dec += 50;
            break;
         case 'X':
        	 if(i != rom.length()-1){
        		 if(rom.at(i+1)=='L' || rom.at(i+1)=='C' || rom.at(i+1)=='D' || rom.at(i+1)=='M' )dec -= 10;
        		 else dec += 10;
        	 }
        	 else
        		 dec += 10;
            break;
         case 'V':
        	 if(i != rom.length()-1){
				if(rom.at(i+1)=='X' || rom.at(i+1)=='L' || rom.at(i+1)=='C' ||
				rom.at(i+1)=='D' || rom.at(i+1)=='M')dec -= 5;
				else dec += 5;
			 }
        	 else
        		 dec += 5;
            break;
         case 'I':
            if(i != rom.length()-1){
            	if(rom.at(i+1)=='V' || rom.at(i+1)=='X' || rom.at(i+1)=='L' || rom.at(i+1)=='C' ||
            			rom.at(i+1)=='D' || rom.at(i+1)=='M')dec -= 1;
            	else dec += 1;
            }
            else dec += 1;
            break;
      }
   }
   decimal = dec;
}

string operator +(const RomanNumeral& num1, const RomanNumeral& num2){
   int sum = 0;
   sum = num1.decimal + num2.decimal;
   RomanNumeral num = RomanNumeral(sum);
   return num.roman;
}

string operator -(const RomanNumeral& num1, const RomanNumeral& num2){
	int sub = 0;
   sub = num1.decimal - num2.decimal;
   RomanNumeral num = RomanNumeral(sub);
   return num.roman;
}

string operator *(const RomanNumeral& num1, const RomanNumeral& num2){
	int mul = 0;
   mul = num1.decimal * num2.decimal;
   RomanNumeral num = RomanNumeral(mul);
   return num.roman;
}

string operator /(const RomanNumeral& num1, const RomanNumeral& num2){
	int div = 0;
   div = num1.decimal / num2.decimal;
   RomanNumeral num = RomanNumeral(div);
   return num.roman;
}

bool operator ==(const RomanNumeral& num1, const RomanNumeral& num2){
   return (num1.decimal == num2.decimal);
}

bool operator !=(const RomanNumeral& num1, const RomanNumeral& num2){
   return (num1.decimal != num2.decimal);
}

ostream& operator <<(ostream& outs, const RomanNumeral& num2){
   outs << "[" <<num2.decimal <<":"<< num2.roman << "]";
   return outs;
}

istream& operator >>(istream& ins, RomanNumeral& num2){
   string rom;
   ins >> rom;
   num2.roman = rom;
   num2.to_decimal();
   return ins;
}
