/*
 * Word.cpp
 *
 *  Created on: Nov 6, 2017
 *      Author: Tejas Panchal
 */

#include <string>
#include "Word.h"
using namespace std;

/***** Modify this file as needed. *****/

Word::Word() : text(""), count(0) {}
Word::Word(string text) : text(text), count(1) {}

Word::~Word() {}

int Word::get_count(){
	return count;
}

void Word::set_count(){
	count++;
}

string Word::get_text(){
	return text;
}

bool Word:: operator  !=(const Word& other) const{
	if(text != other.text) return true;
	else return false;
}

bool Word:: operator  <(const Word& other) const{
	if(text < other.text) return true;
	else return false;
}

bool Word:: operator  ==(const Word& other) const{
	if(text == other.text) return true;
	else return false;
}



