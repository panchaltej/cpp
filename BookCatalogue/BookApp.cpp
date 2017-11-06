/*
 * BookApp.cpp
 *
 *  Created on: Oct 2, 2017
 *      Author: Tejas Panchal (012432680)
 */

#include "Book.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string.h>

/***** Complete this file. *****/

using namespace std;

// Status codes.
enum class StatusCode {OK, DUPLICATE, NOT_FOUND, INVALID_COMMAND};

/**
 * Find the book in the catalog with the given ISBN.
 * Using a binary search.
 * @param isbn the ISBN.
 * @param catalog the vector of book records.
 * @return the vector index of the book if found, else return -1.
 */
int find(const string isbn, vector<Book>& catalog);

const string INPUT_FILE_NAME = "commands.in";

/**
 * The main. Open the command input file and loop to process commands.
 */
int main()
{
    // Open the input file.
    ifstream input;
    input.open(INPUT_FILE_NAME.c_str(), fstream:: in);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    vector<Book> catalog;  // book catalog

    /**
     * Loop to read commands until the end of file.
     */
    while (!input.fail())
    {
    	char command = 'x';
		input >> command;
		if(command != 'x')
        cout << endl << command << " ";

		/*
		 * Command '+' adds a book in Catalog
		 */
        if(command == '+'){
        	Book b1;
			input >> b1;
        	int index = 0;
        	bool duplicate = false;
        	for(int j=0; j<catalog.size(); j++){
        		if(b1.getIsbn().compare(catalog[j].getIsbn()) == 0){
					duplicate = true;
        		}
        		if(b1.getIsbn().compare(catalog[j].getIsbn()) > 0){
        			index = j+1;
        		}
        	}
        	cout << "Inserted at index " << index <<": "<< b1 << endl;
        	if(duplicate) cout << "*** Duplicate ISDN ***"<< endl;
        	else catalog.insert(catalog.begin() + index, b1);
        }
        /*
		 * Command '-' removes a book from Catalog
		 */
        else if(command == '-'){
        	Book b1;
			input >> b1;
			bool removed = false;
        	for(int j=0; j<catalog.size(); j++){
        		if(b1.getIsbn().compare(catalog[j].getIsbn()) == 0){
        			removed = true;
        			cout << "Removed "<< catalog[j] << endl;
        			catalog.erase(catalog.begin() + (j));
        			break;
        		}
        	}
        	//If mentioned book is not found in catalog
        	if(removed == false){
        		cout << "Removed " << b1 << endl;
        		cout << "*** Book not found ***" << endl;
        	}

        }
        /*
		 * Command '?' Searches for a book with given criterion in Catalog
		 */
        else if(command == '?'){
        	string search;
        	getline(input, search);

        	int param = search.find('=');
        	string parameter = search.substr(0, param);
        	string searchVal = search.substr(param+1, search.length());

        	//Show all the books if no criterion given
        	if(search == ""){
        		cout << "All books in the catalog:" << endl;
        		for(int i =0; i< catalog.size(); i++){
					cout << catalog[i] << endl;
				}
        	}

        	//Show books of mentioned author
        	else if(parameter == " author"){
        		cout << "Books by author "<< searchVal<<":" << endl;
        		for(int i =0; i< catalog.size(); i++){
        			if(searchVal.compare(catalog[i].getLast()) == 0)
					cout <<catalog[i] << endl;
				}
        	}

        	//Show book with the mentioned ISBN
        	//Using binary search
        	else if(parameter == " isbn"){
        		cout << "Book with ISBN "<< searchVal<<":" << endl;
        		int index = find(searchVal, catalog);
        		if(index >= 0)
        		cout <<catalog[index] << endl;
			}

        	//Show books with mentioned Category
        	else if(parameter == " category"){
        		cout << "Books in category "<< searchVal<<":" << endl;
				for(int i =0; i< catalog.size(); i++){
					if(searchVal.compare(catalog[i].getCategory()) == 0)
					cout <<catalog[i] << endl;
				}
			}
		}
        else if(command == 'x'){}
        else{
        	cout << "*** Invalid command ***" << endl;
        	string temp;
        	getline(input, temp);
        }
    }
    return 0;
}

int find(const string isbn, vector<Book>& catalog){
	int low = 0;
	int high = catalog.size();
	string value = isbn;
	while (low <= high) {
	  int mid = (low + high)/2;

	  if (value.compare(catalog[mid].getIsbn()) == 0) {
		  return mid;
	  }
	  else if (value.compare(catalog[mid].getIsbn()) < 0) {
		  high = mid-1;
	  }
	  else {
		  low = mid+1;
	  }
	}
	return -1;
}

