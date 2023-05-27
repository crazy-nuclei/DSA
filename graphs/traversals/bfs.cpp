#include "../../myHeaders.h"
using namespace std;

void bfs( unordered_map<int, list<int>> &mp, int &src ) {
    
    unordered_map<int, int> vis;
    queue<int> se; 

    se.push(src);
    vis[src] = 1;

    while(!se.empty()) {
        int p = se.front(); se.pop();

        cout << p << endl; 

        for(auto q : mp[p]) {
            if(vis[q] == 0) {
                se.push(q);
                vis[q] = 1;
            }
        }
    }
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

    bfs(mp, src);
    
}

/* 

5
1 2
1 3
1 4
3 5
5 6
1

4
4 1
4 2
2 3
1 3
4

*/