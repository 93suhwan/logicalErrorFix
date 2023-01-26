#pragma GCC optimize("O2")
#include<bits/stdc++.h>
#define ll long long int
#define inf 1E18
#define ninf -1*1E18
#define mod 1000000007
#define fi first
#define si second
#define pb push_back
#define vi vector<long long int>
#define pi pair<long long int,long long int>
#define vpi vector<pair<long long int,long long int>>
#define vvi vector<vector<long long int>>
#define umii unordered_map<ll,ll>
#include<limits>
using namespace std;


void dfs1(ll node, vpi adj[], bool visited[], vi &nodes) {

     visited[node] = true;
     nodes.pb(node);
     for (auto child : adj[node]) {

          if (!visited[child.fi]) {
               dfs1(child.fi, adj, visited, nodes);
          }
     }
}

void dfs2(ll node, vpi adj[], bool visited[], int color[], ll &cnt, bool &ok) {

     if (color[node] == 1) {
          cnt++;
     }

     for (auto child : adj[node]) {

          if (color[child.fi] == -1) {
               color[child.fi] = (color[node] ^ child.si);
               dfs2(child.fi, adj, visited, color, cnt, ok);
          } else if (color[child.fi] != (color[node]^child.si)) {
               ok = false;
               return;
          }
          if (!ok) {
               return;
          }
     }
}


void answerNikalBc(ll t1) {

     ll n, m;
     cin >> n >> m;

     vpi adj[n + 1];

     for (ll i = 1; i <= m; i++) {

          ll u, v;
          string s;
          cin >> u >> v >> s;

          if (s == "crewmate") {
               adj[u].pb({v, 0});
               adj[v].pb({u, 0});
          } else {
               adj[u].pb({v, 1});
               adj[v].pb({u, 1});
          }
     }

     bool visited[n + 1] = {0};
     int color[n + 1];
     memset(color, -1, sizeof(color));
     bool ok = true;
     ll ans = 0;
     for (ll i = 1; i <= n; i++) {

          ll cnt1 = 0, cnt2 = 0;
          if (color[i] == -1) {
               vi nodes;
               color[i] = 0;
               dfs1(i, adj, visited, nodes);

               dfs2(i, adj, visited, color, cnt1, ok);
               for (auto a : nodes) {
                    visited[a] = false;
                    color[a] = -1;
               }
               color[i] = 1;
               dfs2(i, adj, visited, color, cnt2, ok);

               ans = max(cnt1, cnt2);

          }
     }

     if (!ok) {
          cout << -1 << "\n";
          return;
     }
     cout << ans << "\n";





}





int main() {


     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     ll t ;
     t = 1;



     // init();
     cin >> t;



     for (ll i = 1; i <= t; i++) {
          // cout << "Case #" << i << ": ";
          answerNikalBc(t);
     }



     cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;

     return 0;
}