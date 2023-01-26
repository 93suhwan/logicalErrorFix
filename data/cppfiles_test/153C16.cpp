#include <bits/stdc++.h>
using namespace std;
const long double PI = 2 * acos(0.0);
const int N = (int)1e6;
mt19937_64 gen(time(0));
uniform_int_distribution<uint64_t> rng;
const int MOD = 998244353;
int lgput(int n, int p, int mod = MOD) {
  int ans = 1, first = n;
  while (p) {
    if (p & 1) ans = 1LL * ans * first % mod;
    first = 1LL * first * first % mod;
    p >>= 1;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
struct BIT {
  int bit[100005];
  int n;
  ~BIT() { n = 0; }
  BIT() {
    n = 0;
    memset(bit, 0, sizeof(bit));
  }
  BIT(int _n) {
    n = _n;
    memset(bit, 0, sizeof(bit));
  }
  void reset(int _n) {
    for (int i = 1; i <= _n; i++) bit[i] = 0;
  }
  void reset() {
    for (int i = 1; i <= n; i++) bit[i] = 0;
  }
  void init(int _n) {
    n = _n;
    reset(n);
  }
  void update(int ind, int val) {
    for (; ind <= n; ind += ((ind) & (-(ind)))) bit[ind] += val;
  }
  int query(int ind) {
    int ans = 0;
    for (; ind; ind -= ((ind) & (-(ind)))) ans += bit[ind];
    return ans;
  }
};
int T;
int n;
string s[25];
int mn[30];
int f[25][30];
int dp[(1 << 23)];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = '#' + s[i];
    for (int j = 1; j < (int)s[i].size(); j++) f[i][s[i][j] - 'a']++;
  }
  for (int mask = 1; mask < (1 << n); mask++) {
    for (int i = 0; i < 26; i++) mn[i] = (int)1e9;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        for (int j = 0; j < 26; j++) mn[j] = min(mn[j], f[i + 1][j]);
      }
    }
    dp[mask] = 1;
    for (int i = 0; i < 26; i++) dp[mask] = 1LL * dp[mask] * (mn[i] + 1) % MOD;
    if (__builtin_popcount(mask) % 2 == 0) dp[mask] = MOD - dp[mask];
  }
  for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < (1 << n); mask++) {
      if (mask & (1 << i)) dp[mask] = (dp[mask] + dp[mask ^ (1 << i)]) % MOD;
    }
  }
  long long ans = 0;
  for (int mask = 1; mask < (1 << n); mask++) {
    int cnt = 0, s = 0;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        cnt++;
        s += i + 1;
      }
    }
    ans ^= 1LL * dp[mask] * cnt * s;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  T = 1;
  for (int t = 1; t <= T; t++) {
    solve();
  }
  return 0;
}
