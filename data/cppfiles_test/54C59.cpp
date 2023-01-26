#include <bits/stdc++.h>
std::mt19937_64 gen(
    std::chrono::steady_clock::now().time_since_epoch().count());
std::mt19937 gen1(std::chrono::steady_clock::now().time_since_epoch().count());
long long int rng(long long int l, long long int r) {
  return std::uniform_int_distribution<long long int>(l, r)(gen);
}
const long double PI = atan(1.0) * 4;
const int32_t INF32 = 2e9 + 7;
const int64_t INF64 = 3e18;
const int32_t LOG = 21;
int32_t MOD = 1e9 + 7;
using namespace std;
void my_debugger(string second, long long int LINE_NUM) { cerr << '\n'; }
template <typename start, typename... end>
void my_debugger(string second, long long int LINE_NUM, start x, end... y) {
  if (second.back() != ',') {
    second += ',';
    cerr << "LINE(" << LINE_NUM << "): ";
  }
  long long int i = second.find(',');
  cerr << second.substr(0, i) << " = " << x;
  second = second.substr(i + 1);
  if (!second.empty()) cerr << ", ";
  my_debugger(second, LINE_NUM, y...);
}
void setMod(long long int mod_val) { MOD = mod_val; }
void files_init() {
  freopen("file.in", "r", stdin);
  freopen("file.out", "w", stdout);
}
const long long int N = 1e6 + 5;
const long long int LOGN = 20;
long long int power(long long int x, long long int y) {
  if (y == 0) return 1;
  long long int temp = power(x, y / 2);
  temp = (temp * temp) % MOD;
  if (y & 1) temp = (temp * x) % MOD;
  return temp;
}
long long int fact[200005];
long long int inv[200005];
void init(long long int n = 200003) {
  fact[0] = inv[0] = 1;
  for (long long int i = 1; i < (long long int)n + 1; i++) {
    fact[i] = (i * fact[i - 1]) % MOD;
    inv[i] = power(fact[i], MOD - 2);
  }
}
long long int ncr(long long int n, long long int r) {
  if (n < r) return 0;
  long long int num = (fact[n] * inv[n - r]) % MOD;
  num = (num * inv[r]) % MOD;
  return num;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long int tests = 1;
  cin >> tests;
  setMod(1e9 + 7);
  init();
  for (long long int ii = 0; ii < (long long int)tests; ii++) {
    long long int n, k;
    cin >> n >> k;
    if (k == 0) {
      cout << 1 << '\n';
      continue;
    }
    vector<long long int> dp(k + 1);
    vector<long long int> pow2(k + 1);
    long long int temp = 0;
    pow2[0] = 1;
    for (long long int i = 1; i < (long long int)k + 1; i++) {
      pow2[i] = (pow2[i - 1] * 2) % MOD;
    }
    for (long long int i = 0; i < n; i += 2) {
      temp += ncr(n, i);
      temp %= MOD;
    }
    dp[1] = temp;
    bool even = false;
    if (n % 2 == 0) even = true;
    if (even) {
      dp[1]++;
      dp[1] %= MOD;
    } else {
      temp += ncr(n, n);
      temp %= MOD;
      dp[1] = temp;
    }
    for (long long int bit = 2; bit <= k; bit++) {
      dp[bit] = (temp * dp[bit - 1]) % MOD;
      if (even) {
        dp[bit] += power(pow2[bit - 1], n);
        dp[bit] %= MOD;
      }
    }
    cout << dp[k] << '\n';
  }
  return 0;
}
