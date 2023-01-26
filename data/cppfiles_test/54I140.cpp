#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200007];
vector<long long> adj[200007];
long long color[200007], cnt[3];
bool ok;
long long fake;
void dfs(long long u) {
  if (u != fake) cnt[color[u]]++;
  for (auto v : adj[u]) {
    if (color[v] == color[u]) {
      ok = false;
    }
    if (color[v] == -1) {
      color[v] = 1 - color[u];
      dfs(v);
    }
  }
}
void read() {
  cin >> n >> m;
  for (long long i = 1; i <= n + 1; ++i) {
    adj[i].clear();
    color[i] = -1;
  }
  fake = n + 1;
  for (long long i = 1; i <= m; ++i) {
    long long x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    if (s == "crewmate") {
      adj[x].push_back(fake);
      adj[fake].push_back(x);
      adj[y].push_back(fake);
      adj[fake].push_back(y);
    } else {
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
  }
}
void solve() {
  long long ans = 0;
  for (long long i = 1; i <= n; ++i) {
    if (color[i] == -1) {
      ok = true;
      cnt[0] = cnt[1] = 0;
      color[i] = 0;
      dfs(i);
      if (ok == false) {
        cout << -1 << "\n";
        ;
        return;
      }
      ans += max(cnt[0], cnt[1]);
    }
  }
  cout << ans << "\n";
  ;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test;
  cin >> test;
  while (test--) {
    read();
    solve();
  }
  return 0;
}
