/*
 * Node.cpp
 *
 *  Created on: Oct 23, 2017
 *      Author: Tejas Panchal
 *      012432680
 */

#include <iostream>
#include "Node.h"

using namespace std;

/***** Complete this file. *****/
long Node::constructor_count;
long Node::copy_count;
long Node::destructor_count;

Node::Node(const long the_value){
	value = the_value;
	constructor_count ++;
}

Node:: Node(const Node& other){
	*this = other;
	copy_count ++;
}

Node::  ~Node(){
	destructor_count ++;
}

long Node:: get_value() const{
	return value;
}

long Node:: get_constructor_count(){
	return constructor_count;
}

long Node:: get_copy_count(){
	return copy_count;
}

long Node:: get_destructor_count(){
	return destructor_count;
}

void Node:: reset(){
	copy_count = 0;
	constructor_count = 0;
	destructor_count = 0;
}

bool Node:: operator ==(const Node& other) const{
	if(value == other.value) return true;
	else return false;
}

bool Node:: operator  >(const Node& other) const{
	if(value > other.value) return true;
	else return false;
}

bool Node:: operator  >=(const Node& other) const{
	if(value >= other.value) return true;
	else return false;
}

bool Node:: operator  <=(const Node& other) const{
	if(value <= other.value) return true;
	else return false;
}

