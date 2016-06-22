#include <iostream>
#include <algorithm>
#include <vector>
#include <limits> 
#include <cmath>

using namespace std;

void predictWinner(int N) {

	vector<char> A(N+1 , 't');
	int sqrt_n = static_cast<int> (sqrt(N));

	// mark primes as p and their multiples as m
	for(int i = 2; i <= N; ++i) {
		if(A[i] == 't') {
			A[i] = 'p';
			if(i <= sqrt_n) {
				for(int j = i*i; j <= N; j += i) {
					A[j] = 'm';
				}
			}
		}
	}

	// mark powers of primes as x
	for(int i = 2;i <= N; ++i) {
		if(i <= sqrt_n) {
			for(long j = i*i; j <= N; j *= i) {
					A[j] = 'x';
			}
		}
	}

	// vector of losing indexes
	vector<int> losers;

	if(N >= 6)
		losers.emplace_back(6);

	A[6] = 'l';

	for(int i = 7; i <= N; ++i) {
		if(A[i] == 'm') {
			// check in losers array
			for(vector<int>::iterator it = losers.begin(); it != losers.end(); ++it) {
				if(A[i - *it] == 'x' or A[i - *it] == 'p') {
					A[i] = 'w';
					break;
				}
			}

			if(A[i] == 'm'){
				A[i] = 'l';
				losers.emplace_back(i);
			}
		}
	}

	if(A[N] == 'l') 
		cout << "Misha" << endl;
	else
		cout << "Chef" << endl; 
}

int main() {

	int T;
	cin >> T;

	while(T-- > 0) {
		int N;
		cin >> N;
		if(N <= 5)
			cout << "Chef" << endl;
		else
			predictWinner(N);
	}

}