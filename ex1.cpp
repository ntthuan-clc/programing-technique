#include<iostream>
#include<stdio.h>

using namespace std;

int* twiceArray(int *arr, int n){
    int *newArr = (int*)realloc(arr, sizeof(int)* 2* n);
    for (int i = n; i < 2*n; ++i){
        newArr[i] = 10;
    }
    return newArr;
}

int main(){
    int *a;
    int  b =10;
    a=&b;
    int *arr = (int*)malloc(sizeof(int)*5);
    int n = 5;
    for (int i = 0; i < 5; ++i){
        arr[i] = i + 1;
    }
    arr = twiceArray(arr,n);
    for (int i = 0; i < 2*n; ++i){
        cout << arr[i] << " ";
    }
    return 0;
}