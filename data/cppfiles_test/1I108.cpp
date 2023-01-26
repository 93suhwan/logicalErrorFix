#include <bits/stdc++.h>
using namespace std;
mt19937_64 gen(0xBEEF);
uniform_int_distribution<uint64_t> rng;
int T;
int n, k;
pair<long double, int> a[100005];
pair<int, int> v[100005];
bool check(long double r) {
  int m = 0, cnt = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    long double d = sqrtf(v[i].first * v[i].first + v[i].second * v[i].second);
    if (d > 2 * r) continue;
    long double angle = atan2(v[i].second, v[i].first);
    long double alpha = acos(d / (2 * r));
    a[++m] = make_pair(angle - alpha, 1);
    a[++m] = make_pair(angle + alpha + 1e-12, -1);
  }
  sort(a + 1, a + m + 1);
  for (int i = 1; i <= m; i++) {
    cnt += a[i].second;
    if (cnt >= k) return 1;
  }
  return 0;
}
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> v[i].first >> v[i].second;
  long double st = 0, dr = 2e5, mid;
  while (dr - st > 1e-9) {
    mid = (st + dr) / 2;
    if (check(mid))
      dr = mid;
    else
      st = mid;
  }
  cout << fixed << setprecision(10) << dr << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  T = 1;
  for (; T; T--) {
    solve();
  }
  return 0;
}
