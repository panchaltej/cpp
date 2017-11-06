/*
 * Spirals.cpp
 *
 *  Created on: Sep 14, 2017
 *  Author: Tejas Panchal
 */

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number

/***** Complete this program. *****/

void do_spiral(const int n, const int start);

/**
 * The main: Generate and print spirals of various sizes.
 */
int main()
{
    do_spiral(1, 1);
    do_spiral(5, 1);
    do_spiral(9, 11);
    do_spiral(12, 13);
    do_spiral(15, 17);
}

void do_spiral(const int n, const int start){
	cout << "Spiral of size " << n << " starting at " << start << endl;

	if (n % 2 != 1){
		cout << "***** Error: Size " << n << " must be odd." << endl << endl;
		return;
	}
	if(start > MAX_START || n > MAX_SIZE){
		cout << "***** Error: Starting value " << start << " < 1 or > " << MAX_START << endl << endl;
		return;
	}

	int arr[n][n]; // stores the spiral
	int temp = start; // stores cell number in a sequence of spiral

	arr[(n-1)/2][(n-1)/2] = start;//center cell gets the starting value

	for(int t = 1; t<=(n-1)/2; t++){
		arr[(n-1)/2][(n-1)/2 + t] = ++temp; //shifting columns to the right

		for(int s = 1; s <= t; s++){
			arr[(n-1)/2 - s][(n-1)/2 + t] = ++temp; //shifting rows upwards
		}

		for(int s = 1; s <= 2*t; s++){
			arr[(n-1)/2 - t][(n-1)/2 + t - s] = ++temp; //shifting columns to the left
		}

		for(int s = 1; s <= 2*t; s++){
			arr[(n-1)/2 - t + s][(n-1)/2 + t - 2*t] = ++temp;//shifting rows downwards
		}

		for(int s = 1; s <= 2*t +1; s++){
			arr[(n-1)/2 - t + 2*t][(n-1)/2 + t - 2*t + s] = ++temp;//shifting columns to the right
		}

		if(!(t == (n-1)/2)){
			for(int s = 1; s <= t-1; s++){
				arr[(n-1)/2 - t + 2*t - s][(n-1)/2 + t - 2*t + 2*t + 1] = ++temp; //completing a loop of the spiral
			}
		}
	}

	//Printing the spiral
	cout << endl;
	for(int i = 0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

}
