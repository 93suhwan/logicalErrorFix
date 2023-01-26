#include <bits/stdc++.h>
using namespace std;
const int N = 4005;
using ll = long long;
const ll MIN = LLONG_MIN >> 2;
int n, m, a[N];
inline ll calc(const vector<ll> &lans, const vector<ll> &rans, ll mn, int i,
               int j) {
  return lans[i] + rans[j] - i * 1ll * j * 2 * mn;
}
vector<ll> solve(int l, int r) {
  auto ret = vector<ll>(m + 1, LLONG_MIN >> 2);
  ret[0] = 0;
  if (l > r) return ret;
  int mn = l;
  for (int i = l + 1; i <= r; i++)
    if (a[i] < a[mn]) mn = i;
  auto lans = solve(l, mn - 1), rans = solve(mn + 1, r);
  vector<ll> tt(m + 1, LLONG_MIN >> 2);
  int lim = min(m, r - l + 1);
  int i = 0, j = 0;
  tt[0] = 0;
  while (i + j < lim) {
    if (calc(lans, rans, a[mn], i, j) - calc(lans, rans, a[mn], i + 1, j) <
        calc(lans, rans, a[mn], i, j) - calc(lans, rans, a[mn], i, j + 1))
      ++i;
    else
      ++j;
    tt[i + j] = calc(lans, rans, a[mn], i, j);
  }
  for (int i = 0; i <= lim; i++) {
    ret[i] = max(ret[i], tt[i]);
    if (i) ret[i] = max(ret[i], tt[i - 1] + a[mn] * 1ll * (m - i * 2 + 1));
    if (i >= 2) assert(ret[i] - ret[i - 1] <= ret[i - 1] - ret[i - 2]);
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cout << solve(1, n)[m] << endl;
  return 0;
}
