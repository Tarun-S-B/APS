#include<iostream>

using namespace std;

int n;
int forest[1001][1001];
int prefix[1001][1001];

// 1 based indexing
// 1 based indexing if used to avoid the checking of negative numbers
void buildPrefix() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            prefix[i][j] = forest[i][j] + prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1];
        }
    }
}

int query(int x1, int y1, int x2, int y2) {
    // cout << prefix[x2][y2] << "-" << prefix[x1 - 1][y2] << "-" << prefix[x2][y1 - 1] << "+" << prefix[x1 - 1][y1 - 1] << endl;
    return (prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1]);
}

int main() {
    unsigned int q;
    cin >> n >> q;
    string str;
    for(int i=0; i<n; i++) {
        cin >> str;
        for(int j=0; j<n; j++) {
            forest[i+1][j+1] = str[j]=='*' ? 1 : 0;
        }
    }

    buildPrefix();

    // for(int i=0; i<=n; i++) {
    //     for(int j=0; j<=n; j++) {
    //         cout << prefix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int x1,y1,x2,y2;
    while(q--) {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << query(y1,x1,y2,x2) << endl;
    }   
}