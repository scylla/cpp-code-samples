#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

int main() {

	int N;
	cin >> N;
	vector<int> arr(N), results(N, 1);
	for(int i=0;i < N; ++i)
		cin >> arr[i];

	for(int i = 0; i < N-1; ++i) {
		if(arr[i] < arr[i+1])
			results[i+1] = results[i] + 1;
	}

	for(int i = N-1; i > 0; --i) {
		if(arr[i] < arr[i-1] && results[i-1] <= results[i])
			results[i-1] = results[i] + 1;
	}

	cout << accumulate(results.begin(), results.end(), 0l) << endl;
	return 0;

}