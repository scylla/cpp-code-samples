#include <iostream>
#include <algorithm>
#include <vector>
#include <limits> 
#include <cmath>

using namespace std;

int main() {
	
	int N;
	cin >> N;
	vector<int> A;

	for(int i = 0;i < N; ++i){
		int k;
		cin >> k;
		A.emplace_back(k);
	}

	int p, q;
	cin >> p >> q;

	sort(A.begin(), A.end());

	int max_so_far = 0, result = p;
	for(int cur = p; cur <=q; ++cur) {
		int low = 0, high = N-1, best_res = A[N-1];
		
		while(high >= low){
			int mid = (low + high)/2;
			if(cur > A[mid]) {
				low = mid + 1;
			} else if(cur < A[mid]){
				high = mid - 1;
			} else {
				best_res = 0; 
				break;
			}
			int res = abs(A[mid] - cur);
			if(res < best_res) {
				best_res = res;
			}
			
		}

		if(best_res > max_so_far){
			result = cur;
			max_so_far = best_res;
		}

	}

	cout << result << endl;
	return 0;

}