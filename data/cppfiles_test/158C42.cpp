#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 10005;
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
    long long n, m;
    cin >> n >> m;
    vector<long long> x(n);
    for (long long i = 0; i < n; i++) {
      cin >> x[i];
    }
    vector<string> s(n);
    for (long long i = 0; i < n; i++) {
      cin >> s[i];
    }
    long long ans = 0;
    vector<long long> best(m);
    iota(best.begin(), best.end(), 1);
    for (long long p = 0; p < (1 << n); p++) {
      vector<pair<long long, long long>> sum(m);
      for (long long i = 0; i < m; i++) {
        sum[i].second = i;
      }
      long long res = 0;
      for (long long i = 0; i < n; i++) {
        if (p & (1 << i)) {
          res += x[i];
        } else {
          res -= x[i];
        }
        for (long long j = 0; j < m; j++) {
          if (s[i][j] == '0') {
            continue;
          }
          if (p & (1 << i)) {
            sum[j].first--;
          } else {
            sum[j].first++;
          }
        }
      }
      sort(sum.begin(), sum.end());
      for (long long i = 0; i < m; i++) {
        res += sum[i].first * (i + 1);
      }
      if (res > ans) {
        ans = res;
        for (long long i = 0; i < m; i++) {
          best[sum[i].second] = i + 1;
        }
      }
    }
    cout << best << '\n';
  }
  return 0;
}
