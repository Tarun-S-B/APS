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
    unsigned long long int mid = (low + high) / 2;
    _build(low,mid,2*index+1);
    _build(mid+1,high,2*index+2);
    tree[index] = tree[2*index+1] + tree[2*index+2];
}


void build() {
    _build(0,n-1,0);
}

unsigned long long int _findSum(unsigned long long int l, unsigned long long int r, unsigned long long int low, unsigned long long int high, unsigned long long int index) {
    if(low >= l && high <= r) {
        return tree[index];
    }
    if(high < l || low > r) {
        return 0;
    }
    unsigned long long int mid = (low + high) / 2;
    return _findSum(l,r,low,mid,2*index+1) + _findSum(l,r,mid+1,high,2*index+2);
}


unsigned long long int findSum(unsigned long long int l, unsigned long long int r) {
    return _findSum(l,r,0,n-1,0);
}

void update(unsigned long long int target, unsigned long long int value, unsigned long long int low, unsigned long long int high, unsigned long long int index) {
    if(low == high && target == low) {
        tree[index] = value;
    } else {
        unsigned long long int mid = (low + high)/2;
        if(target <= mid) {
            update(target,value,low,mid,2*index+1);
        } else {
            update(target,value,mid+1,high,2*index+2);
        }
        tree[index] = tree[2*index+1] + tree[2*index+2];
    }
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
    unsigned long long int type;
    while(query--) {
        cin >> type;
        if(type == 1) {
            cin >> l >> r;
            update(l-1,r,0,n-1,0);
        } else if(type == 2) {
            cin >> l >> r;
            unsigned long long int ans = findSum(l-1,r-1);

            cout << ans << endl;
        }
    }

    return 0;
}