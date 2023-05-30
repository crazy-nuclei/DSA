#include "../../myHeaders.h"
using namespace std;

void LPS(string &pattern, vector<int> &lps) {

    lps[0] = 0;
    for(int i = 1; i < pattern.length(); i++) {
        int len = lps[i-1];

        while(len > 0 && pattern[len] != pattern[i]) {
            len = lps[len-1];
        }

        if(pattern[i] == pattern[len]) {
            len += 1;
        }

        lps[i] = len;
    }
}

void KMP(string &text, string &pattern, vector<int> &ans) {
    int n = text.length();
    int m = pattern.length();

    vector<int> lps(m, 0);
    LPS(pattern, lps);

    int i = 0, j = 0;
    while(n-i >= m-j) {
        if(text[i] == pattern[j]) {
            i += 1;
            j += 1;
        }
        else {
            if(j != 0) {
                j = lps[j-1];
            } 
            else{
                i += 1;
            }
        }

        if(j == m) {
            ans.push_back(i-m);
            j = lps[j-1];
        }
    }
}

int main() {

    string text, pattern; cin >> text >> pattern;

    vector<int> ans;
    KMP(text, pattern, ans);

    cout << ans.size() << endl;

}

/*
onionionspl
onions

*/