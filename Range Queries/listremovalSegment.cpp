#include<iostream>

using namespace std;

int n;
int tree[8*100000];
int a[2*100000];

void buildAliveTree(int low, int high, int index) {
    if(low == high) {
        tree[index] = 1;
        return;
    }
    int mid = (low+high)/2;
    buildAliveTree(low,mid,2*index+1);
    buildAliveTree(mid+1,high,2*index+2);
    tree[index] = tree[2*index+1] + tree[2*index+2];
    return;
}

int getRemoved(int low, int high, int pos, int index) {
    if(low == high) {
        // if(pos == low) {
        //     tree[index] = 0;
        //     return a[low];
        // } 

        tree[index] = 0;
        return a[low];
        
    }
    int mid = (low + high) / 2,ans;
    // if(tree[2*index+1]>pos) {
    if(pos < tree[2*index+1]) {
        ans = getRemoved(low,mid,pos,2*index+1);
    } else {
        // Remember to subtract the left child which going to right from the pos
        ans = getRemoved(mid+1,high,pos - tree[2*index+1],2*index+2);
    }
    tree[index] = tree[2*index+1] + tree[2*index+2];
    return ans;
}

int main() {
    int x;
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];

    buildAliveTree(0,n-1,0);
    // cout << "Alive: ";
    // for(int i=0; i<2*n-1; i++) cout << tree[i] << " ";
    // cout << endl;

    for(int i=0;i<n;i++) {
        cin >> x;
        cout << getRemoved(0,n-1,x-1,0) << " ";
        // cout << "Alive: ";
        // for(int i=0; i<2*n-1; i++) cout << tree[i] << " ";
        // cout << endl;
    }

}