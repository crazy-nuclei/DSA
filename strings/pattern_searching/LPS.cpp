#include "../../myHeaders.h"
using namespace std;

void LPS(string &pattern, vector<int> &lps) {
    lps[0] = 0;

    for(int i = 1; i < pattern.length(); i++) {
        int len = lps[i-1];
        
        while(len > 0 && pattern[i] != pattern[len]) {
            len = lps[len-1];
        }

        if(pattern[i] == pattern[len]) {
            len += 1;
        }
        lps[i] = len;
    }
}

void print_lps(vector<int> &lps) {
    for(int i = 0; i < lps.size(); i++) {
        cout << lps[i] << " ";
    }
}

int main() {

    string pattern; cin >> pattern;
    vector<int> lps(pattern.size());


    LPS(pattern, lps);

    print_lps(lps);
}

/*

onions

aaabaaac

aabaaac
*/