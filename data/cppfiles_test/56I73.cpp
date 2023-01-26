#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
const long long mod = 1e9 + 7;
const int maxn = 2e5 + 10;
long long k, n;
map<string, int> cmap;
unordered_map<long long, int> color;
long long exp(long long x, long long pow) {
  if (pow == 0) {
    return 1;
  } else if (pow == 1) {
    return x;
  } else if (pow % 2 == 0) {
    return exp((x * x) % mod, pow / 2);
  } else if (pow % 2 == 1) {
    return (x * exp((x * x) % mod, (pow - 1) / 2)) % mod;
  }
}
long long memexp[70];
long long find_height(long long u) {
  long long h = 0;
  while (u) {
    h++;
    u /= 2;
  }
  return h;
}
map<pair<long long, int>, long long> mem;
long long getdp(long long u, int h, int col, long long max_node,
                unordered_map<long long, int>& non_trivial) {
  if (color[u] && col != color[u]) {
    return 0;
  }
  auto it = mem.find({u, col});
  if (it != mem.end()) {
    return it->second;
  }
  long long& ans = mem[{u, col}];
  ans = (color[u] ? 1 : 2);
  if (!non_trivial[u]) {
    ans *= memexp[k - h];
    ans %= mod;
    return ans;
  }
  for (long long v = 2 * u; v <= 2 * u + 1; v++) {
    if (v <= max_node) {
      long long subans = 0;
      for (int c = 1; c <= 3; c++) {
        if (c != col) {
          long long subsubans = getdp(v, h + 1, c, max_node, non_trivial);
          subans += subsubans;
          subans %= mod;
        }
      }
      ans *= subans;
      ans %= mod;
    }
  }
  ans %= mod;
  return ans;
}
int main() {
  cin >> k >> n;
  for (int i = 0; i < 70; i++) {
    long long subtree_size = (1LL << i) - 2;
    memexp[i] = exp(4, subtree_size);
  }
  cmap["white"] = 1;
  cmap["green"] = 2;
  cmap["red"] = 3;
  cmap["yellow"] = 1;
  cmap["blue"] = 2;
  cmap["orange"] = 3;
  long long max_node = (1 << k) - 1;
  unordered_map<long long, int> non_trivial;
  for (int i = 0; i < n; i++) {
    long long node;
    string s;
    cin >> node >> s;
    color[node] = cmap[s];
    while (node) {
      non_trivial[node] = 1;
      node /= 2;
    }
  }
  long long ans = 0;
  ans += getdp(1, 0, 1, max_node, non_trivial);
  ans %= mod;
  ans += getdp(1, 0, 2, max_node, non_trivial);
  ans %= mod;
  ans += getdp(1, 0, 3, max_node, non_trivial);
  ans %= mod;
  cout << ans << endl;
}
