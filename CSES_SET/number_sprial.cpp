// https://cses.fi/problemset/task/1071

#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    unsigned long long int x,y;
    
    for(int i=0; i<n; i++) {
        cin >> x >> y;
        if(x > y) {
            if(x&1) {
                cout << (x-1) * (x-1) + y << endl;
            } else {
                cout << x * x - y + 1 << endl;
            }
        } else {
            if(y&1) {
                cout << y * y - x + 1 << endl;
            } else {
                cout << (y-1) * (y-1) + x << endl;
            }
        } 
    }
    return 0;
}