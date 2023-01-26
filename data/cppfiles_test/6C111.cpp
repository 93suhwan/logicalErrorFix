#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, i, j, k, p, t, m, q;
  cin >> n >> m;
  vector<set<long long int>> g(n + 1);
  for (j = 0; j < m; j++) {
    cin >> p >> q;
    g[p].insert(q);
    g[q].insert(p);
  }
  set<long long int> alive;
  for (int j = 1; j <= n; j++) {
    if (g[j].empty() || g[j].upper_bound(j) == g[j].end()) alive.insert(j);
  }
  cin >> q;
  long long int a, b, c;
  vector<long long int> ans;
  for (j = 0; j < q; j++) {
    cin >> a;
    if (a != 3) {
      if (a == 1) {
        cin >> b >> c;
        g[b].insert(c);
        g[c].insert(b);
        if (alive.find(b) != alive.end()) {
          if (g[b].upper_bound(b) != g[b].end()) alive.erase(b);
        }
        if (alive.find(c) != alive.end()) {
          if (g[c].upper_bound(c) != g[c].end()) alive.erase(c);
        }
      } else {
        cin >> b >> c;
        g[b].erase(c);
        g[c].erase(b);
        if (g[b].empty() || g[b].upper_bound(b) == g[b].end()) alive.insert(b);
        if (g[c].empty() || g[c].upper_bound(c) == g[c].end()) alive.insert(c);
      }
    } else
      ans.push_back(alive.size());
  }
  for (long long int a : ans) cout << a << endl;
}
