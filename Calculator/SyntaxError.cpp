/*
 * SyntaxError.cpp
 *
 *  Created on: Nov 2, 2017
 *      Author: tejas
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string.h>
#include <exception>
#include <stdexcept>
#include "SyntaxError.h"

SyntaxError::SyntaxError(const string& what):runtime_error(what) {};



