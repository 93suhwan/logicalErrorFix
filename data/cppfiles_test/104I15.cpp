#include <bits/stdc++.h>
using namespace std;
template <typename T>
int smin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
int smax(T& a, const T& b) {
  return b > a ? a = b, 1 : 0;
}
mt19937_64 rng;
const char nl = '\n';
const int MX = 2e5 + 10;
const long long INF = 1e18 + 10;
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> a(n), b(n);
  long long sum = 0, sum_a;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    sum += a[i] + b[i];
    sum_a += a[i];
  }
  long long lo = 0, hi = 0;
  for (int i = 0; i < n; i++) {
    lo += max(0LL, a[i] - m);
    hi += a[i] - max(0LL, m - b[i]);
  }
  vector<int> take(n);
  long long ans = INF;
  sum -= n * m;
  if (lo <= sum / 2 && sum / 2 <= hi) {
    ans = abs(sum - sum / 2 * 2);
    long long want = sum / 2;
    long long rem = 0;
    for (int i = 0; i < n; i++) {
      rem += max(0LL, a[i] - m);
    }
    for (int i = 0; i < n; i++) {
      rem -= max(0LL, a[i] - m);
      long long here = min(a[i], max(rem, a[i] - m));
      take[i] = a[i] - here;
    }
  } else if (abs(2 * lo - sum) <= abs(2 * hi - sum)) {
    ans = abs(2 * lo - sum);
    for (int i = 0; i < n; i++) {
      take[i] = min(a[i], m);
    }
  } else {
    ans = abs(2 * hi - sum);
    for (int i = 0; i < n; i++) {
      take[i] = max(0LL, m - b[i]);
    }
  }
  cout << ans << nl;
  for (int i = 0; i < n; i++) {
    cout << take[i] << " " << m - take[i] << nl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int te = 1;
  cin >> te;
  while (te--) {
    solve();
  }
  return 0;
}
