#include "../../myHeaders.h"
using namespace std;

void cal_prim(vector<int> &prim_pow, int p, int q) {
     for(int i = 0; i < prim_pow.size(); i++) {
        if(i == 0) {
            prim_pow[i] = p;
            continue;
        }
        prim_pow[i] = prim_pow[i-1]*p;
        prim_pow[i] %= q;
     }
}

void cal_hash(string patt, vector<int> &prim_pow, int q, int &hash) {
    for(int i = 0; i < prim_pow.size(); i++) {
        hash += (patt[i]-'a' +1)*prim_pow[prim_pow.size()-1-i];
        hash %= q;
    }
}

void roll_hash(string&text, string&pattern, vector<int> &maybe) {

    int n = text.length();
    int m = pattern.length();

    int p = 17;
    int q = 1e8 + 7;

    vector<int> prim_pow(m);
    cal_prim(prim_pow, p, q);

    int te_hash = 0, pat_hash = 0; 
    cal_hash(text, prim_pow, q, te_hash); 
    cal_hash(pattern, prim_pow, q, pat_hash); 

    for(int i = 0; i <= n-m; i++) {
        
        if(i == 0 ) {
            if(te_hash == pat_hash) { 
                maybe.push_back(i);
            }
            continue;
        }
        te_hash -= (text[i-1]-'a' +1)*prim_pow[m-1];
        while(te_hash < 0) te_hash += q;
        te_hash %= q;
        te_hash = (te_hash + text[i+m-1]-'a' +1)*prim_pow[0];
        te_hash %= q;

        if(te_hash == pat_hash) {
            maybe.push_back(i);
        }
    }
}

void confirm(string text, string pattern, vector<int> &maybe, vector<int> &ans) {

    for(int i = 0; i < maybe.size(); i++) {
        int p =1 ;
        for(int j = maybe[i], pa = 0; j < maybe[i]+pattern.size(); j++, pa++) {
            if(pattern[pa] != text[j] ) {
                p = 0;
                break;
            }
        }
        if(p) ans.push_back(maybe[i]);
    }
}

void RK(string &text, string &pattern, vector<int> &ans) {
    vector<int> maybe;
    
    roll_hash(text, pattern, maybe);

    confirm(text, pattern, maybe, ans);
}


int main() {

    string text, pattern;
    cin >> text >> pattern;

    vector<int> ans;

    RK(text, pattern, ans);

    cout << ans.size() << endl;
}

/*
oooo
oo

ponions
onions

pp
pp

geeksforgeeks
geeks


*/