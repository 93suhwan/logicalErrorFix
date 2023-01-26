#include <bits/stdc++.h>
using namespace std;
struct st {
  long long x;
  long long y;
  long long t;
  long long i;
};
const long long maxn = 2e5 + 10;
long long n, k;
vector<long long> e[maxn], vis(maxn);
vector<st> a;
void init() {
  for (long long i = 0; i <= n; ++i) {
    vis[i] = 0;
    e[i].clear();
  }
}
long long dfs(long long x) {
  vis[x] = 1;
  long long c = a[x].t;
  for (auto& i : e[x]) {
    if (!vis[i]) {
      c = min(dfs(i), c);
    }
  }
  return c;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  long long test;
  cin >> test;
  for (long long h = 0; h < test; ++h) {
    cin >> n >> k;
    init();
    a = vector<st>(n);
    map<long long, long long> mx, my;
    long long cx = 0, cy = 0;
    for (long long i = 0; i < n; ++i) {
      cin >> a[i].x >> a[i].y >> a[i].t;
      a[i].i = i;
      if (!mx[a[i].x]) {
        mx[a[i].x] = ++cx;
      }
      if (!my[a[i].y]) {
        my[a[i].y] = ++cy;
      }
    }
    set<pair<long long, long long> > sx[cx + 1], sy[cy + 1];
    for (long long i = 0; i < n; ++i) {
      sx[mx[a[i].x]].insert({a[i].y, i});
      sy[my[a[i].y]].insert({a[i].x, i});
    }
    for (pair<long long, long long> px : mx) {
      long long x = px.second, len = sx[x].size();
      pair<long long, long long> p = *sx[x].begin();
      long long last = p.first, ind = p.second;
      sx[x].erase(p);
      for (long long i = 1; i < len; ++i) {
        p = *sx[x].begin();
        sx[x].erase(p);
        long long kl = p.first, j = p.second;
        if (kl - last <= k) {
          e[j].push_back(ind);
          e[ind].push_back(j);
        }
        last = kl;
        ind = j;
      }
    }
    for (pair<long long, long long> px : my) {
      long long x = px.second, len = sy[x].size();
      pair<long long, long long> p = *sy[x].begin();
      long long last = p.first, ind = p.second;
      sy[x].erase(p);
      for (long long i = 1; i < len; ++i) {
        p = *sy[x].begin();
        sy[x].erase(p);
        long long kl = p.first, j = p.second;
        if (kl - last <= k) {
          e[j].push_back(ind);
          e[ind].push_back(j);
        }
        last = kl;
        ind = j;
      }
    }
    vector<long long> d;
    for (long long i = 0; i < n; ++i) {
      if (!vis[i]) {
        d.push_back(dfs(i));
      }
    }
    sort(d.rbegin(), d.rend());
    long long t = 0;
    for (long long i = 0; i < d.size(); ++i) {
      if (d[i] <= t) {
        break;
      }
      d[i] = t++;
    }
    cout << *max_element(d.begin(), d.end()) << '\n';
  }
}
