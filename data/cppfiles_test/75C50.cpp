#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long cl(long double a) {
  if (a > (long long)a) {
    return (long long)a + 1;
  } else {
    return (long long)a;
  }
}
long long flr(long double a) {
  if (a < 0.0) {
    return (long long)a - 1;
  }
  return (long long)a;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long pw(long long n, long long k) {
  if (k == 0) return 1;
  long long t = pw(n, k / 2);
  long long ans = (t * t) % mod;
  if (k % 2)
    return (ans * n) % mod;
  else
    return ans;
}
long long solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long pre[n], suff[n];
  for (long long i = 0; i < n; i++) {
    pre[i] = 1;
    if (i > 0 && a[i] < a[i - 1]) {
      pre[i] = pre[i - 1] + 1;
    }
  }
  for (long long i = n - 1; i >= 0; i--) {
    suff[i] = 1;
    if (i < n - 1 && a[i] < a[i + 1]) {
      suff[i] += suff[i + 1];
    }
  }
  long long s = 0, e = n - 1;
  long long flag = 0;
  long long prev = -1;
  while (s <= e) {
    if (a[s] > prev && a[e] > prev) {
      if (a[e] < a[s]) {
        long long len = min(e - s + 1, suff[s]);
        if (len % 2) {
          return flag;
        }
        prev = a[e];
        e--;
      } else if (a[e] > a[s]) {
        long long len = min(e - s + 1, pre[e]);
        if (len % 2) {
          return flag;
        }
        prev = a[s];
        s++;
      } else {
        long long len = min(e - s + 1, suff[s]);
        if (len % 2) return flag;
        len = min(e - s + 1, pre[e]);
        if (len % 2) return flag;
        return (flag ^ 1);
      }
    } else if (a[e] > prev) {
      long long len = min(e - s + 1, pre[e]);
      if (len % 2)
        return flag;
      else
        return (flag ^ 1);
    } else if (a[s] > prev) {
      long long len = min(e - s + 1, suff[s]);
      if (len % 2)
        return flag;
      else
        return (flag ^ 1);
    } else {
      return (flag ^ 1);
    }
    flag ^= 1;
  }
  return flag;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  while (t--) {
    if (!solve()) {
      cout << "Alice"
           << "\n";
    } else {
      cout << "Bob"
           << "\n";
    }
  }
}
