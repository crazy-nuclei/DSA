#include "../../myHeaders.h"
using namespace std;

string make_string(int i, int j, bool p) {
    string ans = to_string(i) + "*" + to_string(j) + "*";
    if(p == true) {
        ans += "true";
    }
    else {
        ans += "false";
    }
    return ans;
}

void mcm(vector<bool> &sym, vector<char> &ope, int i, int j, unordered_map<string, int> &mp) {
    string ijt = make_string(i, j, true);
    string ijf = make_string(i, j, false);

    if(mp[ijt] != 0 || mp[ijf] != 0) {
        return;
    }

    if(i >= j) {
        if(sym[i] == true) {
            mp[ijt] += 1;
        }
        else {
            mp[ijf] += 1;
        }
        return;
    }

    for(int k = i; k < j; k++) {
        string lt = make_string(i, k, true);
        string lf = make_string(i, k, false);

        string rt = make_string(k+1, j, true);
        string rf = make_string(k+1, j, false);

        mcm(sym, ope, i, k, mp);
        mcm(sym, ope, k+1, j, mp);

        if(ope[k] == '|') {
            mp[ijt] += mp[lt]*mp[rt] + mp[lt]*mp[rf] + mp[lf]*mp[rt];
            mp[ijf] += mp[lf]*mp[rf];
        }
        else if(ope[k] == '&') {
            mp[ijt] += mp[lt]*mp[rt];
            mp[ijf] += mp[lt]*mp[rf] + mp[lf]*mp[rt] + mp[lf]*mp[rf];
        }
        else {
            mp[ijt] += mp[lt]*mp[rf] + mp[lf]*mp[rt];
            mp[ijf] += mp[lt]*mp[rt] + mp[lf]*mp[rf];
        }
    }
}

void solve(vector<bool> &sym, vector<char> &ope) {
    unordered_map<string, int> mp;
    
    mcm(sym, ope, 0, sym.size()-1, mp);

    string ijt = make_string(0, sym.size()-1, true);
    string ijf = make_string(0, sym.size()-1, false);

    cout << "No of express resulting in truth : " << mp[ijt] << endl;
    cout << "No of express resulting in false : " << mp[ijf] << endl;
}

int main() {
    int n; cin >> n;
    vector<bool> sym(n);
    vector<char> ope(n-1);

    for(int i = 0; i < n; i++) {
        char p; cin >> p;
        if(p == 'T' || p == 't'){
            sym[i] = true;
        }
        else {
            sym[i] = false;
        }
        
    }

    for(int i = 0; i < n-1; i++) {
        cin >> ope[i];
    }

    solve(sym, ope);
}

/*

3
T F T
^ &

3
T F F
^ |

4
T T F T
| & ^

*/