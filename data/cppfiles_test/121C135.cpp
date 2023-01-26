#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 300005;
const long long MOD = 998244353;
const long long INF = 1e18;
const long double EPS = 1e-7;
inline long long summ(long long x, long long y) {
  return (x + y) - (x + y >= MOD) * MOD;
}
inline long long difm(long long x, long long y) {
  return (x - y) + (x - y < 0) * MOD;
}
inline long long mulm(long long x, long long y) { return x * y % MOD; }
long long bin_pow(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2) {
      n--;
      res = mulm(res, a);
    } else {
      n /= 2;
      a = mulm(a, a);
    }
  }
  return res;
}
inline long long rev(long long n) { return bin_pow(n, MOD - 2); }
inline long long divm(long long x, long long y) { return mulm(x, rev(y)); }
long long fact[MAXN], fact_rev[MAXN];
void fact_init() {
  fact[0] = fact_rev[0] = 1;
  for (long long i = 1; i < MAXN; i++) {
    fact[i] = fact[i - 1] * i % MOD;
    fact_rev[i] = rev(fact[i]);
  }
}
inline long long comb(long long n, long long k) {
  return fact[n] * fact_rev[k] % MOD * fact_rev[n - k] % MOD;
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
ostream& operator<<(ostream& stream, const pair<long long, long long>& p) {
  return stream << p.first << ' ' << p.second;
}
ostream& operator<<(ostream& stream, const vector<long long>& v) {
  for (long long val : v) {
    stream << val << ' ';
  }
  return stream;
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base ::sync_with_stdio(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    long long cnta = count(a.begin(), a.end(), '1');
    long long cntb = count(b.begin(), b.end(), '1');
    if (cntb != cnta && cntb != n - cnta + 1) {
      cout << -1 << '\n';
      continue;
    }
    long long mn = INF;
    if (cntb == cnta) {
      long long cnt = 0;
      for (long long i = 0; i < n; i++) {
        cnt += a[i] != b[i];
      }
      mn = min(1ll * mn, 1ll * cnt);
    }
    if (cntb == n - cnta + 1) {
      long long cnt = 0;
      for (long long i = 0; i < n; i++) {
        cnt += a[i] == b[i];
      }
      mn = min(1ll * mn, 1ll * cnt);
    }
    cout << mn << '\n';
  }
  return 0;
}
