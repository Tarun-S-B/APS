#include<iostream>
#include<vector>
using namespace std;

/*
input:
target sum, no of coins, coins
15
3
3 5 1
*/

int main() {
    int target_amount,no_coins;
    cin >> target_amount >> no_coins;
    vector<int> ways(target_amount+1);
    ways[0] = 1;
    vector<int>coins (no_coins);
    for(int i=0; i<no_coins; i++) cin >> coins[i];

    // take each coin
    for(int coin: coins) {
        for(int i=coin; i<=target_amount;i++) {
            ways[i] += ways[i-coin];
        }
    }
    cout << ways[target_amount] << endl;

    return 0;
}
