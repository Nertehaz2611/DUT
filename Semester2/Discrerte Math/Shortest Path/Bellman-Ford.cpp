#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;

const int MaxN = 1 + 1e2;
const ll INF = 1e18;

int n, m, s, e, mark[MaxN];
int truoc[MaxN];
ll dist[MaxN];

struct Edge{
    int u, v, w;
};

Edge edges[MaxN];

void input(){
	scanf("%d%d", &n, &m);
	
	for(int i = 0; i < m; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edges[i] = {u, v, w};
    }
    
    printf("\nNhap vao Vi Tri Xuat Phat: "); scanf("%d", &s);
	printf("\nNhap vao Vi Tri Dich: "); scanf("%d", &e);
    printf("\n");
}

void Bellman_Ford(){
	for (int i = 0 ; i<= n; i++){
		dist[i] = INF;
	}
    dist[s] = 0;

    for(int i = 1; i <= n; i++){
    	for (int j = 0; j < m; j++){
    		if (dist[edges[j].u] + edges[j].w < dist[edges[j].v]){
    			if (i == n) mark[edges[j].v] = 1;
    			dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
    			truoc[edges[j].v] = edges[j].u;
			}
		}
    }
}

void display(){
	if (!mark[e]){ 
        if (dist[e] == INF) printf("Khong ton tai duong di tu dinh %d toi dinh %d\n", s, e);
        else {
        	printf("Do dai duong di ngan nhat tu dinh %d toi dinh %d: %lld\n", s, e, dist[e]);
        	if (s == e) return;
        	printf("\nDuong Di Ngan Nhat tu %d den %d la: ", s, e);
			printf(" %d", e);
			int i = truoc[e];
			printf(" <-- %d", i);
			
			if (i != s) do {
				i = truoc[i];
				printf(" <-- %d", i);
			} while (i != s);
		}
    } else printf("Khong ton tai duong di ngan nhat tu dinh %d toi dinh %d\n", s, e);
    
}

int main(){
    input();
    Bellman_Ford();
    display();
    return 0;
}

/*
6 10
1 2 1
2 3 5
2 4 2
2 6 7
3 6 1
4 3 1
4 1 2
4 5 4
5 4 3
6 5 1
*/
