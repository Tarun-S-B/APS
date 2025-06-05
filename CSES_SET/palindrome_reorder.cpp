#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    // Intialise the count array to keep track of the characters
    int count[26] = {0};

    string s;
    cin >> s;
    for(char c : s) {
        count[c-'A']++;
    }

    // Count the odd occurence of character in the string
    int countOdd = 0;
    for(int i=0; i<26; i++) {
        if(count[i]&1)
            countOdd++;
    }

    // if there are more than 1 odd occurence, then the palindrome isn't possible
    if(countOdd > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    string ans = "";

    // get the index of odd occurence of the characrter if any
    countOdd = -1;
    for(int i=0; i<26; i++) {
        if(count[i]&1)
            countOdd = i;
    }

    // Build the first half of the palindrome
    for(int i=0; i<26; i++) {
        // skip the middle element
        if(i == countOdd) 
            continue;
        else if(count[i]) {
            for(int j=0; j<count[i]/2; j++) {
                ans += i + 'A';
            }
        }
    }

    // store the length of the first half
    int n = ans.length();

    // add the middle element if any. (Odd occurence)
    if(countOdd != -1) {
        for(int i=0; i<count[countOdd]; i++)
        ans += countOdd + 'A';
    }

    // Build the second half, reverse if first half
    for(int i=n-1; i>=0; i--) {
        ans += ans[i];
    }

    // Output the Answer
    cout << ans;

    return 0;
}