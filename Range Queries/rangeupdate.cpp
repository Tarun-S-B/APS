#include<iostream>
// #define unsigned long long int int
using namespace std;

const int MAXN = 200005;

int a[MAXN],n;                   // array of size up to 2e5, values ≤ 1e9
long long tree[4 * MAXN];      // each node may store sum up to 2e14
long long lazy[4 * MAXN];      // same reason as above


// int a[100000], tree[4*100005],lazy[4*100005],n;

void updateRange(int low, int high, int l, int r, int diff, int index) {
    // 1. Check if the lazy updation is still pending (condiition if leaf node)
    // 2. If complete out of range
    // 3. On complete overlap increment current tree{index} and add the increment to lazy childrens (condition if leaf node)
    // 4. Partial overlap go to left and right of mid
    
    
    // 1. Check if the lazy updation is still pending (condiition if leaf node)
    if(lazy[index]!=0) {
        tree[index] += (high-low+1) * lazy[index];
        if(low!=high) {
            lazy[2*index+1] += lazy[index];
            lazy[2*index+2] += lazy[index];
        }
        lazy[index] = 0;
    }
    
    // 2. If complete out of range
    if(low>r || high<l){
        return;
    }
    // 3. On complete overlap increment current tree{index} and add the increment to lazy childrens (condition if leaf node)
    if(low>=l && high<=r) {
        tree[index] += (high - low + 1)*diff;
        if(low!=high) {
            lazy[2*index+1] += diff;
            lazy[2*index+2] += diff;
        }
        return;
    }
    
    // 4. Partial overlap go to left and right of mid
    int mid = (low + high) / 2;
    updateRange(low,mid,l,r,diff,2*index+1);
    updateRange(mid+1,high,l,r,diff,2*index+2);
    tree[index] = tree[2*index+1] + tree[2*index+2];
    return;
}


unsigned long long int query(int low, int high, int l, int r, int index) {
    if(lazy[index]!=0) {
        tree[index] += (high-low+1)*lazy[index];
    }
    if(low!=high) {
        lazy[2*index+1] += lazy[index];
        lazy[2*index+2] += lazy[index];
    }
    lazy[index] = 0;

    if(low>=l && high<=r) {
        return tree[index];
    }
    if(r<low || l>high) {
        return 0;
    }
    int mid = (low+high) /2;
    return (query(low,mid,l,r,2*index+1) + query(mid+1,high,l,r,2*index+2));
}
// int query(int low, int high, int l, int r, int index) {
//     if(low>=l && high<=r) {
//         return tree[index];
//     }
//     if(r<low || l>high) {
//         return 0;
//     }
//     int mid = (low+high) /2;
//     return ( query(low,mid,l,r,2*index+1) + query(mid+1,high,l,r,2*index+2));
// }


void update(int low, int high, int target, int val, int index) {
    if(low == high) {
        if(low == target) {
            tree[index] = val;
            return;
        }
    }
    int mid = (low + high) / 2;
    if(target <= mid) {
        update(low, mid,target,val,2*index+1);
    } else {
        update(mid+1,high,target,val,2*index+2);
    }
    tree[index] = tree[2*index+1] + tree[2*index+2];
    return;
}


void build(int low, int high, int index) {
    if(low == high) {
        tree[index] = a [low];
        return;
    }
    int mid = (low+high) /2;
    build(low,mid,2*index+1);
    build(mid+1,high,2*index+2);
    tree[index] = tree[2*index+1] + tree[2*index+2];
    return;
}

int main() {
    int q;
    cin >> n >> q;
    for(int i=0; i<n; i++) cin >> a[i];
    
    build(0,n-1,0);
    // for(int i=0; i<4*n; i++) cout << tree[i] << " ";
    // cout << endl;
    

    int l,r,type,diff;
    while(q--) {
        cin >> type;
        if(type == 1) {
            cin >> l >> r >> diff;
            updateRange(0,n-1,l-1,r-1,diff,0);
        } else {
            cin >> diff;
            diff--;
            cout << query(0,n-1,diff,diff,0) << endl;
        }
    }
    // // update(0,n-1,2,10,0);
    // updateRange(0,n-1,0,3,5,0);
    // cout << query(0,n-1,0,2,0);
    // cout << endl;
    // for(int i=0; i<4*n; i++) cout << tree[i] << " ";
    // cout << endl;

    return 0;
}