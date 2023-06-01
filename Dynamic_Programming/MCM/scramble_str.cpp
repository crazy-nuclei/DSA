#include "../../myHeaders.h"
using namespace std;

bool check(string s1, string s2, int i, int j) {
    bool aa = true;
    bool bb = true;
    
    for(int k = i; k <= j; k++) {
        if(s1[k] != s2[k]) {
            aa = false;
        }
        if(s1[k] != s2[j-k+i]){
            bb = false;
        }
    }

    return aa | bb;
}

bool mcm(string s1, string s2, int i, int j, vector<vector<int>> &dp) {
    
    if(dp[i][j] != -1) {
        if(dp[i][j] == 1) {
            return true;
        }
        else return false;
    }

    if(i >= j) {
        if(s1[i] == s2[i]) {
            return true;
        }
        else {
            return false;
        }
    }

    if(check(s1, s2, i, j)) {
        return dp[i][j] = true;
    }

    bool ans = false;
    for(int k = i; k < j; k++) {
        bool aa = mcm(s1, s2, i, k, dp);
        bool bb = mcm(s1, s2, k+1, j, dp);

        ans = aa&bb;
        if(ans == true) break;
    }

    return dp[i][j] = ans;
}

void solve(string s1, string s2) {
    if(s1.length() != s2.length()) {
        cout << "s2 is not the scrambled string of s1" << endl;
    }

    vector<vector<int>> dp(s1.length(), vector<int> (s1.length(), -1));

    bool ans = mcm(s1, s2, 0, s1.length()-1, dp);
    
    if(ans) {
        cout << "s2 is scrambled string of s1" << endl;
    }
    else {
        cout << "s2 is not scrambled string of s1" << endl;
    }
}

int main() {
    string s1, s2; cin >> s1 >> s2;
    solve(s1, s2);
}

/*
phqtrnilf
ilthnqrpf

rgtae
great

we 
we
*/