/*
 * CalculatorApp.cpp
 *
 *  Created on: Oct 31, 2017
 *      Author: Tejas Panchal
 *      		012432680
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string.h>
#include <exception>
#include <stdexcept>
#include "Calculator.h"
#include "SyntaxError.h"

using namespace std;

/**
 * The main
 */
int main()
{
	string input = "";
	string exprsn = "";
	double answer = 0;
	do
	{
		cout << "Expression? ";
		getline(cin, input);
		if(input != ""){
			if(input.at(input.length()-1) != '='){
				if(input != ".")
					cout << "Expression must end with an =" << endl << endl;
			}
			else{
				exprsn = input.substr(0, input.length()-1);
				exprsn.erase(remove_if(exprsn.begin(), exprsn.end(), ::isspace), exprsn.end());

				Calculator* calc = new Calculator(exprsn);
				try{
					answer = calc->expression(exprsn);
				}
				catch(std::overflow_error e){
					cout << "***** Division by zero"<< endl << endl;
					continue;
				}
				catch (SyntaxError& ex) {
					cout << ex.what()<< endl << endl;
					continue;
				}
				cout << answer << endl << endl;
			}
		}
	}
	while (input != ".");

	cout << endl << "Done!";
}






