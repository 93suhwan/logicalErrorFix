#include <bits/stdc++.h>
using namespace std;
bool isprime(long long k) {
  for (long long i = 2; i <= sqrt(k); i++)
    if (k % i == 0) return false;
  return true;
}
long long bm(long long a, long long b, long long mod) {
  if (b == 0) return 1;
  long long t = bm(a, b / 2, mod);
  t = t * t % mod;
  return (b % 2 == 1 ? t * a % mod : t);
}
long long inv(long long a, long long mod) { return bm(a, mod - 2, mod); }
void gay(long long TC) { cout << "Case #" << TC << ": "; }
struct pe {
  long long v;
  long long id;
} a[200005];
long long b[200005];
bool cmp(pe x, pe y) {
  if (x.v == y.v) return x.id < y.id;
  return x.v < y.v;
}
long long d[200005];
long long cnt;
long long n;
bool can(long long k) {
  long long pos;
  cnt = 0;
  for (long long i = 0; i < n; i++) d[i] = 0;
  for (long long i = 1; i < n; i++) {
    if (a[i].v >= 0) {
      pos = i;
      break;
    }
  }
  for (long long i = pos; i < n; i++) {
    if (cnt == 0 || a[i].id > d[cnt]) {
      d[++cnt] = a[i].id;
    } else {
      long long k = lower_bound(d + 1, d + 1 + cnt, a[i].id) - d;
      if (k >= 0) d[k] = a[i].id;
    }
    if (cnt >= k) return true;
  }
  return false;
}
void solve(long long TC) {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> b[i];
    if (b[i] > n) {
      b[i] = n + 1;
    }
    a[i].v = i - b[i];
    a[i].id = b[i];
  }
  sort(a + 1, a + 1 + n, cmp);
  long long l = 0, r = n;
  n++;
  while (l < r) {
    long long m = (l + r + 1) / 2;
    if (!can(m))
      r = m - 1;
    else
      l = m;
  }
  cout << l << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  for (long long i = 1; i <= t; i++) solve(i);
  return 0;
}
