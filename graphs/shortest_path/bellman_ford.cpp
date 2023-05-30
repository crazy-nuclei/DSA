#include "../../myHeaders.h"
using namespace std;

void bellman(unordered_map<int, list<pair<int,int>>> &mp, vector<int> &dis, int src ) {
    
    dis[src] = 0;
    for(int i =0; i < mp.size()-1; i++) {
        for(auto p : mp) {
            int node = p.first;
            for(auto pp : mp[node]) {
                int v = pp.first;
                int w = pp.second;

                if(dis[v] > dis[node] + w) {
                    dis[v] = dis[node] + w;
                }
            }
        }
    }
}

void print_dis(vector<int> &dis) {
    for(int i = 0; i < dis.size(); i++) {
        cout << i << " " << dis[i] << endl;
    }
}

void neg_cycle(unordered_map<int, list<pair<int,int>>> &mp, vector<int> &dis) {

        int br = 0;
        for(auto p : mp) {
            int node = p.first;
            for(auto pp : mp[node]) {
                int v = pp.first;
                int w = pp.second;

                if(dis[v] > dis[node] + w) {
                    br = 1;
                    break;
                    dis[v] = dis[node] + w;
                }
            }
            if(br == 1) break;
        }

        if(br == 1) {
            cout << "The graph contains negative cycle" << endl;
        }
        else {
            cout << "The graph does not contain negative cycle" << endl;
        }
} 

int main() {
    
    unordered_map<int, list<pair<int,int>>> mp;

    int dir; cin >> dir;

    int n; cin >> n;
    for(int i =0; i <n; i++) {
        int u,v,w; cin >> u >> v >> w;
        mp[u].push_back({v,w});
        mp[v].push_back({u,w});
        if(dir) {
             mp[v].pop_back();
        }
    }

    vector<int> dis(mp.size(), INT_MAX/2);
    int src; cin >> src;
    bellman(mp, dis, src);

    neg_cycle(mp, dis);
    
    print_dis(dis);
}

/*
1
7
3 2 6
5 3 1
0 1 5
1 5 -3
1 2 -2
3 4 -2 
2 4 3
0

0
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