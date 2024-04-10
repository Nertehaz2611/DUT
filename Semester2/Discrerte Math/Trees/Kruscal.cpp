#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef long long ll;

struct edge{
	int u, v;
	int w;
};

const int maxn = 1001;
int n, m;
int parent[maxn], sz[maxn];
edge canh[maxn];

void make_set(){
	for (int i = 1; i <= n; i++){
		parent[i] = i;
		sz[i] = 1;
	}
}

int find(int v){
	if (v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}

int Union(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b) return 0;
	if (sz[a] < sz[b]){
		a ^= b;
		b ^= a;
		a ^= b;
	}
	parent[b] = a;
	sz[a] += sz[b];
	return 1; 
}

void input(){
	scanf("%d%d", &n, &m);
	int j = 1;
	for (int i = 0; i < m; i++){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		edge e = {x, y, z};
		canh[i] = e;
	}
}

void edgeSort(edge canh[], int l, int r){
	int p = canh[(l+r)/2].w;
	int i = l, j = r;
	while (i < j){
		while (canh[i].w < p){
			i++;
		}
		while (canh[j].w > p){
			j--;
		}
		if (i <= j){
			edge temp = canh[i];
			canh[i] = canh[j];
			canh[j] = temp;
			i++;
			j--;
		}
	}
	if (i < r){
		edgeSort(canh, i, r);
	}
	if (l < j){
		edgeSort(canh, l, j);
	}
}

void kruscal(){
	edge mst[maxn];
	int j = 0;
	int d = 0;
	edgeSort(canh, 0, m-1);
	for (int i = 0; i < m; i++){
		if (j == n-1) break;
		edge e = canh[i];
		if (Union(e.u, e.v)){
			mst[j] = e;
			d += e.w;
			j++;
		}
	}
	if (j != n-1){
		printf("Do thi khong lien thong");
	}
	else {
		printf("\nDo dai MST: %d\n", d);
		for (j = 0; j < n-1; j++){
			printf("%d %d %d\n", mst[j].u, mst[j].v, mst[j].w);
		}
	}
}

int main(){
	input();
	make_set();
	kruscal();
	return 0;
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

