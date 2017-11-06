/*
 * Calculator.h
 *
 *  Created on: Oct 31, 2017
 *      Author: Tejas Panchal
 *      		012432680
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <string>
using namespace std;


/**
 * The Calculator class.
 */
class Calculator
{
public:

    /**
     * Default constructor.
     */
    Calculator();

    /**
     * Constructor.
     */
    Calculator(string expression);

    /**
     * Destructor.
     */
    ~Calculator();

    double expression(string &str);

    double term(string &str);

    double factor(string &str);

    /**
	 * Get expr
	 */
    const string getexpr();


private:

    string expr;
};




#endif /* CALCULATOR_H_ */
