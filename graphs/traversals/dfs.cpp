#include "../../myHeaders.h"
using namespace std;

void dfs_p(unordered_map<int, list<int>> &mp, unordered_map<int,int> &vis, int p) {

    vis[p] = true;
    cout << p << endl;
    for(auto q : mp[p]) {
        if(vis[q] == 0 ) dfs_p(mp, vis, q);
    }
}

void dfs( unordered_map<int, list<int>> &mp, int &src ) {
    
    unordered_map<int,int> vis;
    dfs_p(mp, vis, src);
}

int main() {

    unordered_map<int, list<int>> mp;
    int src; 

    int n; cin >> n;
    for(int i =0 ; i < n; i++) {
        int p, q; cin >> p >> q;
        mp[p].push_back(q);
        mp[q].push_back(p);
    }
    
    cin >> src;

    dfs(mp, src);
    
}

/*

5
1 2
1 3
1 4
2 5
5 6

*/