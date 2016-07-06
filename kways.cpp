#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 100

using namespace std;
int cache[MAX][MAX][MAX][2]; // 0 is R and 1 is D

int main() {

	int M, N, K;
	cin >> M >> N >> K;

	memset(cache, 0, sizeof cache);

	for(int j = 1; j < N; ++j) {
		for(int k = 0; k <= K; ++k) {
			cache[0][j][k][0] = 1;
		}
	}

	for(int i = 1; i < M; ++i) {
		for(int k = 0; k <= K; ++k) {
			cache[i][0][k][1] = 1;
		}
	}

	for(int i = 1; i < M; ++i) {
		for(int j = 1; j < N; ++j) {
			for(int k = 1; k <= K; ++k) {
				cache[i][j][k][0] = cache[i][j-1][k][0] + cache[i][j-1][k-1][1];
				cache[i][j][k][1] = cache[i-1][j][k][1] + cache[i-1][j][k-1][0];

			}
		}		
	}

	cout << cache[M-1][N-1][K][0] + cache[M-1][N-1][K][1] << endl;

	return 0;
}