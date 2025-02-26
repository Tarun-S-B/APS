#include<iostream>
#include<string>
#include<climits>

using namespace std;

int main() {
    string a;
    cin >> a;
    int l=0,r=0;
    int n = a.length();
    char c;
    int maxlen = INT_MIN;
    while(l<n) {
        c = a[l];
        r = l;
        while(a[r] == c) {
            r++;
        }
        maxlen = max(maxlen,(r-l));
        l = r;
    }
    cout << maxlen;
    return 0;
}