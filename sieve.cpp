#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

void print_primes(int n) {
	vector<int> primes;
	deque<bool> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	
	for(int p = 2; p < n; ++p) {
		if(is_prime[p]) {
			primes.emplace_back(p);
			for(int j = p*p; j < n; j += p) {
				is_prime[j] = false;
			}
		}
	}

	for(int i = 0; i < primes.size(); ++i) {
		cout << primes[i] << " ";
	}

	cout << endl;

}

int main () {

	int T;
	cin >> T;
	int N;
	while(T-- > 0) {
		cin >> N;
		print_primes(N);
	}

}
