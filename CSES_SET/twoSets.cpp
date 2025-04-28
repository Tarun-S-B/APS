// https://cses.fi/problemset/task/1092

#include<iostream>
#include<vector>

using namespace std;

int main() {
    unsigned long long int n;
    cin >> n;
    unsigned long long int ans = n * (n+1);
    ans /= 2;
    if(ans&1){
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    vector<unsigned long long int> sum1;
    vector<unsigned long long int> sum2;
    ans /=2;
    for(unsigned long long int i=n; i>=1; i--) {
        if(ans>=i) {
            sum1.push_back(i);
            ans-=i;
        } else {
            sum2.push_back(i);
        }
    }
    cout << sum1.size() << endl;
    for(auto i: sum1) cout << i << " ";
    cout << endl;
    cout << sum2.size() << endl;
    for(auto i: sum2) cout << i << " ";

    return 0;
}