/*
 * Word.h
 *
 *  Created on: Nov 6, 2017
 *      Author: Tejas Panchal
 *      		012432680
 */

#ifndef WORD_H_
#define WORD_H_

#include <string>
using namespace std;

/***** Modify this file as needed. *****/

/**
 * A word entry consisting of a word text and a frequency count
 * for a concordance.
 */
class Word
{
public:
    /**
     * Default constructor.
     */
    Word();

    /**
     * Constructor.
     * Create a word entry with the given text. Initialize the count to 1.
     * @param text the text of the word.
     */
    Word(string text);

    /**
     * Destructor.
     */
    virtual ~Word();

    string get_text();

    int get_count();

    void set_count();

    bool operator  !=(const Word& other) const;

    bool operator  <(const Word& other) const;

    bool operator  ==(const Word& other) const;

private:
    string text;
    int count;
};

#endif /* WORD_H_ */



