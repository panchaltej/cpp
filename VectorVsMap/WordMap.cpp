/*
 * WordMap.cpp
 *
 *  Created on: Nov 6, 2017
 *      Author: Tejas Panchal
 *      		012432680
 */

#include <iostream>
#include <map>
#include <string>
#include "WordMap.h"

/***** Complete this file. *****/

using namespace std;

WordMap::WordMap()
{
    /***** Complete this member function. *****/
}

WordMap::~WordMap()
{
    /***** Complete this member function. *****/
}

Word *WordMap::insert(const string text)
{
    /***** Complete this member function. *****/
	Word w = Word(text);

	map<string, Word>::iterator it = data.begin();
	while ((it != data.end()) && (it->second < w))
	{
		it++;
	}
	if(it != data.end()){
		if(it->second == w){
			(it->second).set_count();
		}
		else{
			data.insert(pair<string, Word>(text, w));
		}
	}
	else{
		data.insert(pair<string, Word>(text, w));
	}
}

Word *WordMap::search(const string text)
{
    /***** Complete this member function. *****/
	map<string, Word>::iterator it = data.find(text);
	if(it != data.end()){
		return &(it->second);
	}
	else{
		return nullptr;
	}
}

int WordMap::get_size(){
	return data.size();
}

map<string, Word> WordMap::get_data() const{
	return data;
}



