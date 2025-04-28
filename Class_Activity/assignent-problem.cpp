#include<iostream>
#include<vector>
#include<bitset>

using namespace std;

int setBits(int n) {
    int c = 0;
    while(n) {
        c++;
        n = n & (n - 1);
    }
    return c;
}

int main() {

    int n = 3;
    int cost[][3] = {
        {3,2,7},
        {5,1,3},
        {2,7,2}
    };

    int N = 1 << n;

    vector<int> dp(N,INT_MAX);
    dp[0] = 0;

    int x;
    for(int i=0; i<N; i++) {
        x = setBits(i);
        for(int j=0; j<n; j++) {
            if(!(i&(1<<j))) {
                // cout << "mask: " << bitset<3>(i) << " J: " << j << endl;
                dp[(i | (1<<j)) ] = min ( dp[(i | (1<<j)) ] , (dp[i] + cost[x][j]) );
                // for(auto it: dp) 
                //     cout << it << " ";
                // cout << endl << endl;
            }
        }
    }
    cout << dp[N-1];
    return 0;
}
