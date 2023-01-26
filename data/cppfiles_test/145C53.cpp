#include <bits/stdc++.h>
using namespace std;
int n, k, root[200005], d[200005];
struct mine {
  long long x, y;
  int time, id;
  mine() { x = -1000000007, y = -1000000007, time = 0, id = 0; }
} a[200005];
long long dist(mine a, mine b) { return a.x - b.x + a.y - b.y; }
int get_root(int u) { return (!root[u]) ? u : root[u] = get_root(root[u]); }
void add(int u, int v) {
  u = get_root(u);
  v = get_root(v);
  if (u != v) {
    root[u] = v;
    d[v] = min(d[v], d[u]);
  }
}
void Solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    root[i] = 0;
    cin >> a[i].x >> a[i].y >> a[i].time;
    d[i] = a[i].time;
    a[i].id = i;
  }
  sort(a + 1, a + n + 1, [](mine a, mine b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
  });
  for (int i = 1; i <= n; ++i) {
    if (a[i].x == a[i - 1].x) {
      if (dist(a[i], a[i - 1]) <= k) {
        add(a[i].id, a[i - 1].id);
      }
    }
  }
  sort(a + 1, a + n + 1, [](mine a, mine b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
  });
  for (int i = 1; i <= n; ++i) {
    if (a[i].y == a[i - 1].y) {
      if (dist(a[i], a[i - 1]) <= k) {
        add(a[i].id, a[i - 1].id);
      }
    }
  }
  sort(a + 1, a + n + 1, [](mine a, mine b) { return a.time < b.time; });
  vector<int> v;
  for (int i = 1; i <= n; ++i) {
    v.push_back(get_root(i));
  }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  for (auto &x : v) {
    x = d[x];
  }
  sort(v.begin(), v.end());
  int run = 0;
  for (int i = 0; i < v.size(); ++i) {
    while (run < v.size() && v[run] <= i) ++run;
    if (run + i + 1 >= v.size()) {
      cout << i << '\n';
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  if (fopen(""
            ".inp",
            "r")) {
    freopen(
        ""
        ".inp",
        "r", stdin);
    freopen(
        ""
        ".out",
        "w", stdout);
  }
  int t;
  cin >> t;
  while (t--) {
    Solve();
  }
  cerr << "Time collapse : " << fixed << setprecision(3)
       << 1.000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
