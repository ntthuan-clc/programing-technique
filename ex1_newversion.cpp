#include<iostream>
#include<stdio.h>

using namespace std;

int* twiceArray(int *arr, int n){
    int* newArr = new int[2*n];
    for (int i = 0; i < n; ++i){
        newArr[i] = arr[i];
    }
    for (int i = n; i < 2*n; ++i){
        newArr[i] = 10;
    }
    return newArr;
}


int main(){
    int *arr = new int[5];
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