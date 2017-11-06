/*
 * SortedVector.cpp
 *
 *  Created on: Oct 23, 2017
 *      Author: Tejas Panchal
 *      012432680
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector()
{
    Node::reset();
}

SortedVector::~SortedVector()
{
    Node::reset();
}

int SortedVector::size() const { return data.size(); }

bool SortedVector::check() const
{
    if (data.size() == 0) return true;

    vector<Node>::const_iterator it = data.begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }
    return it == data.end();  // Good if reached the end.
}

void SortedVector::prepend(const long value)
{
    /***** Complete this function. *****/
//	Node new_node = Node(value);
//	vector<Node>::iterator it = data.begin();
	data.insert(data.begin(), Node(value));
}

void SortedVector::append(const long value)
{
    /***** Complete this function. *****/
	Node new_node = Node(value);
//	vector<Node>::iterator it = data.end();
//	data.insert(it, new_node);
	data.push_back(new_node);
}

void SortedVector::remove(const int index)
{
    /***** Complete this function. *****/
	vector<Node>::iterator it = data.begin();
	advance(it, index);
	data.erase(it);
}

void SortedVector::insert(const long value)
{
    /***** Complete this function. *****/
	Node new_node = Node(value);
	vector<Node>::iterator it = data.begin();
	while ((it != data.end()) && (*it <= new_node))
	{
		it++;
	}
	data.insert(it, new_node);
}

Node SortedVector::at(const int index) const
{
    /***** Complete this function. *****/
//	vector<Node>::iterator it = data.begin();
//	advance(it, index);
//	Node new_node = *it;
	return data[index];
}



