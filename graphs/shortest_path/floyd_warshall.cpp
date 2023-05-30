#include "../../myHeaders.h"
using namespace std;

void initi(unordered_map<int, list<pair<int,int>>> &mp, vector<vector<int>> &dis) {
    for(int i =0; i < mp.size(); i++) {
        dis[i][i] = 0;
    }

    for(auto p : mp) {
        int u = p.first;
        for(auto pp : p.second) {
            int v = pp.first;
            int w = pp.second;

            dis[u][v] = w;
        }
    }
}

void floyd(unordered_map<int, list<pair<int,int>>> &mp, vector<vector<int>> &dis) {
    initi(mp, dis);

    for(int via = 0; via < mp.size(); via++) {
        for(int i = 0; i < mp.size(); i++) {
            for(int j = 0; j < mp.size(); j++) {
                dis[i][j] = min(dis[i][j], dis[i][via] + dis[via][j]);
            }
        }
    }
}

void neg_cycle(vector<vector<int>> &dis) {
    int p = 0;
    for(int i =0; i < dis.size(); i++) {
        if(dis[i][i] < 0) {
            p = 1;
            break;
        }
    }
    if(p == 1) {
        cout << "The graph has negative cycle" << endl;
    }
    else {
        cout << "The graph does not have negative cycle" << endl;
    }
}

void print_dis(vector<vector<int>> &dis) {

    for(int i = 0; i < dis.size(); i++) {
        for(int j =0; j < dis.size(); j++ ) {
            cout << dis[i][j] << "    ";
        }
        cout << endl;
        cout << endl;
    }
}

int main() {

    unordered_map<int, list<pair<int,int>>> mp;

    int dir; cin >> dir;
    int n; cin >> n; 
    for(int i = 0; i < n; i++) {
        int u,v,w; cin >> u >> v >> w;
        mp[u].push_back({v,w});
        mp[v].push_back({u,w});
        if(dir) {
            mp[v].pop_back();
        }
    }

    vector<vector<int>> dis(mp.size(), vector<int> (mp.size(), INT_MAX/2));
    floyd(mp, dis);
    neg_cycle(dis);
    print_dis(dis);
}

/*
1
6
0 1 2
1 0 1
1 2 3
3 0 3
3 1 5
3 2 4
*/