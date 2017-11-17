/*
 * WordVector.cpp
 *
 *  Created on: Nov 6, 2017
 *      Author: Tejas Panchal
 *      		012432680
 */

#include <iostream>
#include <vector>
#include <string>
#include "WordVector.h"

/***** Complete this file. *****/

using namespace std;

WordVector::WordVector()
{
    /***** Complete this member function. *****/
}

WordVector::~WordVector()
{
    /***** Complete this member function. *****/
}

Word *WordVector::insert(const string text)
{
    /***** Complete this member function. *****/
	Word w = Word(text);

	vector<Word>::iterator it = data.begin();
	while ((it != data.end()) && (it->get_text() < text))
	{
		it++;
	}
	if(it != data.end()){
		if(it->get_text() == text){
			it->set_count();
		}
		else{
			data.insert(it, w);
		}
	}
	else{
		data.push_back(w);
	}
}

Word *WordVector::search(const string text)
{
    /***** Complete this member function. *****/

	int low = 0;
	int high = data.size()-1;

	while(low <= high){
		int mid = (low+high)/2;

		if(data[mid].get_text() == text) return &data[mid];
		else if(data[mid].get_text() > text) high = mid-1;
		else low = mid+1;
	}
	return nullptr;

}

int WordVector::get_size(){
	return data.size();
}

vector<Word> WordVector::get_data(){
	return data;
}



