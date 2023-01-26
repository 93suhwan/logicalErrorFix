#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e16;
const long long N = 2e5 + 10;
long long pw(long long a, long long n) {
  if (n == 0) return 1;
  long long res = pw(a, n / 2);
  if (n % 2)
    return res * res * a;
  else
    return res * res;
}
void run() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (auto &e : a) {
    cin >> e;
  }
  reverse((a).begin(), (a).end());
  long long rem = 19;
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    rem -= a[i];
    v.push_back(rem);
    rem = a[i];
  }
  reverse((a).begin(), (a).end());
  reverse((v).begin(), (v).end());
  long long ans = 0;
  k++;
  for (long long i = 0; i < n - 1; i++) {
    long long cur = stoll(string(v[i], '9'));
    if (cur > k) {
      ans += k * pw(10, a[i]);
      k = 0;
      break;
    } else {
      ans += cur * pw(10, a[i]);
      k -= cur;
    }
    if (k <= 0) break;
  }
  ans += k * 1ll * pw(10, a[n - 1]);
  cout << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long tt = 1;
  cin >> tt;
  while (tt--) run();
  return 0;
}
