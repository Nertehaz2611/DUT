#include<iostream>
using namespace std;

bool TD(int ai, int aj){
    return ai > aj;
}

bool GD(int ai, int aj){
    return ai < aj;
}

void HV(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

void Sort(int *p, int n, bool (*cmp)(int, int) = TD){
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if ((*cmp)(*(p+i), *(p+j))) HV(*(p+i), *(p+j));
        }
    }
}

void Show(int *p, int n){
    for (int i = 0; i < n; i++){
        cout << *(p+i) << " ";
    }
    cout << endl;
}

int main(){
    int A[] = {1, 4, 3, 8, 7, 6};
    int n = sizeof(A) / sizeof(int);
    Sort(A, n);
    Show(A, n);
    Sort(A, n, GD);
    Show(A, n);
    return 0;
}