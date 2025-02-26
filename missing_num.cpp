#include<iostream>

using namespace std;

int main() {
    long long int n,N,x;
    cin >> n;
    N = (n * (n+1))/2;
    for(int i=0; i<n-1; i++) {
        cin >> x;
        N -= x;
    }
    cout << N;
    return 0;
}