#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
constexpr long long inf = 1e18;
const long long maxn = 2e5 + 100;
const int MAXN = 1.1e6;
int spf[MAXN];
void sieve() {
  for (int i = 1; i < MAXN; i++) spf[i] = 1;
  for (int i = 2; i * i < MAXN; i++) {
    for (int j = i * i; j < MAXN; j += i * i) spf[j] = i;
  }
}
long long fact[MAXN], inv[MAXN], invFact[MAXN];
void factGen() {
  fact[0] = inv[1] = fact[1] = invFact[0] = invFact[1] = 1;
  for (long long i = 2; i < MAXN; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
    inv[i] = mod - (inv[mod % i] * (mod / i) % mod);
    invFact[i] = (inv[i] * invFact[i - 1]) % mod;
  }
}
int gcdExtended(int a, int b, int *x, int *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  int x1, y1;
  int gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
int modInverse(int a, int m) {
  int x, y;
  int g = gcdExtended(a, m, &x, &y);
  if (g != 1)
    return -1;
  else {
    int res = (x % m + m) % m;
    return res;
  }
}
long long binpow(long long a, long long b, long long m) {
  if (b < 0) return 0LL;
  if (a <= 0) return 0LL;
  a %= m;
  long long ans = 1LL;
  while (b) {
    if (b & 1) ans = ans * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return ans;
}
long long modinv(long long n) { return binpow(n, mod - 2, mod); }
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
string go(string t) {
  while (t.back() == '0') t.pop_back();
  reverse(t.begin(), t.end());
  return t;
}
long long mul(long long a, long long b) {
  long long ans = 0;
  while (b) {
    if (b & 1) {
      ans += a;
    }
    b = b >> 1;
    a += a;
    if (a > inf) {
      a = inf;
    }
    if (ans > inf) {
      ans = inf;
    }
  }
  return ans;
}
void solve() {
  long long n, k, x;
  cin >> n >> k >> x;
  x--;
  string s;
  cin >> s;
  vector<long long> cnt;
  long long c = 0;
  for (long long i = 0; i < n; ++i) {
    if (s[i] == 'a') {
      cnt.push_back(c);
      c = 0;
    } else {
      c++;
    }
  }
  cnt.push_back(c);
  vector<long long> m((int)cnt.size());
  m[(int)m.size() - 1] = 1;
  for (long long i = (int)cnt.size() - 2; i >= 0; --i) {
    m[i] = mul(m[i + 1], k * cnt[i + 1] + 1);
  }
  vector<long long> ans((int)cnt.size());
  for (long long i = 0; i < (int)cnt.size(); ++i) {
    ans[i] = x / m[i];
    x %= m[i];
  }
  for (long long i = 0; i < (int)cnt.size(); ++i) {
    for (long long j = 0; j < ans[i]; ++j) {
      cout << 'b';
    }
    if (i + 1 != (int)cnt.size()) {
      cout << 'a';
    }
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
