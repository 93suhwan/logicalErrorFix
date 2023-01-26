#include <bits/stdc++.h>
using namespace std;
const long long MAX = 2000000;
const long long MOD = 1000000007;
const long long OO = 0x3f3f3f3f;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long &w : v) cin >> w;
  auto check = [&](long long k) {
    vector<long long> aux(n), arr = v;
    for (long long i = n - 1; i >= 2; --i) {
      if (aux[i] + arr[i] < k) return false;
      long long a = max(k - aux[i], 0ll);
      long long d = (arr[i] - a) / 3;
      arr[i] -= 3 * d;
      aux[i - 1] += d;
      aux[i - 2] += 2 * d;
    }
    for (long long i = 0; i < n; ++i)
      if (aux[i] + arr[i] < k) return false;
    return true;
  };
  long long b = 0, e = 1000000000000, ans = 0;
  while (b <= e) {
    long long mid = (b + e) / 2;
    if (check(mid))
      ans = mid, b = mid + 1;
    else
      e = mid - 1;
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  for (long long caso = 1; caso <= t; ++caso) {
    solve();
  }
  return 0;
}
