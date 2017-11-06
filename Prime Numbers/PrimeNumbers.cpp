/*
 * PrimeNumbers.cpp
 *
 *  Created on: Sep 13, 2017
 *  Author: Tejas Panchal (012432680)
 */


#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_NUMBER = 1000;  // maximum possible prime number
const int ROW_SIZE   = 20;    // row size for printing

//if a number is prime, all the elements with index of multiples of prime number are set false
//only elements with prime number index will remain true after the loop executes
void compute_primes(bool a[], int alen);

//prints prime numbers, 20 numbers per row
void print_primes(bool a[], int alen);

/***** Complete this program. *****/

/**
 * The main: Compute and print the prime numbers up to MAX_NUMBER.
 */
int main()
{
	bool arr[MAX_NUMBER];

	//setting all the elements to true
	for(int i = 0; i< MAX_NUMBER; i++){
		arr[i] = true;
	}
	compute_primes(arr, sizeof(arr));
	print_primes(arr, sizeof(arr));
}

void compute_primes(bool a[], int alen){
	for(int j = 2; j<MAX_NUMBER; j++){
		if(a[j] == true){
			int multiple = 0;
			int t =2;
			while(multiple < MAX_NUMBER){
				multiple = j * t;
				if(multiple < MAX_NUMBER){
					a[multiple] = false; //only elements with index of prime numbers will remain true.
				}
				t++;
			}
		}
	}
}

void print_primes(bool a[], int alen){
	int prime_count = 0; //count of prime numbers
	for(int i = 2; i<MAX_NUMBER; i++){
		if(a[i] == true){
			prime_count ++;
			if(prime_count % 20 == 0) cout << setw(3) << i << " " << endl;
			else cout << setw(3) << i << " ";
		}
	}
	cout << endl << endl << "Done!";
}

