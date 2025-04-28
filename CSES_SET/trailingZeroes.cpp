// https://cses.fi/problemset/task/1618

#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;

    while(n) {
        ans += n/5;
        n /= 5;
    }

    cout << ans;

    return 0;
}