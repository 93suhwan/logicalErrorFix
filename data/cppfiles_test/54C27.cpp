#include <bits/stdc++.h>
using namespace std;
vector<int> colour;
vector<int> c(2);
vector<vector<pair<long long, long long> > > g;
bool ok;
void dfs(long long v) {
  c[colour[v]]++;
  for (auto i : g[v]) {
    if (colour[i.first] == -1) {
      colour[i.first] = colour[v] ^ i.second;
      dfs(i.first);
    } else if (colour[v] ^ colour[i.first] != i.second)
      ok = false;
  }
}
void solve() {
  long long n, m;
  cin >> n >> m;
  g = vector<vector<pair<long long, long long> > >(n + 1);
  colour = vector<int>(n + 1, -1);
  while (m--) {
    long long i, j;
    string s;
    cin >> i >> j >> s;
    if (s[0] == 'c') {
      g[i].push_back({j, 0});
      g[j].push_back({i, 0});
    } else {
      g[i].push_back({j, 1});
      g[j].push_back({i, 1});
    }
  }
  long long ans = 0;
  ok = true;
  for (int i = 1; i <= n; i++)
    if (colour[i] == -1) {
      c[0] = c[1] = 0;
      colour[i] = 0;
      dfs(i);
      ans += max(c[0], c[1]);
    }
  if (!ok) ans = -1;
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
