#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int get_max_moves(vector<vector<int>>& cache, const vector<vector<int>>& arr, int row, int col) {


	if(cache[row][col] != -1) {
		return cache[row][col];
	}

	int moves = 1;
	int N = cache[0].size();
	
	if(row-1 >= 0 && arr[row][col] +1 == arr[row-1][col])
		moves = max(1 + get_max_moves(cache, arr, row-1, col), moves);
	if(col-1 >= 0 && arr[row][col] +1 == arr[row][col-1])
		moves = max(1 + get_max_moves(cache, arr, row, col-1), moves);
	if(row+1 < N && arr[row][col] +1 == arr[row+1][col])
		moves = max(1 + get_max_moves(cache, arr, row+1, col), moves);
	if(col+1 < N && arr[row][col] +1 == arr[row][col+1])
		moves = max(1 + get_max_moves(cache, arr, row, col+1), moves);

	cache[row][col] = moves;
	return moves;

}

int main() {

	int N;
	cin >> N;
	vector<vector<int>> arr;
	vector<vector<int>> cache;

	for(int i = 0; i < N; ++i) {
		vector<int> sub_arr;
		vector<int> cache_arr;

		for (int j = 0; j < N; ++j) {
			int item;
			cin >> item;
			sub_arr.emplace_back(item);
			cache_arr.emplace_back(-1);
		}

		arr.emplace_back(sub_arr);
		cache.emplace_back(cache_arr);
	}

	int best_moves = 0;

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			best_moves = max(best_moves, get_max_moves(cache, arr, i, j)); 
		}
	}

	cout << best_moves << endl;
	return 0;
}