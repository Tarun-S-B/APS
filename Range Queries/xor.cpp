#include<iostream>

using namespace std;

unsigned long long int tree[800000];
unsigned long long int a[200000];
int n;

void _build(unsigned long long int low, unsigned long long int high, unsigned long long int index) {
    if(low == high) {
        tree[index] = a[low];
        return;
    }
    unsigned long long int mid = (low + high)/2;
    _build(low,mid,2*index+1);
    _build(mid+1,high,2*index+2);
    tree[index] = tree[2*index+1] ^ tree[2*index+2];
}

void build() {
    _build(0,n-1,0);
}

unsigned long long int _findXOR(unsigned long long int l, unsigned long long int r, unsigned long long int low, unsigned long long int high, unsigned long long int index) {
    if(low>=l && high<=r) {
        return tree[index];
    } 
    if(high < l || r < low) {
        return 0;
    }
    unsigned long long int mid = (low + high) / 2;
    return _findXOR(l,r,low,mid,2*index+1) ^ _findXOR(l,r,mid+1,high,2*index+2);
}

unsigned long long int findXOR(unsigned long long int l, unsigned long long int r) {
    return _findXOR(l,r,0,n-1,0);
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
    // cout << "TREE: ";
    // for(int i=0; i<4*n; i++)
    // cout << tree[i] << " ";
    while(query--) {
        cin >> l >> r;
        unsigned long long int ans = findXOR(l-1,r-1);
        cout << ans << endl;
    }

    return 0;
}