/*
 * SortedList.cpp
 *
 *  Created on: Oct 23, 2017
 *      Author: Tejas Panchal
 *      012432680
 */

#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
}

int SortedList::size() const { return data.size(); }

bool SortedList::check()
{
    if (data.size() == 0) return true;

    list<Node>::iterator it = data.begin();
    list<Node>::iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

void SortedList::prepend(const long value)
{
    /***** Complete this function. *****/
	Node new_node = Node(value);
	list<Node>::iterator it = data.begin();
	data.insert(it, new_node);
}

void SortedList::append(const long value)
{
    /***** Complete this function. *****/
	Node new_node = Node(value);
	list<Node>::iterator it = data.end();
	data.insert(it, new_node);
}

void SortedList::remove(const int index)
{
    /***** Complete this function. *****/
	list<Node>::iterator it = data.begin();
	advance(it, index);
	it = data.erase(it);
}

void SortedList::insert(const long value)
{
    /***** Complete this function. *****/
	Node new_node = Node(value);
	list<Node>::iterator it = data.begin();

	// Ensure that each node is greater than the new node.
	while ((it != data.end()) && (*it <= new_node))
	{
		it++;
	}
	data.insert(it, new_node);
}

Node SortedList::at(const int index)
{
    /***** Complete this function. *****/
	list<Node>::iterator it = data.begin();
	advance(it, index);
	Node new_node = *it;
	return new_node;
}



