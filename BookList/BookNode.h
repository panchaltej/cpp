/*
 * BookNode.h
 *
 *  Created on: Oct 18, 2017
 *      Author: Tejas Panchal
 *      012432680
 */

#ifndef BOOKNODE_H_
#define BOOKNODE_H_

#include "Book.h"

/**
 * A book node in a linked list.
 */
class BookNode
{
public:
    /**
     * Constructor.
     * @param book this node's book.
     */
    BookNode(Book book);

    BookNode(Book book, BookNode* nextBook);

    void set_next(BookNode* n);

    Book get_book();

    BookNode* get_next();

    /***** Complete this class. *****/

private:
    Book book;       // this node's book
    BookNode *next;  // link to the next node in the list
};

#endif /* BOOKNODE_H_ */

