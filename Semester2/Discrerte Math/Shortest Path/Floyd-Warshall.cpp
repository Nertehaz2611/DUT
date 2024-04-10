#include <stdio.h>
const int oo = 99999;
int a[1812][1812];
int n, m;
int next1[100][100];

void Init(){
    scanf("%d", &n);
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			next1[i][j] = 999999;
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			scanf("%d", &a[i][j]);
			if (a[i][j] != oo && a[i][j] != 0){ // Co duong di giua i va j
				next1[i][j] = j;
			}
		}
	}
}

void Floyd_Warshall(){
	for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
            	if ((a[i][j] >  a[i][k] + a[k][j]) && (a[i][k] != oo) && (a[k][j] != oo)){
            		a[i][j] = a[i][k] + a[k][j];
                	next1[i][j] = next1[i][k];
            	}
            }
        }
    }
}

void display(){
	printf("\nMa tran khoang cach:\n");
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
        	printf("%d ", a[i][j]);
    	}
    	printf("\n");
    }
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		if(a[i][j] == oo){
    			printf("\nKhong co duong di tu dinh %d toi dinh %d", i, j);
    			continue;
			}
    		if (i != j){
    			printf("\nDuong di tu dinh %d toi dinh %d: ", i, j);
    			for(int tmp = i; tmp != j; tmp = next1[tmp][j]){
    				printf("%d --> ", tmp);
    			}
				printf("%d", j);
				printf("\nDo dai duong di: %d\n", a[i][j]);
			}
		}
	}
}

int main() {
    Init();
    Floyd_Warshall();
    display();
    return 0;
}

/*
4
99999 7  5 99999
99999 99999 7 6
99999 99999 99999 11
4 1 99999 99999
*/
