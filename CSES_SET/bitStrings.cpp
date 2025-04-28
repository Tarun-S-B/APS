// https://cses.fi/problemset/task/1617

#include<iostream>
#include<cmath>

using namespace std;

int main() {
    unsigned long long int n,  i;
    int ans = 1;
    cin >> n;
    // ans = log2(n) + 1;

    for(i=0; i<n; i++) {
        ans = ans << 1;
        // cout << "Ans: " << ans << endl;
        ans = ans % int((1e9 + 7));
    }

    cout << ans;
    return 0;
}