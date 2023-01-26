#include <bits/stdc++.h>
using namespace std;
const long long INF = numeric_limits<long long>::max();
const long long nax = (long long)(20001);
const long long mod = 1e9 + 7;
template <class X, class Y>
bool maximize(X& x, const Y y) {
  if (y > x) {
    x = y;
    return true;
  }
  return false;
}
template <class X, class Y>
bool minimize(X& x, const Y y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}
long long is_not_prime[nax];
void sieve() {
  for (long long i = 2; i * i < nax; ++i) {
    for (long long j = i * i; j < nax; j += i) {
      is_not_prime[j] = 1;
    }
  }
}
pair<long long, long long> a[nax];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  sieve();
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    long long sum = 0;
    for (long long i = 1; i <= n; ++i) {
      cin >> a[i].first;
      sum += a[i].first;
      a[i].second = i;
    }
    if (is_not_prime[sum]) {
      cout << n << '\n';
      for (long long i = 1; i <= n; ++i) {
        cout << i << " ";
      }
      cout << '\n';
      continue;
    }
    sort(a + 1, a + n + 1);
    long long ans = -1, memo = 0;
    for (long long i = 1; i <= n; ++i) {
      if (is_not_prime[sum - a[i].first]) {
        if (maximize(ans, sum - a[i].first)) {
          memo = a[i].second;
        }
      }
    }
    if (ans == -1) {
      cout << n - 2 << '\n';
      for (long long i = 3; i <= n; ++i) {
        cout << a[i].second << " ";
      }
      cout << '\n';
      continue;
    }
    cout << n - 1 << '\n';
    for (long long i = 1; i <= n; ++i) {
      if (memo == a[i].second) {
        continue;
      }
      cout << a[i].second << " ";
    }
    cout << '\n';
  }
  return 0;
}
