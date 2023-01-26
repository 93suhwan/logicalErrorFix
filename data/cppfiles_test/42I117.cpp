#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
const int tam = 1000010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF = 1e100;
const double EPS = 1e-9;
const double PI = acos(-1);
int t[4 * tam], lazy[4 * tam];
void push(int node, bool bo) {
  t[node] += lazy[node];
  if (bo) lazy[node * 2 + 1] += lazy[node], lazy[node * 2 + 2] += lazy[node];
  lazy[node] = 0;
}
void update(int b, int e, int node, int i, int j, int val) {
  push(node, b != e);
  if (b > j || e < i) return;
  if (b >= i && e <= j) {
    lazy[node] += val;
    push(node, b != e);
    return;
  }
  int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
  ;
  update(b, mid, l, i, j, val);
  update(mid + 1, e, r, i, j, val);
  t[node] = min(t[l] + lazy[l], t[r] + lazy[r]);
}
vector<pair<int, int> > seg[tam];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, a, b, c;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    seg[c].push_back({a, b});
  }
  update(1, m, 0, 1, 1, 1);
  update(1, m, 0, m, m, 1);
  int to = 1, res = MOD;
  for (int i = 1; i < tam; i++) {
    while (to < tam && t[0] < 2) {
      for (pair<int, int> cat : seg[to]) {
        update(1, m, 0, cat.first, cat.second, 2);
        update(1, m, 0, cat.first, cat.first, -1);
        update(1, m, 0, cat.second, cat.second, -1);
      }
      to++;
    }
    if (t[0] > 1) res = min(res, to - 1 - i);
    for (pair<int, int> cat : seg[i]) {
      update(1, m, 0, cat.first, cat.second, -2);
      update(1, m, 0, cat.first, cat.first, 1);
      update(1, m, 0, cat.second, cat.second, 1);
    }
  }
  cout << res << '\n';
  return 0;
}
