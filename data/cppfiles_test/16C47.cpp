#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
const long long N = 2e5 + 5;
const long long MAXN = 10000001;
long long spf[MAXN];
long long fact[N], invfact[N];
using namespace std;
bool is_prime(long long n) {
  if (n == 1) {
    return false;
  }
  long long i = 2;
  while (i * i <= n) {
    if (n % i == 0) {
      return false;
    }
    i += 1;
  }
  return true;
}
long long pow(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
long long modinv(long long k) { return pow(k, mod - 2, mod); }
void precompute() {
  fact[0] = fact[1] = 1;
  for (long long i = 2; i < N; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= mod;
  }
  invfact[N - 1] = modinv(fact[N - 1]);
  for (long long i = N - 2; i >= 0; i--) {
    invfact[i] = invfact[i + 1] * (i + 1);
    invfact[i] %= mod;
  }
}
long long nCr(long long x, long long y) {
  if (y > x) return 0;
  long long num = fact[x];
  num *= invfact[y];
  num %= mod;
  num *= invfact[x - y];
  num %= mod;
  return num;
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
string toBinary(long long n) {
  string r;
  while (n != 0) {
    r = (n % 2 == 0 ? "0" : "1") + r;
    n /= 2;
  }
  return r;
}
void sieve() {
  spf[1] = 1;
  for (long long i = 2; i < MAXN; i++) spf[i] = i;
  for (long long i = 4; i < MAXN; i += 2) spf[i] = 2;
  for (long long i = 3; i * i < MAXN; i++) {
    if (spf[i] == i) {
      for (long long j = i * i; j < MAXN; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
long long getFactorization(long long x) {
  long long ret = 0;
  while (x != 1) {
    ret++;
    x = x / spf[x];
  }
  return ret;
}
void solve(long long in) {
  long long n;
  cin >> n;
  vector<long long> a(n);
  multimap<long long, long long> m;
  multiset<pair<long long, long long>> s;
  long long sum = 0;
  long long zc = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] != 0) s.insert({a[i], i + 1});
  }
  vector<pair<long long, long long>> v;
  while (s.size() > 1) {
    v.push_back({s.begin()->second, s.rbegin()->second});
    long long xa = s.begin()->first - 1, xb = s.begin()->second;
    long long ya = s.rbegin()->first - 1, yb = s.rbegin()->second;
    s.erase(s.begin());
    s.erase(--s.end());
    if (xa != 0) s.insert({xa, xb});
    if (ya != 0) s.insert({ya, yb});
  }
  cout << v.size() << "\n";
  for (long long i = 0; i < v.size(); i++) {
    cout << v[i].first << " " << v[i].second << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i < t + 1; i++) {
    solve(i);
  }
  return 0;
}
