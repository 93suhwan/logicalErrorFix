#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1.0);
const long double EPS = 1e-7;
const long long MOD = 1e9 + 7;
void solve() {
  long long k;
  cin >> k;
  long long lo = 1;
  long long hi = 100000;
  long long best = hi;
  while (lo <= hi) {
    long long mid = (lo + hi) / 2;
    if (mid * mid < k) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
      best = min(best, mid);
    }
  }
  long long d = best * best - k;
  long long r = best;
  r -= max(0LL, d - best + 1LL);
  long long c = best;
  if (d < best) {
    c = 1 + (d);
  }
  cout << r << " " << c << endl;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
