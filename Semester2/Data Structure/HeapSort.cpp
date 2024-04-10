#include<stdio.h>
#include<conio.h>
#include<math.h>

int n = 10;
int heapsize = n;

void maxHeapify(double a[], int i){
	int l = 2*i + 1;
	int r = 2*i + 2;
	int largest;
	if (l <= heapsize && a[l] > a[i]){
		largest = l;
	}
	else largest = i;
	if (r <= heapsize && a[r] > a[largest]){
		largest = r;
	}
	if (largest != i){
		a[i] = a[i] + a[largest];
		a[largest] = a[i] - a[largest];
		a[i] = a[i] - a[largest];
		maxHeapify(a, largest);
	}
}

void buildMaxHeap(double a[]){
	heapsize = n-1;
	for (int i = (n-1)/2; i >= 0; i--){
		maxHeapify(a, i);
	}
}

void heapSort(double a[]){
	buildMaxHeap(a);
	for (int i = n-1; i >= 1; i--){
		a[i] = a[i] + a[0];
		a[0] = a[i] - a[0];
		a[i] = a[i] - a[0];
		heapsize--;
		maxHeapify(a, 0);
	}
}

int main(){
	double a[10] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
	heapSort(a);
	for (int i = 0; i < n; i++){
		printf("%.0lf ", a[i]);
	}
	return 0;
}
