#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const long long inf = 1e15 + 10;
vector<long long> a(maxn);
vector<pair<long long, long long> > tree(maxn * 4);
void build(int v, int t_l, int t_r) {
  if (t_l == t_r) {
    tree[v] = make_pair(a[t_l + 1], a[t_l + 1]);
    return;
  }
  int t_m = (t_l + t_r) / 2;
  build(v << 1, t_l, t_m);
  build((v << 1) + 1, t_m + 1, t_r);
  tree[v] = make_pair(min(tree[v << 1].first, tree[(v << 1) + 1].first),
                      max(tree[v << 1].second, tree[(v << 1) + 1].second));
}
pair<long long, long long> res(int l, int r, int v, int t_l, int t_r) {
  if (l > t_r || r < t_l) return make_pair(inf, -inf);
  if (t_l >= l && t_r <= r) return tree[v];
  int t_m = (t_l + t_r) / 2;
  pair<long long, long long> L = res(l, r, v << 1, t_l, t_m),
                             R = res(l, r, (v << 1) + 1, t_m + 1, t_r);
  return make_pair(min(L.first, R.first), max(L.second, R.second));
}
int main() {
  int n, q;
  int l, r;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int b;
  for (int i = 1; i <= n; i++) cin >> b, a[i] -= b;
  for (int i = 2; i <= n; i++) a[i] += a[i - 1];
  build(1, 0, n - 1);
  while (q--) {
    cin >> l >> r;
    if (a[r] - a[l - 1] != 0) {
      cout << "-1\n";
      continue;
    }
    pair<long long, long long> k = res(l - 1, r - 1, 1, 0, n - 1);
    cout << max(abs(k.first - a[l - 1]), k.second - a[l - 1]) << '\n';
  }
  return 0;
}
