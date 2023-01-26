#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long INF = 1e18;
const long long MAXN = 2e5 + 100;
long long t[4 * MAXN];
void upd(long long v, long long l, long long r, long long p) {
  if (l + 1 == r) {
    t[v]++;
    return;
  }
  long long m = (r + l) / 2;
  if (p < m) {
    upd(v * 2, l, m, p);
  } else {
    upd(v * 2 + 1, m, r, p);
  }
  t[v] = t[v * 2] + t[v * 2 + 1];
}
long long get(long long v, long long l, long long r, long long ql,
              long long qr) {
  if (ql >= r || l >= qr) {
    return 0;
  }
  if (ql <= l && r <= qr) {
    return t[v];
  }
  long long m = (r + l) / 2;
  return get(v * 2, l, m, ql, qr) + get(v * 2 + 1, m, r, ql, qr);
}
void solve() {
  long long n;
  cin >> n;
  for (int i = 0; i < MAXN; ++i) {
    t[i] = 0;
  }
  long long sz = 1;
  while (sz < n) sz *= 2;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  set<long long> b;
  for (int i = 0; i < n; ++i) {
    b.insert(a[i]);
  }
  map<long long, long long> pos;
  long long c = 0;
  for (auto i : b) {
    pos[i] = c++;
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += min(get(1, 0, sz, 0, pos[a[i]]), get(1, 0, sz, pos[a[i]] + 1, n));
    upd(1, 0, sz, pos[a[i]]);
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}
