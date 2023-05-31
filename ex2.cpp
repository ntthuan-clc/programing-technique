#include <iostream>
#include <stdio.h>

using namespace std;
// ktra snt
bool check(int x)
{
    if (x < 2)
    {
        return false;
    }
    for (int i = 2; i <= x / 2; ++i)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

//dem so luong
int countPrime(int n){
    int count = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (check(i))
        {
            count++;
        }
    }
    return count;
}

int *primeUnderN(int n)
{
    int* result = (int*)malloc(sizeof(int)*countPrime(n));
    int index = 0;
    for(int i = 0; i <= n; ++i){
        if(check(i)){
            result[index] = i;
            index++;
        }
    }
    return result;
}

//version 2 primeUnderN
int *primeUnderNv2(int n)
{
    int* result = (int*)malloc(sizeof(int)*100);
    int index = 0;
    for(int i = 0; i <= n; ++i){
        if(check(i)){
            result[index] = i;
            cout << result[index] << " ";
            index++;
        }
    }
    result = (int*)realloc(result,sizeof(int)*index);
    return result;
}

int main()
{
    int n = 100;
    // tra ra pointer arr luu snt < n
    int count = countPrime(n);
    int* arrPrime = primeUnderN(n);
    
    for (int i = 0; i < count; ++i){
        cout << arrPrime[i] << " ";
    }
    cout << "\n";
    int* arrPrimeV2 = primeUnderNv2(n);
    // for (int i = 0; i < count; ++i){
    //     cout << arrPrimeV2[i] << " ";
    // }

    return 0;
}