// https://cses.fi/problemset/task/1094

#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<unsigned long long int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    unsigned long long int count = 0;
    unsigned long long int prev = a[0];
    for(int i=1; i<n; i++) {
        if(prev>a[i]) {
            count += (prev - a[i]);
            a[i] = prev;
        }
        prev = a[i];
    }
    cout << count;
    return 0;
}