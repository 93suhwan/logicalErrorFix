#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
const int N = 5;
struct SegTree {
  struct V {
    vector<int> cost = vector<int>(6, 0);
    int len = 0;
  };
  V t[N * 4 + 10];
  static V merge(V a, V b) {
    V res;
    res.len = a.len + b.len;
    res.cost[0] = a.cost[0] + b.cost[(a.len + 0) % 3];
    res.cost[1] = a.cost[1] + b.cost[(a.len + 1) % 3];
    res.cost[2] = a.cost[2] + b.cost[(a.len + 2) % 3];
    res.cost[3] = a.cost[3] + b.cost[3 + (a.len + 4) % 3];
    res.cost[4] = a.cost[4] + b.cost[3 + (a.len + 5) % 3];
    res.cost[5] = a.cost[5] + b.cost[3 + (a.len + 3) % 3];
    return res;
  }
  void build(int v, int l, int r, char s[]) {
    t[v].len = r - l;
    if (r == l + 1) {
      if (s[l] == 'a') {
        t[v].cost[1] = t[v].cost[2] = t[v].cost[4] = t[v].cost[5] = 1;
      } else if (s[l] == 'b') {
        t[v].cost[0] = t[v].cost[2] = t[v].cost[3] = t[v].cost[5] = 1;
      } else {
        t[v].cost[0] = t[v].cost[1] = t[v].cost[3] = t[v].cost[4] = 1;
      }
      return;
    };
    int m = (r + l) / 2;
    build(v * 2 + 1, l, m, s);
    build(v * 2 + 2, m, r, s);
    t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
  }
  V get(int v, int l, int r, int L, int R) {
    if (l >= R || r <= L) {
      return V();
    }
    if (l >= L && r <= R) {
      return t[v];
    }
    int m = (r + l) / 2;
    return merge(get(v * 2 + 1, l, m, L, R), get(v * 2 + 2, m, r, L, R));
  }
  int get(int l, int r) {
    auto res = get(0, 0, N, l, r + 1);
    return *min_element((res.cost).begin(), (res.cost).end());
  }
};
SegTree t;
char s[N];
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  t.build(0, 0, N, s);
  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    cout << t.get(l - 1, r - 1) << '\n';
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(12);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
