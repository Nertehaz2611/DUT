#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
 
#define Max 50

int final[Max];
int V, U;		// So Dinh, So Canh
int start, end;	// Diem Xuat Phat va Ket Thuc

void Init (int CP[Max][Max]){
	int i, j;
	for (int i = 0; i < Max; i++){
		for (int j = 0; j < Max; j++){
			CP[i][j] = 32000;
		}
	}
	scanf("%d%d", &V, &U);
	for (i = 1; i <= U; i++){
		int x, y; scanf("%d%d", &x, &y);
		scanf("%d", &CP[x][y]);
	}
}

void Display (int truoc[Max], int d[Max]){
	int i, j;
	printf("\n Duong Di Ngan Nhat tu %d den %d la: ", start, end);
	printf(" %d <-- ", end);
	i = truoc[end];
	
	while (i != start){
		printf("%d <-- ", i);
		i = truoc[i];
	}
	
	printf("%d", start);
	printf("\n Do Dai Duong Di la: %d", d[end]);
}

void Dijkstra (int CP[Max][Max], int truoc[Max], int d[Max]){
	int u, v, minp;
	printf("\n Nhap vao Vi Tri Xuat Phat: "); scanf("%d", &start);
	printf("\n Nhap vao Vi Tri Dich: "); scanf("%d", &end);
	
	for (v = 0; v <= V-1; v++){
		d[v] = CP[start][v];
		truoc[v] = start;
		final[v] = 0;
	}
	
	truoc[start] = 0;
	d[start] = 0;
	final[start] = 1;
	
	while (!final[end]){
		minp = 2000;
		for (v = 0; v <= V-1; v++){
			if (!final[v] && (minp > d[v])){
				u = v;
				minp = d[v];
			}
		}
		
		final[u] = 1;			// u la Dinh co Nhan Temp Nho Nhat
		if (!final[end]){
			for (v = 0; v <= V-1; v++){
				if (!final[v] && (d[u] + CP[u][v] < d[v])){
					d[v] = d[u] + CP[u][v];
					truoc[v] = u;
				}
			}
		}
	}
}

int main (){
	int CP[Max][Max];	// Ma Tran Chi Phi
	int truoc[Max];
	int d[Max];	// Do Dai Duong Di
	
	Init (CP);
	Dijkstra(CP, truoc, d);
	Display (truoc, d);
	return 0;
}

/*
6 9
0 1 5
0 2 2
0 3 1
1 4 3
2 1 1
2 5 1
3 2 1
5 1 1
5 4 1
*/
