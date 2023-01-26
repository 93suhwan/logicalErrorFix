#include <bits/stdc++.h>
using namespace std;
struct UnionFind {
  vector<int> par;
  vector<int> siz;
  vector<int> val;
  UnionFind(int N) {
    par.resize(N);
    siz.resize(N);
    val.resize(N);
    for (int i = 0; i < N; i++) {
      par[i] = i;
      siz[i] = 1;
      val[i] = i;
    }
  }
  int &operator[](const int &x) { return val[getParent(x)]; }
  int getParent(int x) {
    int t = x;
    while (par[x] != x) {
      x = par[x];
    }
    par[t] = x;
    return x;
  }
  int getSize(const int &x) { return siz[getParent(x)]; }
  bool merge(int x, int y) {
    x = getParent(x);
    y = getParent(y);
    if (x == y) {
      return false;
    }
    if (siz[x] > siz[y]) {
      swap(x, y);
    }
    par[x] = y;
    siz[y] += siz[x];
    val[y] = min(val[x], val[y]);
    return true;
  }
  bool connected(const int &x, const int &y) {
    return getParent(x) == getParent(y);
  }
};
struct mine {
  int x, y, t;
};
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int ttt;
  cin >> ttt;
  while (ttt--) {
    long long n, k;
    cin >> n >> k;
    vector<mine> m(n);
    UnionFind a(n);
    map<int, vector<pair<int, int>>> px, py;
    for (int i = 0; i < n; ++i) {
      cin >> m[i].x >> m[i].y >> m[i].t;
      a[i] = m[i].t;
      px[m[i].x].push_back({m[i].y, i});
      py[m[i].y].push_back({m[i].x, i});
    }
    for (auto &&[_y, v] : px) {
      sort(v.begin(), v.end());
      for (int i = 1; i < v.size(); ++i) {
        if (v[i - 1].first + k >= v[i].first) {
          a.merge(v[i].second, v[i - 1].second);
        }
      }
    }
    for (auto &&[_y, v] : py) {
      sort(v.begin(), v.end());
      for (int i = 1; i < v.size(); ++i) {
        if (v[i - 1].first + k >= v[i].first) {
          a.merge(v[i].second, v[i - 1].second);
        }
      }
    }
    vector<long long> vis;
    for (int i = 0; i < n; ++i) {
      if (a.getParent(i) == i) {
        vis.push_back(a[i]);
      }
    }
    sort(vis.rbegin(), vis.rend());
    ;
    long long ans = vis.size() - 1;
    for (long long i = 0; i + 1 < vis.size(); ++i) {
      ans = min(ans, max(i, vis[i + 1]));
    }
    cout << ans << "\n";
  }
}
