#include<iostream>

using namespace std;

unsigned long long int tree[800000];
unsigned long long int a[200000];
int n;

void build(unsigned long long int low, unsigned long long int high, unsigned long long int index) {
    if(low == high) {
        tree[index] = a[low];
        return;
    }
    unsigned long long int mid = (low + high)/2;
    build(low, mid,2*index+1);
    build(mid+1,high,2*index+2);
    tree[index] = tree[2*index+1] + tree[2*index+2];
}

unsigned long long int findXOR(unsigned long long int l, unsigned long long int r, unsigned long long int low, unsigned long long int high, unsigned long long int index) {
    if(low  >= l && high <= r){
        return tree[index];
    }
    if(r<low || l>high){
        return 0;
    }
    unsigned long long int mid = (low + high)/2;
    return findXOR(l,r,low,mid,2*index+1) ^ findXOR(l,r,mid+1,high,2*index+2);
}

void update(unsigned long long int target, unsigned long long int value, unsigned long long int low, unsigned long long int high, unsigned long long int index) {
    if(low == high && low == target) {
        tree[index] = value;
        return;
    }
    unsigned long long int mid = (low + high) / 2;
    if(target <= mid) {
        update(target,value,low,mid,2*index+1);
    } else {
        update(target,value,mid+1,high,2*index+2);
    }
    tree[index] = tree[2*index+1] ^ tree[2*index+2];
}

int main() {
    unsigned long long int query,l,r,type;
    cin >> n;
    cin >> query;
    for(int i=0; i<n; i++) {
        // cout << "IN QUERY" <<endl;
        cin >> a[i];
    }
    build(0,n-1,0);
    // cout << "TREE: ";
    // for(int i=0; i<4*n; i++)
    // cout << tree[i] << " ";
    while(query--) {
        cin >> type;
        if(type==1) {
            cin >> l >> r;
            update(l,r,0,n-1,0);
        } else {
            cin >> l >> r;
            unsigned long long int ans = findXOR(l-1,r-1,0,n-1,0);
            cout << ans << endl;
        }
    }

    return 0;
}