/*
 * BookList.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: Tejas Panchal
 *      012432680
 */

#include "BookList.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;


BookList::BookList(const string name)
    : name(name), head(nullptr), tail(nullptr)
{
    //create();
}

void BookList::print()
{
    /***** Complete this function. *****/
}

//void BookList::push_front(Book b)
//{
//   BookNode* new_node = new BookNode(b);
//   if(head == nullptr){
//      head = new_node;
//      tail = new_node;
//   }
//   else{
//      new_node->set_next(head);
//      head = new_node;
//   }
//}

void BookList::set_head(BookNode* n){
	head = n;
}

BookNode* BookList::get_head(){
	return head;
}
void BookList::set_tail(BookNode* n){
	tail = n;
}

/***** Complete this file. *****/



