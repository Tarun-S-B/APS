// STOLEN VALUES
// can't steal from adjacent homes
/*
input: 
8
9 3 5 8 2 4 7 10
output:
31
*/

#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n,x;
    cin >> n;
    vector<int> a;
    vector<int> dp(n+1);
    for(int i=0; i<n; i++) {
        cin >> x;
        a.push_back(x);
    }

    // Algo
    dp[1] = a[0];
    for(int i=2; i<=n; i++) {
        dp[i] = max(dp[i-1],dp[i-2]+a[i-1]);
    }
    cout << dp[n];
    return 0;
}