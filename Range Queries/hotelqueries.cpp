#include<iostream>

using namespace std;

int n;
long long int tree[8 * 100000 + 1];
long long int a[2 * 100000 + 1];

void buildMaxSegTree(int low, int high, int index) {
    if(low == high) {
        tree[index] = a[low];
        return;
    }
    int mid = (low + high) / 2;
    buildMaxSegTree(low,mid,2*index+1);
    buildMaxSegTree(mid+1,high,2*index+2);
    tree[index] = max(tree[2*index+1],tree[2*index+2]);
    return;
}

long long int allocateGuest(int low, int high, int val, int index) {
    // only go to the leftmost when equal to or greater than the arrived guest and update the room availability once occupied
    if(tree[index] < val) 
        return -1;

    if(low == high) {
        tree[index] -= val;
        return low;
        // return tree[index];
    }
    int mid = (low + high) / 2;

    long long int ans;
    if(tree[2*index+1] >= val) {
        ans = allocateGuest(low,mid,val,2*index+1);
    } else {
        ans = allocateGuest(mid+1,high,val,2*index+2);
    } 

    // if(ans == 0) {
    //     ans = allocateGuest(mid+1,high,val,2*index+2);
    // } 
    tree[index] = max(tree[2*index+1],tree[2*index+2]);
    // return index;
    // return tree[index];
    return ans;
    
}


int main() {
    int n,q;
    cin >> n >> q;
    for(int i=0; i<n; i++) cin >> a[i];

    buildMaxSegTree(0,n-1,0);
    // for(int i=0; i<4*n; i++) cout << tree[i] << " ";
    // cout << endl;
    long long int queries;
    while(q--) {
        cin >> queries;
        cout << allocateGuest(0,n-1,queries,0) + 1 << " ";
    }
    // cout << "Ans: " << allocateGuest(0,n-1,6,0) << endl;
    // cout << endl;
    // for(int i=0; i<4*n; i++) cout << tree[i] << " ";

    return 0;
}