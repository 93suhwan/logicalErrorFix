#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int T, n, k;
vector<tuple<int, int, int>> ptsx, ptsy;
vector<int> tc;
struct DSU {
  vector<int> e;
  DSU(int N) { e = vector<int>(N, -1); }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool sameSet(int x, int y) { return get(x) == get(y); }
  void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y];
    e[y] = x;
    tc[x] = min(tc[x], tc[y]);
  }
  int size(int x) { return -e[get(x)]; }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  for (int z = 0; z < T; z++) {
    cin >> n >> k;
    ptsx = vector<tuple<int, int, int>>();
    ptsy = vector<tuple<int, int, int>>();
    for (int i = 0; i < n; i++) {
      int x, y, t;
      cin >> x >> y >> t;
      ptsx.push_back({x, y, i});
      ptsy.push_back({y, x, i});
      tc.push_back(t);
    }
    sort(ptsx.begin(), ptsx.end());
    sort(ptsy.begin(), ptsy.end());
    DSU d = DSU(n);
    for (int i = 0; i < n - 1; i++) {
      if (get<0>(ptsx[i + 1]) == get<0>(ptsx[i]) &&
          get<1>(ptsx[i + 1]) - get<1>(ptsx[i]) <= k) {
        d.unite(get<2>(ptsx[i + 1]), get<2>(ptsx[i]));
      }
      if (get<0>(ptsy[i + 1]) == get<0>(ptsy[i]) &&
          get<1>(ptsy[i + 1]) - get<1>(ptsy[i]) <= k) {
        d.unite(get<2>(ptsy[i + 1]), get<2>(ptsy[i]));
      }
    }
    vector<int> conn;
    for (int i = 0; i < n; i++) {
      ;
      if (d.e[i] < 0) {
        conn.push_back(tc[i]);
      }
    }
    sort(conn.begin(), conn.end());
    int ans = conn.size() - 1;
    for (int idx = 0; idx < conn.size(); idx++) {
      ans = min(ans, max(conn[idx], (int)conn.size() - idx - 2));
    }
    cout << ans << "\n";
  }
}
