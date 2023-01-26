#include <bits/stdc++.h>
using namespace std;
vector<long long> tree;
long long get(long long v, long long l, long long r, long long ql,
              long long qr) {
  if (ql >= r || l >= qr) return 0;
  if (ql <= l && r <= qr) return tree[v];
  long long mid = (l + r) / 2;
  return get(2 * v + 1, l, mid, ql, qr) + get(2 * v + 2, mid, r, ql, qr);
}
void update(long long v, long long l, long long r, long long ind) {
  if (l > ind || r <= ind) return;
  if (r - l == 1) {
    tree[v]++;
    return;
  }
  long long mid = (l + r) / 2;
  update(2 * v + 1, l, mid, ind);
  update(2 * v + 2, mid, r, ind);
  tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<pair<long long, long long>> a(n * m);
  for (long long i = 0; i < n * m; ++i) {
    cin >> a[i].first;
    a[i].second = -i;
  }
  sort(a.begin(), a.end());
  long long ans = 0;
  for (long long i = 0; i < n * m;) {
    if (i % m == 0) tree.assign(4 * m, 0);
    long long j = i;
    while (j < n * m - 1 && a[j].first == a[j + 1].first) j++;
    if (j / m != i / m) {
      for (long long k = (j / m) * m - 1; k >= i; --k) {
        ans += get(0, 0, n, 0, (-a[k].second) % m);
      }
      tree.assign(4 * m, 0);
      for (long long k = (j / m) * m; k <= j; ++k) {
        update(0, 0, n, (-a[k].second) % m);
      }
      i = j + 1;
    } else {
      for (long long k = i; k <= j; ++k) {
        ans += get(0, 0, n, 0, (-a[k].second) % m);
      }
      for (; i <= j; ++i) {
        update(0, 0, n, (-a[i].second) % m);
      }
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
