// https://cses.fi/problemset/task/1070

#include<iostream>

using namespace std;

int main() {
    long long int n;

    cin >> n;
    if(n==1) {
        cout << 1;
        return 0;
    } else if(n<4) {
        cout << "NO SOLUTION";
        return 0;
    }
    for(long long int i=1; i<=(n/2); i++) 
        cout << (i + (n/2)) << " " << i << " ";
    if(n%2)
        cout << n;
    return 0;
}