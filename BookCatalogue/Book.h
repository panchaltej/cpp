/*
 * Book.h
 *
 *  Created on: Oct 2, 2017
 *      Author: Tejas Panchal (012432680)
 */

#ifndef BOOK_H_
#define BOOK_H_

#include <string>
using namespace std;

/***** Complete this file. *****/

/**
 * The Book class.
 */
class Book
{
public:
    /**
     * Book categories.
     */
    enum class Category { FICTION, HISTORY, TECHNICAL, NONE };

    /**
     * Default constructor.
     */
    Book();

    /**
     * Constructor.
     */
    Book(string isbn, string last, string first, string title, Category category);

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
    Category category;
};

#endif /* EMPLOYEE_H_ */

