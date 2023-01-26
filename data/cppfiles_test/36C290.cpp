#include <bits/stdc++.h>
using namespace std;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const int iINF = INT_MAX;
const long long INF = LLONG_MAX;
const long double PI = 3.14159265358979323846;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long fpow(long long a, long long b, long long m) {
  if (!b) return 1;
  long long ans = fpow(a * a % m, b / 2, m);
  return (b % 2 ? ans * a % m : ans);
}
long long inv(long long a, long long m) { return fpow(a, m - 2, m); }
bool isprime(long long x) {
  for (long long i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) return false;
  }
  return true;
}
void solve() {
  long long n, sum = 0;
  cin >> n;
  vector<pair<long long, long long> > a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
    sum += a[i].first;
  }
  sort(a.begin(), a.end());
  if (!isprime(sum)) {
    cout << n << "\n";
    for (long long i = n - 1; i >= 0; i--) cout << a[i].second << " ";
  } else {
    long long cur;
    for (long long i = 0; i < n; i++) {
      if (!isprime(sum - a[i].first)) {
        cur = i;
        break;
      }
    }
    cout << n - 1 << "\n";
    for (long long i = n - 1; i >= 0; i--) {
      if (i != cur) cout << a[i].second << " ";
    }
  }
  cout << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
}
