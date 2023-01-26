#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
const long long mod = 1e9 + 7;
const int maxn = 2e5 + 10;
long long k, n;
map<string, int> cmap;
unordered_map<long long, int> hashmap;
int color[maxn];
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
long long mem[maxn][4];
long long getdp(long long u, int h, int col) {
  auto it = hashmap.find(u);
  if (it == hashmap.end()) {
    return memexp[k - h];
  }
  int hash = it->second;
  int match = color[hash];
  if (match && col != match) {
    return 0;
  }
  long long ans = (match ? 1 : 2);
  long long& memans = mem[hash][col];
  if (memans != -1) {
    return memans;
  }
  memans = ans;
  if (h + 1 < k) {
    for (long long v = 2 * u; v <= 2 * u + 1; v++) {
      long long subans = 0;
      for (int c = 1; c <= 3; c++) {
        if (c != col) {
          long long subsubans = getdp(v, h + 1, c);
          subans += subsubans;
          subans %= mod;
        }
      }
      memans *= subans;
      memans %= mod;
    }
  }
  memans %= mod;
  return memans;
}
int main() {
  memset(mem, -1, sizeof(mem));
  cin >> k >> n;
  for (int i = 0; i < 70; i++) {
    long long subtree_size = (1LL << i) - 2;
    memexp[i] = (2 * exp(4, subtree_size)) % mod;
  }
  cmap["white"] = 1;
  cmap["green"] = 2;
  cmap["red"] = 3;
  cmap["yellow"] = 1;
  cmap["blue"] = 2;
  cmap["orange"] = 3;
  for (int i = 0; i < n; i++) {
    long long node;
    string s;
    cin >> node >> s;
    int t = node;
    while (t) {
      if (!hashmap.count(t)) {
        int sz = hashmap.size();
        hashmap[t] = sz;
      }
      t /= 2;
    }
    color[hashmap[node]] = cmap[s];
  }
  long long ans = 0;
  ans += getdp(1, 0, 1);
  ans %= mod;
  ans += getdp(1, 0, 2);
  ans %= mod;
  ans += getdp(1, 0, 3);
  ans %= mod;
  cout << ans << endl;
}
