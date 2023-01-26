#include <bits/stdc++.h>
#pragma GCC target("popcnt")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native"
using namespace std;
template <typename T, typename K>
inline bool smax(T &x, const K &y) {
  return x < y ? x = y, true : false;
}
template <typename T, typename K>
inline bool smin(T &x, const K &y) {
  return x > y ? x = y, true : false;
}
const int mod = 1e9 + 7;
int add(int x, int y) {
  int z = x + y;
  if (z >= mod) {
    z -= mod;
  }
  return z;
}
int sub(int x, int y) {
  int z = x - y;
  if (z < 0) {
    z += mod;
  }
  return z;
}
int mul(int x, int y) {
  long long z = 1ll * x * y;
  if (z >= mod) {
    z %= mod;
  }
  return z;
}
int binpow(int a, long long p) {
  int r = 1;
  while (p) {
    if (p & 1) r = mul(r, a);
    a = mul(a, a), p >>= 1;
  }
  return r;
}
vector<vector<int>> g;
vector<int> in;
set<int> alive;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    g = vector<vector<int>>(n + 1);
    in = vector<int>(n + 1);
    for (int i = 1; i <= n; ++i) {
      int k;
      cin >> k;
      for (int j = 1; j <= k; ++j) {
        int x;
        cin >> x;
        g[x].push_back(i);
        in[i] += 1;
      }
    }
    alive.clear();
    int done = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) {
      if (in[i] == 0) {
        alive.insert(i);
      }
    }
    while (done != n) {
      if (alive.empty()) {
        cnt = 1e9;
        break;
      }
      ++cnt;
      int chapter = 0;
      auto it = alive.begin();
      while (!alive.empty() &&
             (it = alive.lower_bound(chapter)) != alive.end() &&
             *it > chapter) {
        int cur = *it;
        alive.erase(it);
        ++done;
        for (auto v : g[cur]) {
          in[v] -= 1;
          if (in[v] == 0) {
            alive.insert(v);
          }
        }
        chapter = cur;
      }
    }
    cout << (cnt < 1e9 ? cnt : -1) << endl;
  }
}
