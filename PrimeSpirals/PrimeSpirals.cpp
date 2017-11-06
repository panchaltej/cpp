/*
 * PrimeSpirals.cpp
 *
 *  Created on: Sep 14, 2017
 *  Author: Tejas Panchal (012432680)
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_START = 50;   // maximum starting number

/***** Complete this program. *****/

void do_prime_spiral(const int n, const int start);

/**
 * The main: Generate and print prime spirals of various sizes.
 */
int main()
{
    do_prime_spiral(5, 1);
    do_prime_spiral(25, 11);
    do_prime_spiral(35, 0);
    do_prime_spiral(50, 31);
    do_prime_spiral(101, 41);
}

void do_prime_spiral(const int n, const int start){
	cout << "Prime spiral of size " << n << " starting at " << start << endl;
	if (n % 2 != 1){
		cout << "***** Error: Size " << n << " must be odd." << endl << endl;
		return;
	}
	if(start > MAX_START || start < 1) {
		cout << "***** Error: Starting value " << start << " < 1 or > " << MAX_START << endl << endl;
		return;
	};


	//Generating Vector of prime numbers
	vector<bool> p;
	vector<int> prime; //Vector holding prime numbers
	p.resize(n*n);

	//Getting prime numbers using The Sieve of Eratosthenes
	for(int i = 0; i < n*n + start; i++){
		p[i] = true;
	}
	for(int j = 2; j<n*n + start; j++){
		if(p[j] == true){
			if(j >= start)
			prime.push_back(j);
			int multiple = 0;
			int t =2;
			while(multiple < n*n + start){
				multiple = j * t;
				if(multiple < n*n + start){
					p[multiple] = false; //only elements with index of prime numbers will remain true.
				}
				t++;
			}
		}
	}


	vector< vector<char> > v;//2D vector to hold spiral
	v.resize(n);
	int temp = start; // cell number starting from the center of the spiral

	//assigning '.' to all the elements
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			v[i].resize(n);
			v[i][j] = '.';
		}
	}

	//assigning '#' to prime elements
	if(find(prime.begin(), prime.end(), temp) != prime.end())
	v[(n-1)/2][(n-1)/2] = '#';
	for(int t = 1; t<=(n-1)/2; t++){
			temp++;
			if(find(prime.begin(), prime.end(), temp) != prime.end())
			v[(n-1)/2][(n-1)/2 + t] = '#';

			for(int s = 1; s <= t; s++){
				temp++;
				if(find(prime.begin(), prime.end(), temp) != prime.end())
				v[(n-1)/2 - s][(n-1)/2 + t] = '#';
			}

			for(int s = 1; s <= 2*t; s++){
				temp++;
				if(find(prime.begin(), prime.end(), temp) != prime.end())
				v[(n-1)/2 - t][(n-1)/2 + t - s] = '#';
			}

			for(int s = 1; s <= 2*t; s++){
				temp++;
				if(find(prime.begin(), prime.end(), temp) != prime.end())
				v[(n-1)/2 - t + s][(n-1)/2 + t - 2*t] = '#';
			}

			for(int s = 1; s <= 2*t +1; s++){
				temp++;
				if(find(prime.begin(), prime.end(), temp) != prime.end())
				v[(n-1)/2 - t + 2*t][(n-1)/2 + t - 2*t + s] = '#';
			}

			if(!(t == (n-1)/2)){
				for(int s = 1; s <= t-1; s++){
					temp++;
					if(find(prime.begin(), prime.end(), temp) != prime.end())
					v[(n-1)/2 - t + 2*t - s][(n-1)/2 + t - 2*t + 2*t + 1] = '#';
				}
			}
		}

	//printing spiral
	cout << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << v[i][j];
		}
		cout << endl;
	}
	cout << endl;

}


