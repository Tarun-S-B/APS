// https://cses.fi/problemset/task/1068

#include<iostream>

using namespace std;

int main() {
    long long int n;
    cin >> n;
    cout << n << " ";
    while(n != 1) {
        if(n%2)
            n = n * 3 + 1;
        else   
            n = n / 2;
        cout << n << " ";
    }
    return 0;
}