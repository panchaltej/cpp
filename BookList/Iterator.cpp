///*
// * Iterator.cpp
// *
// *  Created on: Oct 19, 2017
// *      Author: tejas
// */
//#include "BookList.h"
//#include "Iterator.h"
//
//
//
//
//// Implement the following three member functions
//
///**
//   Tests whether this iterator is past the end of the list.
//*/
//bool Iterator::past_end() const
//{
//   return (position == nullptr);
//}
//
///**
//   Yields the element to which the iterator points.
//   This member function should not be called if the iterator
//   is past the end of the list.
//*/
//Book Iterator::get() const
//{
//   return position ->get_book();
//}
//
///*
//   Moves the iterator to the next element of the list or
//   past the end.
//   This member function should not be called if the iterator
//   is already past the end of the list.
//*/
//void Iterator::next()
//{
//   position = position->get_next();
//}
//
