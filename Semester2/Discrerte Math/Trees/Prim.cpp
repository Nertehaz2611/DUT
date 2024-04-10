#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

const int maxn = 1001;

struct canh{
	int x, y, w;
};

struct pair{
	int first, second;
};

int n, m; 
pair adj[maxn][maxn];
bool used[maxn];

void input(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		adj[x][i] = {y, z};
		adj[y][i] = {x, z}; 
	}
	for (int i = 0; i < maxn; i++){
		used[i] = false;
	}
}

void prim(int v){
	canh MST[maxn];
	int MSTsz = 0;
	int d = 0;
	used[v] = true; 
	while(MSTsz <= n - 1){
		int min_w = INT_MAX;
		int X, Y;
		for(int i = 1; i <= n; i++){
			if(used[i]){
				for(int t = 0; t < m; t++){
					int j = adj[i][t].first, trongso = adj[i][t].second;
					if(used[j] == 0 && trongso < min_w){
						min_w = trongso;
						X = j; Y = i;
					}
				}
			}
		}
		MST[MSTsz] = {X, Y, min_w};
		d += min_w;
		used[X] = true;
		MSTsz++;
	}
	printf("\nDo dai MST: %d\n", d);
	for(int i = 1; i < n; i++){
		printf("%d %d %d\n", MST[i].x, MST[i].y, MST[i].w);
	}
}

int main(){
	input();
	prim(1);
}

/*
6 9
1 2 9
2 3 1
1 3 4
2 4 6
2 5 3
3 5 2
4 6 10
5 6 8
4 5 3
*/
