#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5;
long long sz[maxn];
long long id[maxn];
vector<long long> g[maxn];
long long pred[maxn];
long long n;
void dfs(long long v, long long p) {
  pred[v] = p;
  sz[v] = 0;
  id[v] = -1;
  for (long long i = 0; i < g[v].size(); ++i) {
    long long to = g[v][i];
    if (to == p) continue;
    dfs(to, v);
    if (sz[v] < sz[to] + 1) {
      id[v] = to;
    }
    sz[v] = max(sz[v], sz[to] + 1);
  }
}
vector<pair<long long, long long>> calc(long long v) {
  vector<long long> all;
  all.push_back(v);
  while (id[v] != -1) {
    all.push_back(v);
    v = id[v];
  }
  vector<pair<long long, long long>> ans;
  ans.push_back({all.size(), v});
  for (long long i = 0; i < all.size(); ++i) {
    long long ver = all[i];
    for (long long j = 0; j < g[ver].size(); ++j) {
      long long to = g[ver][j];
      if (to == pred[ver] || to == id[ver]) continue;
      auto tmp = calc(to);
      for (long long k = 0; k < tmp.size(); ++k) {
        ans.push_back(tmp[k]);
      }
    }
  }
  sort(ans.begin(), ans.end());
  for (long long l = 0; l < (long long)all.size() - 1; ++l) {
    ans.push_back({0, all[l]});
  }
  return ans;
}
long long cnt_bad = 0;
long long cnt_red = 0;
long long ans = -1e18;
void f() {
  long long r = cnt_red;
  long long w = cnt_bad - cnt_red;
  long long b = n - cnt_bad;
  long long le = -1;
  long long ri = b;
  while (le + 1 != ri) {
    long long mid = (le + ri) / 2;
    long long val1 = (w + b - mid) * (r - mid);
    long long val2 = (w + b - (mid + 1)) * (r - (mid + 1));
    if (val1 < val2) {
      ri = mid;
    } else {
      le = mid;
    }
  }
  ans = max(ans, (w + b - ri) * (r - (ri)));
}
signed main() {
  cin.tie();
  cout.tie();
  ios_base::sync_with_stdio(false);
  long long k;
  cin >> n >> k;
  for (long long i = 0; i < n - 1; ++i) {
    long long a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  f();
  dfs(0, -1);
  vector<pair<long long, long long>> all = calc(0);
  reverse(all.begin(), all.end());
  for (long long j = 0; j < k; ++j) {
    cnt_red++;
    cnt_bad += all[j].first;
    f();
  }
  cout << ans << "\n";
}
