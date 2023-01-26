#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int64_t longinf = LLONG_MAX - 100000;
const long long inf = INT_MAX;
long long pw(long long x, long long y, long long p = longinf) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long invmod(long long a, long long m = mod) { return pw(a, m - 2, m); }
long long cl(long long a, long long x) {
  return a % x == 0 ? a / x : a / x + 1;
}
void run_time_terror(long long case_no = 0) {
  long long n, k;
  cin >> n >> k;
  set<long long> s;
  for (long long i = 0; i < n; ++i) {
    s.insert(i + 1);
  }
  for (long long i = 0; i < k; ++i) {
    long long a, b, c;
    cin >> a >> b >> c;
    s.erase(b);
  }
  for (long long i = 0; i < n; ++i) {
    if (i + 1 == *s.begin()) {
      continue;
    }
    cout << (i + 1) << " " << (*s.begin()) << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cout.setf(ios::fixed);
  cout << setprecision(0);
  long long tt = 1;
  cin >> tt;
  for (long long case_no = 1; case_no <= tt; case_no++) {
    run_time_terror(case_no);
  }
  return 0;
}
