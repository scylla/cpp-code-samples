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

	int max_so_far = 0, result = p, best_diff = 0, diff = 0;
	for(int cur = p; cur <=q;) {

		int low = 0, high = N-1, pos = -1;
		int mid = 0;
		bool match = false;

		// search cur or next smaller number than cur		
		while(high >= low){
			mid = (low + high)/2;
			if(A[mid] == cur) {
				pos = mid;
				match = true;
				break;
			} else if(A[mid] < cur) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}

		if(A[mid] > cur && mid > 0) {
			pos = mid -1;
		} else pos = mid;
		
		cout << "pos :: " << pos << endl;
		cout << "cur :: " << cur << endl;
		if(pos + 1 < N) { // case 1
			int sol;
			if (A[pos] > cur) {
				cout << "case 1 -- 0" << endl;
				diff = A[pos] - cur;				
				if(diff > best_diff) {
					best_diff = diff;
					result = cur; 
				}
				cur = cur + diff;
			} else {
				cout << "case 1 -- 1" << endl;
				sol = (A[pos] + A[pos + 1])/2;
				diff = min(sol - A[pos], A[pos+1] - sol);
				cout << "diff :: " << diff << endl;
				
				if(diff > best_diff) {
					best_diff = diff;
					result = min(A[pos] + diff, A[pos + 1] - diff); 
				}
				cur = A[pos + 1] + diff + 1;
			}
		} else { // case 2
			cout << "case 2" << endl;
			diff = q - A[N-1];
			if(diff > best_diff) {
				best_diff = diff;
				result = q;
			}
			break;
		}
		
		cout << "next cur " << cur << endl;
		cout << "result " << result << "   best_diff " << best_diff << endl;
		diff = 0;

	}

	if(result > q) result = q;
	cout << result << endl;
	return 0;

}