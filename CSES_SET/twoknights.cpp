// https://cses.fi/problemset/task/1072

#include<iostream>

using namespace std;

long long int fun(int n) {
    // a(n) = (n - 1)*(n + 4)*(n^2 - 3*n + 4)/2
    long long int ans = (n-1);
    ans *= n+4;
    ans *= n*n - 3*n +4;
    ans /=2;
    return ans;
}

int main() {
    int n;
    cin>> n;
    for(int i=0; i<n; i++) {
        cout << fun(i+1) << endl;
    }
    return 0;
}