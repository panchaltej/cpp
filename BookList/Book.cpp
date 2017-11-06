/*
 * Book.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: Tejas Panchal
 *      012432680
 */

/***** Complete this file. *****/

#include "Book.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

Book::Book() : isbn(""), last(""), first(""), title("")
{
}

Book::Book(string isbn, string last, string first, string title){
	this->isbn = isbn;
	this->last = last;
	this->first = first;
	this->title = title;
}

Book::~Book(){
	this->isbn = "";
	this->last = "";
	this->first = "";
	this->title = "";

}

const string Book::getIsbn(){
	return isbn;
}

const string Book::getLast(){
	return last;
}

istream& operator >>(istream& ins, Book& inputBook){
   string bookDetail;

   getline(ins, bookDetail);



   int isbn = bookDetail.find(','); // separating strings after ","
   inputBook.isbn = bookDetail.substr(0, isbn);


	   int last = bookDetail.find(',', isbn+1);
	   inputBook.last = bookDetail.substr(isbn+1, last-isbn-1);

	   int first = bookDetail.find(',', last+1);
	   inputBook.first = bookDetail.substr(last+1, first-last-1);

	   int title = bookDetail.find(',', first+1);
	   inputBook.title = bookDetail.substr(first+1);


   return ins;
}

ostream& operator <<(ostream& outs, const Book& inputBook){
	outs << "  Book{ISBN=" <<inputBook.isbn <<", last=" <<inputBook.last <<", first=" <<inputBook.first <<", title=" <<inputBook.title<<"}";
	return outs;
}


