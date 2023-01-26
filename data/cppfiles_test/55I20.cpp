#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int M = 1e9 + 7;
int n, m, ind, l, r;
int prv[N], a[2 * N];
struct Interv {
  int ind, l, r;
} interv[N];
pair<int, int> arb[8 * N], lazy[8 * N];
void push(int node) {
  if (node * 2 >= 8 * N || !lazy[node].first) return;
  lazy[node * 2] = arb[node * 2] = lazy[node];
  lazy[node * 2 + 1] = arb[node * 2 + 1] = lazy[node];
  lazy[node] = {0, 0};
}
void setValue(int node, int l, int r, int L, int R, pair<int, int> value) {
  if (L > R) return;
  push(node);
  if (L <= l && r <= R) {
    if (arb[node] < value) {
      arb[node] = value;
      lazy[node] = value;
    }
    return;
  }
  int mid = (l + r) / 2;
  setValue(node * 2, l, mid, L, min(R, mid), value);
  setValue(node * 2 + 1, mid + 1, r, max(L, mid + 1), R, value);
  arb[node] = max(arb[node * 2], arb[node * 2 + 1]);
}
pair<int, int> query(int node, int l, int r, int L, int R) {
  if (L > R) return {INT_MIN, 0};
  push(node);
  if (L <= l && r <= R) return arb[node];
  int mid = (l + r) / 2;
  return max(query(node * 2, l, mid, L, min(R, mid)),
             query(node * 2 + 1, mid + 1, r, max(L, mid + 1), R));
}
bool inline cmp(Interv a, Interv b) { return a.ind < b.ind; }
signed main() {
  int t = 0, i, j, row;
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    cin >> ind >> l >> r;
    interv[i] = {ind, l, r};
    a[++t] = l;
    a[++t] = r;
  }
  sort(a + 1, a + t + 1);
  int y = 0;
  for (i = 2; i <= t + 1; i++)
    if (a[i] != a[i - 1]) a[++y] = a[i - 1];
  t = y;
  for (i = 1; i <= m; i++) {
    interv[i].l = lower_bound(a + 1, a + t + 1, interv[i].l) - a;
    interv[i].r = lower_bound(a + 1, a + t + 1, interv[i].r) - a;
  }
  sort(interv + 1, interv + m + 1, cmp);
  pair<int, int> ans = {0, 0};
  pair<int, int> mx = {0, 0};
  for (row = 1; row <= m + 1; row++) {
    if (interv[row].ind != interv[row - 1].ind && row > 1) {
      for (i = row - 1; interv[i].ind == interv[row - 1].ind; i--)
        setValue(1, 1, 2 * n, interv[i].l, interv[i].r,
                 {mx.first + 1, interv[i].ind});
      prv[interv[row - 1].ind] = mx.second;
      ans = max(ans, {mx.first + 1, interv[row - 1].ind});
      mx = {0, 0};
    }
    if (row <= m)
      mx = max(mx, query(1, 1, 2 * n, interv[row].l, interv[row].r));
  }
  set<int> choose;
  row = ans.second;
  do {
    choose.insert(row);
    row = prv[row];
  } while (row);
  cout << n - choose.size() << '\n';
  for (i = 1; i <= n; i++)
    if (choose.count(i) == 0) cout << i << ' ';
  return 0;
}
