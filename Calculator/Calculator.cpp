/*
 * Calculator.cpp
 *
 *  Created on: Oct 31, 2017
 *      Author: Tejas Panchal
 *      		012432680
 */

#include "Calculator.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include "SyntaxError.h"

using namespace std;

Calculator::Calculator() : expr("")
{
}

Calculator::Calculator(string expression) : expr(expression)
{
}

Calculator::~Calculator()
{
}

double Calculator::expression(string &str){
	if(str.length()==0) return 0;
	else{
		double e1 = 0;
		double e2 = 0;

		e1 = term(str);
		char op;
		//Exception handling for incorrect syntex
		if(str.length() != 0){
			if(!(str.at(0) == '+' || str.at(0)=='-' || str.at(0)=='*'|| str.at(0)=='/'|| str.at(0)=='(' || str.at(0)=='E' || str.at(0)=='e' || isdigit(str.at(0)))) {
				string exc = str.substr(0,1);
				throw SyntaxError("***** Unexpected "+ exc);
			}
		}
		if(str.length() != 0 && (str.at(0) == '+' || str.at(0)=='-') ){
			while(str.length() != 0 && (str.at(0) == '-' || str.at(0)=='+') ){
				op = str.at(0);
				str = str.substr(1);
				e2 = term(str);
				if(op == '+') e1 = e1+e2;
				else e1 = e1-e2;
			}
			return e1;
		}
		else{
			return e1;
		}
	}
}

double Calculator::term(string &str){
	double t1 = 0;
	double t2 = 0;

	t1 = factor(str);
	char op;
	//calcuating multiplication or division
	if(str.length() != 0 && (str.at(0) == '*' || str.at(0)=='/') ){
		while(str.length() != 0 && (str.at(0) == '*' || str.at(0)=='/') ){
			op = str.at(0);
			str = str.substr(1);
			t2 = factor(str);
			if(op == '*') t1 = t1*t2;
			else {
				if(t2 == 0) throw std::overflow_error("***** Division by zero");
				else t1 = t1/t2;
			}
		}
		return t1;
	}
	else{
		return t1;
	}
}

double Calculator::factor(string &str){
	string number = "";

	//if the factor is a number
	if(isdigit(str.at(0)) || str.at(0) == 'E' || str.at(0) == 'e'){
		while(str.length() != 0 && (isdigit(str.at(0)) || str.at(0)=='.') ){
				number = number+str.at(0);
				str = str.substr(1);
		}
		if(str.length() != 0 && (str.at(0)=='E' || str.at(0)=='e')){
			str = str.substr(1);
			if(str.length() <= 1 || !(str.at(0) == '+' || str.at(0) == '-')) throw SyntaxError("Incorrect Syntax");
			if(str.at(0) == '+'){
				str = str.substr(1);
				double n = atof(number.c_str());
				double exp = atof((str.substr(0,1)).c_str());
				for(int i = 0; i<exp; i++){
					n = n*10;
				}
				return n;
			}
			else if(str.at(0) == '-'){
				str = str.substr(1);
				double n = atof(number.c_str());
				double exp = atof((str.substr(0,1)).c_str());
				for(int i = 0; i<exp; i++){
					n = n/10;
				}
				return n;
			}
		}
		return atof(number.c_str());//return number if it does not contain exponential part
	}
	//if the factor has another expression in brackets
	if(str.at(0) == '('){
		str = str.substr(1);
		int pos = str.find_last_of(')');
		if(pos == -1) throw SyntaxError("***** Missing )");
		string temp = str.substr(0,pos);
		str = str.substr(pos+1);
		double f1 = expression(temp);
		return f1;
	}
}

const string Calculator::getexpr(){
	return expr;
}




