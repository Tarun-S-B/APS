#include<iostream>
#include<climits>

using namespace std;

unsigned long long int tree[800000];
unsigned long long int a[200000];
int n;

unsigned long long int _build(unsigned long long int low, unsigned long long int high, unsigned long long int index) {
    if(low == high) {
        tree[index] = a[low];
        return a[low];
    }
    unsigned long long int mid = (low + high) / 2;
    _build(low,mid,2*index+1);
    _build(mid+1,high,2*index+2);
    tree[index] = min(tree[2*index+1], tree[2*index+2]); 
    return tree[index];
}

void build() {
    _build(0,n-1,0);
}

unsigned long long int _findMin(unsigned long long int l, unsigned long long int r, unsigned long long int low, unsigned long long int high, unsigned long long int index) {
    if(low>=l && high<=r) {
        return tree[index];
    }
    if(l>high || r<low) {
        return INT_MAX;
    }
    unsigned long long int mid = (low+high)/2;
    return min(_findMin(l,r,low,mid,2*index+1),_findMin(l,r,mid+1,high,2*index+2));
}

unsigned long long int findMin(unsigned long long int l, unsigned long long int r) {
    return _findMin(l,r,0,n-1,0);
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
        unsigned long long int ans = findMin(l-1,r-1);
        cout << ans << endl;
    }

    return 0;
}