#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N, M;
	cin >> N >> M;
	vector<int> coins(M);
	vector<long> sums(N+1, 0);

	for(int i = 0; i < M; ++i)
		cin >> coins[i];

	sums[0] = 1;
	for(int i = 0; i < M; ++i) {
		for(int j = coins[i]; j <= N && j - coins[i] >= 0; ++j) {
			sums[j] += sums[j - coins[i]]; 
		}
	}

	cout << sums[N] << endl;

	return 0;
}