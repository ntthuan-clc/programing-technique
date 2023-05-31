#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{ 
    FILE* in;
    in = fopen("1000n.bin", "rb");
    if(in != nullptr){
        int n;
        fread(&n, sizeof(n), 1, in);
        cout << n << '\n';
        int* arr = new int[n];
        for (int i = 0; i < n; ++i){
            fread(&arr[i], sizeof(arr[i]), 1, in);
        }

        for (int i = 0; i < n; ++i){
            cout << arr[i] << " ";
        }

    }

    

    return 0;
}