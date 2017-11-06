/*
 * BookNode.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: Tejas Panchal
 *      012432680
 */

#include "BookList.h"
#include "Book.h"
#include "BookNode.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;


BookNode::BookNode(Book book)
    : book(book), next(nullptr)
{

}

BookNode::BookNode(Book book, BookNode* nextBook)
    : book(book), next(nextBook)
{

}

void BookNode::set_next(BookNode* n){
	next = n;
}

Book BookNode::get_book(){
	return book;
}
BookNode* BookNode::get_next(){
	return next;
}





