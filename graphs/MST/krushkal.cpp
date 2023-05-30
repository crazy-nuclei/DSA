#include "../../myHeaders.h"
using namespace std;

void sorted_list(unordered_map<int, list<pair<int,int>>> &mp, set<pair<int, pair<int,int>>> &st ) {
    for(auto p : mp) {
        int u = p.first;
        for(auto pp : p.second) {
            int v = pp.first;
            int w = pp.second;

            int a = (u < v) ? u : v;
            int b = u + v - a;
            st.insert({w, {a,b}});
        }
    }
}

int find(vector<int> &parent, int u) {
    if(parent[u] != u) {
        parent[u] = find(parent, parent[u]);
    } 

    return parent[u];
}

void Union(vector<int> &parent, vector<int> &rank, int a, int b) {
    
    if(rank[a] < rank[b]) {
        parent[a] = b;
    }
    else if(rank[b] < rank[a]) {
        parent[b] = a;
    }
    else {
        parent[a] = b;
        rank[b] += 1;
    }
}

void mst_ds(set<pair<int, pair<int,int>>> &st, unordered_map<int, list<pair<int,int>>> &mst, int n) {
    
    vector<int> rank(n, 0), parent(n);
    for(int i =0; i < n; i++) {
        parent[i] = i;
    }

    int t = n-1;

    while(!st.empty() && t) {
        auto p = *(st.begin());
        st.erase(st.begin());
        int w = p.first;
        int u = p.second.first;
        int v = p.second.second;

        int a = find(parent, u);
        int b = find(parent, v);

        if( a != b) {
            t--; 
            Union(parent, rank, a, b);
            mst[u].push_back({v, w});
            mst[v].push_back({u, w});
        }
    }
}

void krushkal(unordered_map<int, list<pair<int,int>>> &mp, unordered_map<int, list<pair<int,int>>> &mst) {
    
    set<pair<int, pair<int,int>>> st;
    sorted_list(mp, st); 
    
    mst_ds(st, mst, mp.size());
    
}

void print_mst(unordered_map<int, list<pair<int,int>>> &mst) {
    set<pair<int,int>> st;
    int we = 0;

    for(auto p : mst) {
        int u = p.first;
        for(auto pp : p.second) {
            int v = pp.first;
            int w = pp.second;

            int a = (u < v) ? u : v;
            int b = u + v - a;

            if(st.find({a,b}) == st.end()) {
                st.insert({a, b});
                cout << a << " " << b << " " << w << endl;
                we += w;
            }
        }
    }
    cout << "Weight of mst = " << we << endl;
}

int main() {

    unordered_map<int, list<pair<int,int>>> mp; 

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--;
        v--;
        mp[u].push_back({v,w});
        mp[v].push_back({u,w});
    }
    unordered_map<int, list<pair<int,int>>> mst;

    krushkal(mp, mst);

    cout << mst.size() << endl;

    print_mst(mst);
}

/*
9
5 4 9 
5 1 4 
4 1 1 
4 3 5 
4 2 3 
1 2 2 
3 6 8
3 2 3
2 6 7
*/