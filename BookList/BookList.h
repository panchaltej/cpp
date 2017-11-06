/*
 * BookList.h
 *
 *  Created on: Oct 18, 2017
 *      Author: Tejas Panchal
 *      012432680
 */
#ifndef BOOKLIST_H_
#define BOOKLIST_H_

#include "BookNode.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

/**
 * A list of book nodes.
 */

class BookList
{
public:

    /**
     * Constructor.
     * @param name the name of this list.
     */
    BookList(const string name);

    /**
     * Print the list.
     */
    void print();

    //void push_front(Book b);

    void set_head(BookNode* n);

	BookNode* get_head();

	void set_tail(BookNode* n);


    /***** Complete this class. *****/

private:
    string name;      // name of this book list
    BookNode *head;   // head of the list of book nodes
    BookNode *tail;   // tail of the list of book nodes
};

#endif /* BOOKLIST_H_ */

