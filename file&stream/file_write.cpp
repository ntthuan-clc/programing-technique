#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    FILE *in, *out;
    in = fopen("1000n.txt", "rt"); // rt = read txt || rb = read bin
    int n;
    fscanf(in, "%d", &n);
    cout << n << '\n';
    int *arr = new int[n];

    if (in == nullptr)
    {
        cout << "open file failed !\n";
    }
    else {
        
        for (int i = 0; i < n; ++i)
        {
            fscanf(in, "%d,", &arr[i]);
        }

        for (int i = 0; i < n; ++i)
        {
            cout << arr[i] << " ";
        }
    }

    out = fopen("1000n.bin", "wb"); // wt = write txt || wb = write bin
    if (out == nullptr)
    {
        cout << "open file failed !\n";
    }
    else
    {
        fwrite(&n, sizeof(n), 1, out);
        for(int i = 0; i < n; ++i) {
            fwrite(&arr[i], sizeof(arr[i]), 1, out);
        }
    }
    
    return 0;
}