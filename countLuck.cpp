#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>

using namespace std;
typedef vector<vector<char>> char2D;
typedef vector<vector<bool>> bool2D;
typedef pair<int, int> pii;
const vector<pii> moves{{0,-1}, {0,1}, {1,0}, {-1,0}};

int g_count = 0;

bool isValidLoc(pii loc, pii move, int N, int M) {
	return (loc.first + move.first) < N && (loc.second + move.second) < M && (loc.first + move.first) >= 0 && (loc.second + move.second) >= 0? true: false;
}

int getMultiCount(const pii& loc, const char2D& visited) {
	int count = 0;
	for(pii move : moves) {
		if(isValidLoc(loc, move, visited.size(), visited[0].size()) && visited[loc.first + move.first][loc.second + move.second] == '0')
			++count;
	}
	return count;
}

void printPair(const pii& p) {
	cout << p.first << " | " << p.second;
}

bool checkLuck(char2D& is_multi, char2D& visited, int K, const pii& start, const pii& end) {

	stack<pii> dfs;
	dfs.push(start);
	int cur_moves = K;

	while(!dfs.empty()) {

		pii top = dfs.top();
		// target reached
		if(top == end && cur_moves == 0) {
			return true;
		}

		int multi_count = 0;

		if(visited[top.first][top.second] - '0' < 4){ 
			
			multi_count = getMultiCount(top, visited);
			if(multi_count > 1) {
				if(visited[top.first][top.second] == '0'){
					is_multi[top.first][top.second] = 'y';
					--cur_moves;
				}
			}
			visited[top.first][top.second] += 1;
		} else {
			dfs.pop();
			if(is_multi[top.first][top.second] == 'y')
				++cur_moves;
			continue;
		}

		for(pii move : moves) {
			if(isValidLoc(top, move, visited.size(), visited[0].size())) {
				pii t_pii = make_pair(top.first + move.first, top.second + move.second);
				if(visited[t_pii.first][t_pii.second] == '0') {
					dfs.push(t_pii);
					break;
				} 
			}
		}
	}

	return false;
}

int main() {

	int T;
	cin >> T;
	int counter = 1;

	while(T-- > 0) {

		int N, M;
		cin >> N >> M;
		char2D visited, is_multi;
		pii start, end;

		for(int i = 0; i < N; ++i) {
			vector<char> vr, mr;
			getchar();
			
			for(int j = 0; j < M; ++j) {
				char item;
				cin >> item;
			
				if(item == 'M') {
					start = make_pair(i, j);
					vr.emplace_back('0');
				} else if(item == '*') {
					end = make_pair(i,j);
					vr.emplace_back('0');
				} else if(item == 'X') {
					vr.emplace_back('f');
				} else {
					vr.emplace_back('0');
				} 

				mr.emplace_back('n');

			}

			visited.emplace_back(vr);
			is_multi.emplace_back(mr);
		}

		int K;
		cin >> K;

		if(checkLuck(is_multi, visited, K, start, end))
			cout << "Impressed" << endl;
		else 
			cout << "Oops!" << endl;

	}

	return 0;
}