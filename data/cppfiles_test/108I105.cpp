#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long inf = 1e18;
const long long ninf = -1e18;
const long long mod = 1e9 + 7;
long long add(long long a, long long b) { return (a % mod + b % mod) % mod; }
long long mul(long long a, long long b) {
  return ((a % mod) * (b % mod)) % mod;
}
long long sub(long long a, long long b) {
  return (a % mod - b % mod) > 0 ? (a % mod - b % mod) % mod
                                 : mod - (b % mod - a % mod) % mod;
}
long long fact(long long x) {
  if (x < 0) return 0;
  if (x == 0) return 1;
  long long p = x % mod;
  while (--x) {
    p = ((p % mod) * (x % mod));
  }
  return p % mod;
}
long long query(long long l, long long r) {
  long long ans;
  cout << "? " << l << " " << r << '\n';
  cin >> ans;
  return ans;
}
void print(long long a) { cout << "! " << a << '\n'; }
void debug() { cout << "kill\n"; }
void debug(long long x) { cout << x << '\n'; }
long long bin_exp(long long x, unsigned long long y) {
  long long res = 1;
  x = x % mod;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
bool isPrime(long long x) {
  if (x == 1) return false;
  for (long long i = 2; i * i <= x; ++i) {
    if (x % i == 0) return false;
  }
  return true;
}
bool cmp(pair<long long, long long> &a, pair<long long, long long> &b) {
  return a.second < b.second;
}
bool cmp2(pair<long long, long long> &a, pair<long long, long long> &b) {
  return a.first > b.first;
}
long long prod(long long x) {
  long long p = 1LL;
  while (x--) {
    p = (p * 2) % mod;
  }
  return p % mod;
}
long long n;
vector<long long> c;
long long invcnt(vector<long long> &a, long long l, long long r) {
  if (l == r) return 0;
  long long mid = (l + r) / 2;
  long long ans = invcnt(a, l, mid) + invcnt(a, mid + 1, r);
  long long i = l, j = mid + 1, k = l;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j])
      c[k++] = a[i++];
    else
      c[k++] = a[j++], ans += (mid - i + 1);
  }
  while (i <= mid) c[k++] = a[i++];
  while (j <= r) c[k++] = a[j++];
  for (long long i = l; i <= r; i++) a[i] = c[i];
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long> > a(n), b(n);
  for (long long i = 0; i <= n - 1; i++) cin >> a[i].first, a[i].second = i + 1;
  for (long long i = 0; i <= n - 1; i++) cin >> b[i].first, b[i].second = i + 1;
  set<long long> ok;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  ok.insert(a[0].second);
  ok.insert(b[0].second);
  long long j = 0;
  for (long long i = n - 1; i >= 0; i--) {
    if (b[0].second == a[i].second) {
      j = i;
      break;
    }
  }
  for (long long i = j; i >= 0; i--) {
    ok.insert(a[i].second);
  }
  j = 0;
  for (long long i = n - 1; i >= 0; i--) {
    if (a[0].second == b[i].second) {
      j = i;
      break;
    }
  }
  for (long long i = j; i >= 0; i--) {
    ok.insert(b[i].second);
  }
  string s = "";
  for (long long i = 0; i <= n - 1; i++) s += "0";
  for (auto x : ok) {
    s[x - 1] = '1';
  }
  cout << s << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long tt;
  cin >> tt;
  while (tt--) solve();
}
