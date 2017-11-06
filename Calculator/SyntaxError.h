/*
 * SyntaxError.h
 *
 *  Created on: Nov 2, 2017
 *      Author: tejas
 */

#ifndef SYNTAXERROR_H_
#define SYNTAXERROR_H_

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string.h>
#include <exception>
#include <stdexcept>
#include "Calculator.h"

using namespace std;

class SyntaxError : public runtime_error
{
public:
   SyntaxError(const string& what);
};



#endif /* SYNTAXERROR_H_ */
