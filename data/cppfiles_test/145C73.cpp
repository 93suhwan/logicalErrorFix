#include <bits/stdc++.h>
using namespace std;
const int N = 2000005;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long M = 1e18;
long long qpow(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
int n, k;
int a[N], b[N], c[N], fa[N], ans[N], vis[N];
map<int, vector<pair<int, int>>> m1, m2;
multiset<int> second;
int get(int x) {
  if (fa[x] == x) return x;
  return fa[x] = get(fa[x]);
}
void merge(int x, int y) {
  x = get(x);
  y = get(y);
  if (x == y) return;
  fa[x] = y;
  ans[y] = min(ans[y], ans[x]);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int tt = 1;
  cin >> tt;
  for (int t = 1; t <= tt; t++) {
    cin >> n >> k;
    vis[0] = 0;
    ans[0] = 0;
    int x, y;
    for (int i = 1; i <= n; i++) {
      vis[i] = 0;
      fa[i] = i;
      cin >> x >> y >> c[i];
      a[i] = x;
      b[i] = y;
      ans[i] = c[i];
      m1[x].push_back({y, i});
      m2[y].push_back({x, i});
    }
    for (auto it : m1) {
      sort(it.second.begin(), it.second.end());
      int last = -1;
      for (auto ff : it.second) {
        if (last != -1) {
          if (b[ff.second] - b[last] <= k) merge(ff.second, last);
        }
        last = ff.second;
      }
    }
    for (auto it : m2) {
      sort(it.second.begin(), it.second.end());
      int last = -1;
      for (auto ff : it.second) {
        if (last != -1) {
          if (a[ff.second] - a[last] <= k) merge(ff.second, last);
        }
        last = ff.second;
      }
    }
    m1.clear();
    m2.clear();
    for (int i = 1; i <= n; i++) {
      int x = get(i);
      if (vis[x]) continue;
      vis[x] = 1;
      second.insert(ans[x]);
    }
    int r = 0;
    while (!second.empty()) {
      auto it = second.end();
      it--;
      if (*it <= r) {
        break;
      }
      second.erase(it);
      while (!second.empty()) {
        auto ff = second.begin();
        if (*ff > r) break;
        second.erase(second.begin());
      }
      if (second.size() == 0) break;
      r++;
    }
    second.clear();
    cout << r;
    cout << "\n";
  }
  return 0;
}
