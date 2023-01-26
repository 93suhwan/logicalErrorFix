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
long long f(long long n) {
  if (n < 0) {
    n *= -1;
    n = (n + 1) / 2;
    n *= -1;
    return n;
  } else {
    n = (n + 1) / 2;
  }
  return n;
}
void solve() {
  long long n, q;
  cin >> n;
  cin >> q;
  string s;
  cin >> s;
  long long pre[n];
  long long a[n];
  for (long long i = 0; i < n; i++) {
    if (s[i] == '+')
      a[i] = 1;
    else
      a[i] = -1;
    if (i % 2) a[i] = -a[i];
  }
  map<long long, set<long long> > m;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '+') {
      if (i % 2 == 0)
        pre[i] = 1;
      else
        pre[i] = -1;
    } else {
      if (i % 2 == 0)
        pre[i] = -1;
      else
        pre[i] = 1;
    }
    if (i > 0) pre[i] += pre[i - 1];
    m[pre[i]].insert(i);
  }
  while (q--) {
    long long l, r;
    cin >> l;
    cin >> r;
    l--;
    r--;
    long long op = pre[r];
    long long k = 0;
    if (l > 0) k = pre[l - 1];
    op -= k;
    if (op == 0) {
      cout << 0 << "\n";
      continue;
    }
    if ((r - l + 1) % 2 == 0) {
      op -= a[r];
    }
    op = f(op);
    auto it = m[k + op].lower_bound(l);
    if ((r - l + 1) % 2) {
      cout << 1 << "\n";
      cout << (*it) + 1 << "\n";
    } else {
      cout << 2 << "\n";
      cout << (*it) + 1 << " " << r + 1 << "\n";
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  cin >> t;
  while (t--) solve();
}
