#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, mod = 1e9 + 7;
long long pwr(long long b, long long p) {
  long long res = 1;
  while (p) {
    if (p % 2) res = res * b % mod;
    b = b * b % mod;
    p /= 2;
  }
  return res;
}
int k, n;
string colors[] = {"white", "yellow", "green", "blue", "red", "orange"};
map<string, int> ids;
int cant[7][7];
map<long long, int> node_color;
map<long long, set<long long>> adj;
long long dfs(long long p, long long c) {
  if (node_color.count(p) && node_color[p] != c) return 0;
  long long ret = 1;
  for (long long ch : adj[p]) {
    long long cur = 0;
    for (int i = 1; i <= 6; ++i) {
      if (cant[c][i]) continue;
      cur += dfs(ch, i);
      cur %= mod;
    }
    ret *= cur;
    ret %= mod;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 6; ++i) {
    ids[colors[i]] = i + 1, cant[i + 1][i + 1] = 1;
    if (i % 2 == 0) cant[i + 1][i + 2] = cant[i + 2][i + 1] = 1;
  }
  cin >> k >> n;
  set<int> used;
  while (n--) {
    long long node;
    string c;
    cin >> node >> c;
    int id = ids[c];
    node_color[node] = id;
    while (node != 1) {
      long long parent = node / 2;
      used.insert(node);
      used.insert(parent);
      adj[parent].insert(node);
      node = parent;
    }
  }
  long long color_ways = 0;
  for (int i = 1; i <= 6; ++i) {
    color_ways += dfs(1, i);
    color_ways %= mod;
  }
  long long rem = (1ll << k) - 1 - used.size();
  cout << color_ways * pwr(4, rem) % mod << endl;
  return 0;
}
