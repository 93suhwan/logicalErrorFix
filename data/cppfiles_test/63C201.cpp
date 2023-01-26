#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> par1, rank1, par2, rank2;
int find(int p, vector<int>& par) {
  if (par[p] == p) return p;
  return par[p] = find(par[p], par);
}
bool Union(int p1, int p2, vector<int>& par, vector<int>& rank) {
  int par1 = find(p1, par), par2 = find(p2, par);
  if (par1 == par2) return 1;
  int u = rank[par1], v = rank[par2];
  if (u == v)
    par[par2] = par1, rank[par1]++;
  else if (u > v)
    par[par2] = par1;
  else
    par[par1] = par2;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(), cout.tie(0);
  ll n, p, q;
  cin >> n >> p >> q;
  par1.resize(n + 1);
  rank1.resize(n + 1, 0);
  par2.resize(n + 1);
  rank2.resize(n + 1, 0);
  for (int i = 0; i <= n; i++) par1[i] = i;
  for (int i = 0; i <= n; i++) par2[i] = i;
  vector<ll> g1[n + 1], g2[n + 1];
  for (int i = 0; i < p; i++) {
    ll x, y;
    cin >> x >> y;
    g1[x].push_back(y);
    g1[y].push_back(x);
    Union(x, y, par1, rank1);
  }
  for (int i = 0; i < q; i++) {
    ll x, y;
    cin >> x >> y;
    g2[x].push_back(y);
    g2[y].push_back(x);
    Union(x, y, par2, rank2);
  }
  ll ans = 0;
  vector<pair<int, int>> v;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int x = i, y = j;
      int p1 = find(x, par1), p2 = find(y, par1);
      if (p1 == p2) continue;
      p1 = find(x, par2), p2 = find(y, par2);
      if (p1 == p2) continue;
      Union(x, y, par1, rank1);
      Union(x, y, par2, rank2);
      ans++;
      v.push_back({x, y});
    }
  }
  cout << ans << endl;
  for (auto& x : v) cout << x.first << " " << x.second << endl;
}
