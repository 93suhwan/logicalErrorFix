#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long inv(long long i) {
  if (i == 1) return 1;
  return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
long long mod_mul(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a * b) % mod) + mod) % mod;
}
long long mod_add(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a + b) % mod) + mod) % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long ceil_div(long long a, long long b) {
  return a % b == 0 ? a / b : a / b + 1;
}
long long pwr(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n, i, j, ans, temp, sum;
  string sans;
  t = 1;
  while (t--) {
    sans = "NO";
    ans = temp = sum = 0;
    cin >> n;
    vector<string> a(n);
    vector<unordered_map<long long, long long, custom_hash>> cnt(n);
    vector<long long> mn(n, 1000000000000000005);
    vector<long long> tot(n, 0);
    for (i = 0; i <= n - 1; i++) {
      cin >> a[i];
      long long sz = a[i].size();
      sum = 0;
      for (j = 0; j <= sz - 1; j++) {
        if (a[i][j] == '(')
          sum++;
        else
          sum--;
        mn[i] = min(mn[i], sum);
        if (sum == mn[i]) {
          cnt[i][mn[i]]++;
        }
      }
      tot[i] = sum;
    }
    vector<long long> dp((1 << n) + 1, -1000000000000000005);
    dp[0] = 0;
    for (i = 0; i < (1 << n); i++) {
      long long balance = 0;
      for (j = 0; j <= n - 1; j++) {
        if (i & (1 << j)) balance += tot[j];
      }
      if (balance < 0) {
        for (j = 0; j < n; j++) {
          if (!(i & (1 << j))) {
            long long i2 = i ^ (1 << j);
            dp[i2] = max(dp[i2], dp[i]);
          }
        }
      } else {
        for (j = 0; j < n; j++) {
          if (!(i & (1 << j))) {
            long long i2 = i ^ (1 << j);
            if (balance + mn[i] < 0) {
              dp[i2] = max(dp[i2], dp[i] + cnt[j][-balance]);
            } else if (balance + mn[i] == 0) {
              dp[i2] = max(dp[i2], dp[i] + cnt[j][mn[j]]);
            } else {
              dp[i2] = max(dp[i2], dp[i]);
            }
          }
        }
      }
    }
    ans = dp[(1 << n) - 1];
    cout << ans;
  }
  return 0;
}
