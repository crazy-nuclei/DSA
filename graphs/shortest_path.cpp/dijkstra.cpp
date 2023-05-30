#include "../../myHeaders.h"
using namespace std;

void dij(unordered_map<int, list<pair<int,int>>> &mp, vector<int> &dis, int src) {
    set<pair<int,int>> st;
    dis[src] = 0;
    st.insert({dis[src], src});

    while(!st.empty()) {
        auto p = *(st.begin());
        st.erase(st.begin());
        int node = p.second;
        int w = p.first;

        for(auto pp : mp[node]) {
            int v = pp.first;
            int ww = pp.second;

            if(dis[v] > w + ww) {
                auto p = st.find({dis[v], v});
                if(p != st.end()) {
                    st.erase(p);
                }
                dis[v] = w + ww;
                st.insert({dis[v], v});
            }
        }
    }
}

void print_dis(vector<int> &dis) {
    for(int i = 0; i < dis.size(); i++) {
        cout << i << " " << dis[i] << endl;
    }
}

int main() {
    
    unordered_map<int, list<pair<int,int>>> mp;
    
    int n; cin >> n; 
    for(int i =0 ; i< n; i++) {
        int u,v,w; cin >> u >> v >> w;

        mp[u].push_back({v,w});
        mp[v].push_back({u,w});
    }

    vector<int> dis(mp.size(), INT_MAX);
    int src; cin >> src;

    dij(mp, dis, src);

    print_dis(dis);
}

/*
8
0 2 4 
0 1 4
1 2 2 
2 3 3
2 4 1
2 5 6 
3 5 2
5 4 3
0
*/