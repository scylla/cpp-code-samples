#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> matrix;

	// read matrix
	for(int i = 0; i < N; ++i) {
		vector<int> cur_row;
		for(int j = 0; j < M; ++j) {
			int k;
			cin >> k;
			cur_row.emplace_back(k);
		}
		matrix.emplace_back(cur_row);
	}

	// store sum sum[i][j] is sum from (1,1) to (i,j)
	vector<vector<int>> sum;
	for(int i = 0; i < N; ++i){
		vector<int> cur_row;
 		for(int j = 0;j < M; ++j){
 			if(i == 0 && j == 0){
				cur_row.emplace_back(matrix[0][0]);
			} else if(i == 0) {
				cur_row.emplace_back(cur_row[j-1] + matrix[i][j]);
			} else if(j == 0) {
				cur_row.emplace_back(sum[i-1][j] + matrix[i][j]);
			} else {
				cur_row.emplace_back(sum[i-1][j] + cur_row[j-1] + matrix[i][j] - sum[i-1][j-1]);
			}
		}
		sum.emplace_back(cur_row);
	}

	// print matrix
	for(int i = 0;i < N; ++i) {
		for(int j = 0;j < M; ++j)
			cout << sum[i][j] << " ";
		cout << endl;	 
	}

	int Q;
	cin >> Q;
	while(Q-- > 0) {
		int a,b;
		cin >> a >> b;
		vector<vector<int>> max_col;

		// create maxCol array of max elements in a row for all sequence of size b
		for(int i = 0; i < N; ++i) {
			deque<int> mQ;
			vector<int> cur_row;
			int k;
			for(k = 0; k < b; ++k){
				while(!mQ.empty() && matrix[i][k] >= matrix[i][mQ.back()]){
					mQ.pop_back();
				}
				mQ.push_back(k);
			}

			for(; k < M; ++k) {
				cur_row.emplace_back(mQ.front());
				while(!mQ.empty() && mQ.front() <= k-b) {
					mQ.pop_front();
				}
				while(!mQ.empty() && matrix[i][k] >= matrix[i][mQ.back()]){
					mQ.pop_back();
				}
				mQ.push_back(k);
			}
			cur_row.emplace_back(mQ.front());
			max_col.emplace_back(cur_row);
		} // ends


		// print matrix
		// for(int i = 0;i < N; ++i) {
		// 	for(int j = 0;j <= M-b; ++j)
		// 		cout << max_col[i][j] << " ";
		// 	cout << endl;	 
		// }

		int best_so_far = numeric_limits<int>::max(); // best difference found as of now
		int r_i = 0, r_j = 0;		
		// find sub matrix considering all submatrices of size (a, b)
		for(int i = 0; i <= M-b; ++i) { // move column wise
			deque<int> cmax;
			int max_col_index = i;

			// find max in current (a,b)
			int k;
			for(k = 0; k < a; ++k) {
				while(!cmax.empty() && matrix[k][max_col[k][max_col_index]] >= matrix[cmax.back()][max_col[cmax.back()][max_col_index]]){
					cmax.pop_back();
				}
				cmax.push_back(k);
			}

			for(; k < N; ++k) {

				int max_ab = matrix[cmax.front()][max_col[cmax.front()][max_col_index]];
				int ab_i = k-1, ab_j = max_col_index+b-1;
				int sum_cur_ab = sum[ab_i][ab_j];
				if(ab_i - a >= 0)
					sum_cur_ab -= sum[ab_i - a][ab_j];
				if(ab_j - b >= 0)
					sum_cur_ab -= sum[ab_i][ab_j - b];
				if(ab_i - a >=0 and ab_j - b >=0)
					sum_cur_ab += sum[ab_i-a][ab_j-b];

				int res = a*b*max_ab - sum_cur_ab;
				if(res < best_so_far) {
					best_so_far = res;
					r_i = ab_i;
					r_j = ab_j;
				}
				// cout << sum_cur_ab << " .. " << max_ab << " .. " << endl;
				// cout << a*b*max_ab  - sum_cur_ab << endl;

				while(!cmax.empty() && cmax.front() <= k-a) {
					cmax.pop_front();
				}
				while(!cmax.empty() && matrix[k][max_col[k][max_col_index]] >= matrix[cmax.back()][max_col[cmax.back()][max_col_index]]){
					cmax.pop_back();
				}
				cmax.push_back(k);
			}

			int max_ab = matrix[cmax.front()][max_col[cmax.front()][max_col_index]];
			int ab_i = k-1, ab_j = max_col_index+b-1;
			int sum_cur_ab = sum[ab_i][ab_j];
			if(ab_i - a >= 0)
				sum_cur_ab -= sum[ab_i - a][ab_j];
			if(ab_j - b >= 0)
				sum_cur_ab -= sum[ab_i][ab_j - b];
			if(ab_i-a >=0 and ab_j-b >=0)
				sum_cur_ab += sum[ab_i-a][ab_j-b];
			int res = a*b*max_ab - sum_cur_ab;
			if(res < best_so_far) {
				best_so_far = res;					
				r_i = ab_i;
				r_j = ab_j;
			}

		}

		cout << "i " << r_i << "  j " << r_j << "  sum " << best_so_far << endl;

	}

}