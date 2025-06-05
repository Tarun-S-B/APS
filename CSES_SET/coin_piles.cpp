// https://cses.fi/problemset/task/1754

#include<iostream>
using namespace std;

int main() {
    int t;
    unsigned long long int a,b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        if(b>a) {
            a = a ^ b;
            b = a ^ b;
            a = a ^ b;
        }
        if(a > 2*b) {
            cout << "NO" << endl;
            continue;
        }
        a = a%3;
        b = b%3;
        if(a+b==3) {
            cout << "YES" << endl;
        } else if(a+b==0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}