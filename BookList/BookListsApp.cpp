/*
 * BookListsApp.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: Tejas Panchal
 *      012432680
 */
#include "Book.h"
#include "BookList.h"
#include "BookNode.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

const string CATEGORIES_FILE_NAME = "categories.txt";

//prints all the books from the list
void print(BookList *list, string name);

//inserts books into list in ascending order
void sortAndInsert(BookList *list, Book b);
/**
 * The main. Create and print the book lists.
 */
int main()
{
	string input_file_name;
	vector<string> Category;
	BookList *scienceList = new BookList("scienceList");
	BookList *historyList = new BookList("historyList");
	BookList *mysteryList = new BookList("mysteryList");
	BookList *childrensList = new BookList("childrensList");
	BookList *mergedList = new BookList("mergedList");
	BookList *author_A_M_List = new BookList("author_A_M_List");
	BookList *author_N_Z_List = new BookList("author_N_Z_List");

	input_file_name = "categories.txt";
	ifstream input;
	input.open(input_file_name.c_str(), fstream:: in);
	if (input.fail())
	{
		cout << "Failed to open " << input_file_name << endl;
		return -1;
	}
	/**
	 * Loop to read commands until the end of file.
	 */
	while (!input.fail())
	{
		string category;
		getline(input, category);

		Category.push_back(category);

	}
	input.close();

	//******SCIENCE********
	input_file_name = "science.txt";
	input.open(input_file_name.c_str(), fstream:: in);
	if (input.fail())
	{
		cout << "Failed to open " << input_file_name << endl;
		return -1;
	}
	/**
	 * Loop to read commands until the end of file.
	 */
	while (!input.fail())
	{
		Book b;
		input >> b;

		if(b.getIsbn() != ""){
			sortAndInsert(scienceList, b);
			sortAndInsert(mergedList, b);
			if((b.getLast()).compare("N")<0)
				sortAndInsert(author_A_M_List, b);
			else
				sortAndInsert(author_N_Z_List, b);
		}


	}
	input.close();

	print(scienceList, "science");

	//******HISTORY********
	input_file_name = "history.txt";
	input.open(input_file_name.c_str(), fstream:: in);
	if (input.fail())
	{
		cout << "Failed to open " << input_file_name << endl;
		return -1;
	}
	/**
	 * Loop to read commands until the end of file.
	 */
	while (!input.fail())
	{
		Book b;
		input >> b;
		if(b.getIsbn() != ""){
			sortAndInsert(historyList, b);
			sortAndInsert(mergedList, b);
			if((b.getLast()).compare("N")<0)
				sortAndInsert(author_A_M_List, b);
			else
				sortAndInsert(author_N_Z_List, b);
		}
	}
	input.close();

	print(historyList, "history");


	//******MYSTERY********
	input_file_name = "mystery.txt";
	input.open(input_file_name.c_str(), fstream:: in);
	if (input.fail())
	{
		cout << "Failed to open " << input_file_name << endl;
		return -1;
	}
	/**
	 * Loop to read commands until the end of file.
	 */
	while (!input.fail())
	{
		Book b;
		input >> b;
		if(b.getIsbn() != ""){
			sortAndInsert(mysteryList, b);
			sortAndInsert(mergedList, b);
			if((b.getLast()).compare("N")<0)
				sortAndInsert(author_A_M_List, b);
			else
				sortAndInsert(author_N_Z_List, b);
		}
	}
	input.close();

	print(mysteryList, "mystery");

	//******CHILDRENS********
	input_file_name = "childrens.txt";
	input.open(input_file_name.c_str(), fstream:: in);
	if (input.fail())
	{
		cout << "Failed to open " << input_file_name << endl;
		return -1;
	}
	/**
	 * Loop to read commands until the end of file.
	 */
	while (!input.fail())
	{
		Book b;
		input >> b;
		if(b.getIsbn() != ""){
			sortAndInsert(childrensList, b);
			sortAndInsert(mergedList, b);
			if((b.getLast()).compare("N")<0)
				sortAndInsert(author_A_M_List, b);
			else
				sortAndInsert(author_N_Z_List, b);
		}
	}
	input.close();

	print(childrensList, "childrens");


	print(mergedList, "MERGED");
	print(author_A_M_List, "AUTHORS A-M");
	print(author_N_Z_List, "AUTHORS N_Z");


    return 0;
}

void print(BookList *list, string name){

	cout << endl << "Book List: "<< name << endl << endl;
	int count = 0;
	BookNode* p = list->get_head();

	while (p != nullptr) // Check if already after the last element
	{
		Book element = p->get_book(); // Get the element to which iter points
		p=p->get_next(); // Move the iterator to the next element
		cout << element  << endl;
		count ++;
	}
	cout << "    ("<<count<<" books)" << endl;

}

void sortAndInsert(BookList *list, Book b){
	BookNode* new_node = new BookNode(b);
	bool flag = false;
	if(list->get_head() != nullptr){
		BookNode* p = list->get_head();


		//Check if the book is already present in the list
		if(b.getIsbn().compare((p->get_book()).getIsbn()) == 0) return;
		while (p->get_next() != nullptr) // Check if already after the last element
		{
			if(b.getIsbn().compare(((p->get_next())->get_book()).getIsbn()) == 0) return;
			p=p->get_next(); // Move the iterator to the next element
		}

		p = list->get_head();
		if(b.getIsbn().compare((p->get_book()).getIsbn()) < 0){
			new_node->set_next(list->get_head());
			list->set_head(new_node);

			return;
		}
		else if(p->get_next()!= nullptr){
			while(p->get_next() != nullptr){
				if((b.getIsbn().compare((p->get_next())->get_book().getIsbn()))<0){
					new_node->set_next(p->get_next());
					p->set_next(new_node);
					flag = true;
					break;
				}
				p=p->get_next();
			}
		}
		if(flag == false){
			new_node->set_next(p->get_next());
			p->set_next(new_node);
			list->set_tail(new_node);

			return;
		}
	}
	else{
		list->set_head(new_node);
		list->set_tail(new_node);

	}
}



