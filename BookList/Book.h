/*
 * Book.h
 *
 *  Created on: Oct 18, 2017
 *      Author: Tejas Panchal
 *      012432680
 */

#ifndef BOOK_H_
#define BOOK_H_
#include <string>
using namespace std;

/**
 * The Book class.
 */
class Book
{

public:

    /**
     * Default constructor.
     */
    Book();

    /**
     * Constructor.
     */
    Book(string isbn, string last, string first, string title);

    /**
     * Destructor.
     */
    ~Book();

    /**
	 * Get ISBN
	 */
    const string getIsbn();

    /**
	 * Get Last Name of author
	 */
    const string getLast();

    /**
	 * Get Category of book
	 */
    const string getCategory();

    /**
	 * * Overloading operator >>
	 */
	friend istream& operator >>(istream& ins, Book& inputBook);

	/**
	 * * Overloading operator >>
	 */
	friend ostream& operator <<(ostream& outs, const Book& inputBook);

private:

    /***** Complete the private members. *****/
    string isbn;
    string last;
    string first;
    string title;
};

#endif /* BOOK_H_ */

