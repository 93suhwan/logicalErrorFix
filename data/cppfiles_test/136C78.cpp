#include <bits/stdc++.h>
using namespace std;
const long long INF = numeric_limits<long long>::max();
const long long nax = (long long)(100001);
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
long long a[nax];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    long long sum = 0;
    for (long long i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum % (n * (n + 1) / 2)) {
      cout << "NO" << '\n';
      continue;
    }
    sum /= (n * (n + 1) / 2);
    long long flag = 1;
    for (long long i = 0; i < n; ++i) {
      if ((sum + a[(i - 1 + n) % n] - a[i]) % n ||
          (sum + a[(i - 1 + n) % n] - a[i]) < 1) {
        flag = 0;
      }
    }
    if (!flag) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    for (long long i = 0; i < n; ++i) {
      cout << (sum + a[(i - 1 + n) % n] - a[i]) / n << " ";
    }
    cout << '\n';
    for (long long i = 0; i < n; ++i) {
    }
  }
  return 0;
}
