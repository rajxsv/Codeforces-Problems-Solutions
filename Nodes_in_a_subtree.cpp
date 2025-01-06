#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int,vector<int>> &adj, vector<vector<char>> &rel, vector<int> &vis, string &s) {
    rel[node].push_back(s[node]);
    vis[node] = 1;

    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs(nbr, adj, rel, vis, s);
            for (auto chars : rel[nbr]) {
                rel[node].push_back(chars);
            }
        }
    }
}

void solve() {

    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<vector<char>> rel(n);  
    vector<int> vis(n, 0);
    unordered_map<int,vector<int>> adj;
   
    for(int i = 0; i < n - 1; i++) {  
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    dfs(0, adj, rel, vis, s);  

    for (int i = 0; i < q; i++) {
        int node, cnt = 0;
        char ch;
        cin >> node >> ch;
        node--;  

        for (auto c : rel[node]) {
            if (c == ch) {
                cnt++;
            }
        }

        cout << cnt << endl;
    }
}

int main() {
    int t = 1;

    while(t--){
        solve();
    }
    return 0;
}
