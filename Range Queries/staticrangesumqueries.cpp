#include<iostream>

using namespace std;

unsigned long long int tree[800000];
unsigned long long int a[200000];
int n;

unsigned long long int _build(unsigned long long int low, unsigned long long int high, unsigned long long int index) {
    if(low == high) {
        tree[index] = a[low];
        return a[low];
    }
    // int mid = high - ((high/2) - (low/2));
    unsigned long long int mid = (high + low) / 2;
    _build(low,mid,2*index+1);
    _build(mid+1,high,2*index+2);
    tree[index] = tree[2*index+1] + tree[2*index+2];
    return tree[index];
}


void build() {
    _build(0,n-1,0);
}

unsigned long long int _findSum(unsigned long long int l, unsigned long long int r, unsigned long long int low, unsigned long long int high, unsigned long long int index) {
    if(l <= low && r>=high) {
        return tree[index];
    }
    if(l>high || r<low) {
        return 0;
    }
    // int mid = high - ( (high/2) - (low/2));
    unsigned long long int mid = (high + low) / 2;
    return _findSum(l,r,low, mid,2*index+1) + _findSum(l,r,mid+1,high,2*index+2);
}

unsigned long long int findSum(unsigned long long int l, unsigned long long int r) {
    return _findSum(l,r,0,n-1,0);
}

int main() {
    unsigned long long int query,l,r;
    cin >> n;
    cin >> query;
    for(int i=0; i<n; i++) {
        // cout << "IN QUERY" <<endl;
        cin >> a[i];
    }
    build();
    while(query--) {
        cin >> l >> r;
        unsigned long long int ans = findSum(l-1,r-1);
        cout << ans << endl;
    }

    return 0;
}