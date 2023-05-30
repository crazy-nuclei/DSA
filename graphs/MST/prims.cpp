#include "../../myHeaders.h"
using namespace std;

void prims(unordered_map<int, list<pair<int,int>>> &mp, unordered_map<int, list<pair<int,int>>> &mst) {
    unordered_set<int> sel ;
    vector<int> dis(mp.size(), INT_MAX);
    set<pair<int,int>> st;
    unordered_map<int,int> parent;

    st.insert({0,0});
    dis[0] = 0;
    parent[0] = 0;

    while(sel.size() != mp.size()) {
        auto p = *(st.begin());
        st.erase(st.begin()); 

        int w = p.first;
        int node = p.second;
        sel.insert(node);
        if(parent[node] != node ) {
            mst[node].push_back({parent[node], w});
            mst[parent[node]].push_back({node, w});
        }

        for(auto pp : mp[node]) {
            int ww = pp.second;
            int v = pp.first;

            if(sel.find(v) == sel.end() && dis[v] > ww) {
                auto pp = st.find({dis[v], v});
                if(pp != st.end()) {
                    st.erase(pp);
                }
                st.insert({ww, v});
                dis[v] = ww;
                parent[v] = node;
            }
        }

    }
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
    for(int i = 0; i < n; i++ ) {
        int u,v,w; cin >> u >> v >> w;
        u--;
        v--;
        mp[u].push_back({v,w});
        mp[v].push_back({u,w});
    }

    unordered_map<int, list<pair<int,int>>> mst;

    prims(mp, mst);

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

6
4 1 6
4 2 8
1 2 2
2 3 3
2 5 5
5 3 7
*/
