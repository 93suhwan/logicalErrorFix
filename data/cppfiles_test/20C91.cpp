#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 200005;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long double EPS = 1e-9;
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
long long zeros[405][405], ones[405][405];
long long cnt_z(long long col, long long up, long long down) {
  return zeros[down][col] - (up == 0 ? 0 : zeros[up - 1][col]);
}
long long cnt_o(long long col, long long up, long long down) {
  return ones[down][col] - (up == 0 ? 0 : ones[up - 1][col]);
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
    bool a[n][m];
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        char c;
        cin >> c;
        a[i][j] = c == '1';
      }
    }
    for (long long j = 0; j < m; j++) {
      zeros[0][j] = !a[0][j];
      for (long long i = 1; i < n; i++) {
        zeros[i][j] = zeros[i - 1][j] + !a[i][j];
      }
      ones[0][j] = a[0][j];
      for (long long i = 1; i < n; i++) {
        ones[i][j] = ones[i - 1][j] + a[i][j];
      }
    }
    long long ans = INF;
    for (long long up = 0; up < n; up++) {
      for (long long down = up + 4; down < n; down++) {
        long long cur = !a[up][0] + !a[up][1] + !a[up][2] + !a[down][0] +
                        !a[down][1] + !a[down][2] + cnt_o(0, up + 1, down - 1) +
                        cnt_o(1, up + 1, down - 1) +
                        cnt_o(2, up + 1, down - 1) + cnt_z(3, up + 1, down - 1);
        long long new_mn = -(!a[up][0] + !a[down][0]) +
                           cnt_z(0, up + 1, down - 1) -
                           cnt_o(0, up + 1, down - 1);
        long long mn = new_mn;
        ans = min(1ll * ans, 1ll * cur + mn);
        for (long long col = 4; col < m; col++) {
          cur += !a[up][col - 1] + !a[down][col - 1] +
                 cnt_z(col, up + 1, down - 1) -
                 cnt_z(col - 1, up + 1, down - 1) +
                 cnt_o(col - 1, up + 1, down - 1);
          new_mn -= !a[up][col - 3] + !a[down][col - 3];
          new_mn -= cnt_z(col - 4, up + 1, down - 1);
          new_mn += cnt_z(col - 3, up + 1, down - 1) -
                    cnt_o(col - 3, up + 1, down - 1);
          mn = min(1ll * mn, 1ll * new_mn);
          ans = min(1ll * ans, 1ll * cur + mn);
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
