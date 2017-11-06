/*
 * Book.cpp
 *
 *  Created on: Oct 2, 2017
 *      Author: Tejas Panchal (012432680)
 */
#include "Book.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

Book::Book() : isbn(""), last(""), first(""), title(""), category()
{
}

Book::Book(string isbn, string last, string first, string title, Category category){
	this->isbn = isbn;
	this->last = last;
	this->first = first;
	this->title = title;
	this->category = category;
}

Book::~Book(){
	this->isbn = "";
	this->last = "";
	this->first = "";
	this->title = "";
	this->category = Book::Category::NONE;
}

const string Book::getIsbn(){
	return isbn;
}

const string Book::getLast(){
	return last;
}

const string Book::getCategory(){
	if(category == Book::Category::TECHNICAL) return "technical";
	else if(category == Book::Category::HISTORY) return "history";
	else if(category == Book::Category::FICTION) return "fiction";
	else return "none";
}

istream& operator >>(istream& ins, Book& inputBook){
   string bookDetail;

   getline(ins, bookDetail);

   int n = std::count(bookDetail.begin(), bookDetail.end(), ','); // n > 1 specifies that the command is to add

   int isbn = bookDetail.find(','); // separating strings after ","
   inputBook.isbn = bookDetail.substr(1, isbn-1);

   inputBook.category = Book::Category::NONE; // default category to be NONE

   if(n>1){
	   int last = bookDetail.find(',', isbn+1);
	   inputBook.last = bookDetail.substr(isbn+1, last-isbn-1);

	   int first = bookDetail.find(',', last+1);
	   inputBook.first = bookDetail.substr(last+1, first-last-1);

	   int title = bookDetail.find(',', first+1);
	   inputBook.title = bookDetail.substr(first+1, title-first-1);

	   string cat = bookDetail.substr(title+1);
	   if(cat == "technical")
		   inputBook.category = Book::Category::TECHNICAL;
	   else if(cat == "fiction")
		   inputBook.category = Book::Category::FICTION;
	   else if(cat == "history")
		   inputBook.category = Book::Category::HISTORY;
	   else
		   inputBook.category = Book::Category::NONE;
   }
   return ins;
}

/**
 * Overloading << to print the enum Category as string
 */
ostream& operator <<(ostream& outs, Book::Category category){
	string temp;
	if(category == Book::Category::TECHNICAL) temp = "technical";
	else if(category == Book::Category::HISTORY) temp = "history";
	else if(category == Book::Category::FICTION) temp = "fiction";
	else temp = "none";
	outs << temp;
	return outs;
}

ostream& operator <<(ostream& outs, const Book& inputBook){
	outs << "Book{ISBN=" <<inputBook.isbn <<", last=" <<inputBook.last <<", first=" <<inputBook.first <<", title=" <<inputBook.title << ", category=" << inputBook.category<<"}";
	return outs;
}

