#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 1025

int mat[NMAX][NMAX];
int tree[NMAX][NMAX];
int n;

const char* cmds[3] = {"SET", "SUM", "END"};

int str_cmp(char* s1, const char* s2) {
	int eq =  1;
	while(true) {
		if(*s1 == '\0' && *s2 == '\0') break;
		if(*s1 != *s2) {
			eq = 0;
			break;
		}
		s1++;
		s2++;
	}
	return eq;
}

void init() {
	for(int i = 0; i < NMAX; ++i) {
		for(int j = 0; j < NMAX; ++j) {
			mat[i][j] = tree[i][j] = 0;
		}
	}
}

void print_mats() {
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("--------------------------------------\n");
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			printf("%d ", tree[i][j]);
		}
		printf("\n");
	}

}

void update(int x, int y, int val) {
	printf(" ------------- before ---------------\n");
	print_mats();
	int change = val - mat[x][y];
	mat[x][y] = val;
	while(x <= n) {
		int y1 = y;
		while(y1 <= n) {
			printf("updating values at %d %d by %d \n", x, y1, change);
			tree[x][y1] += change;
			y1 += (y1 & -y1);
		}
		x += (x & -x); 
	}
	printf(" ------------- after ---------------\n");
	print_mats();
}

int sum(int x, int y) {
	int sum = 0;
	while(x > 0) {
		int y1 = y;
		while(y1 > 0) {
			sum += tree[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return sum;
}

int main() {	
	int t;
	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	char cmd[4];
	int x1, y1, x2, y2, val;
	while(t--) {
		scanf("%d", &n);
		init();
		while(true) {
			scanf("%s", cmd);
			if(str_cmp(cmd, cmds[2])) { // END 
				printf("END \n");
				printf("\n");
				break;
			} else if(str_cmp(cmd, cmds[0])) { // SET
				printf("SET \n");
				scanf("%d %d %d", &x1, &y1, &val);
				update(x1+1, y1+1, val);
			} else { // SUM
				printf("SUM \n");
				scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
				int sum_v = sum(x2+1, y2+1);
				sum_v -= sum(x2+1, y1);
				sum_v -= sum(x1, y2+1);
				sum_v += sum(x1, y1);
				printf("%d\n", sum_v);
			}
		}
	}
}