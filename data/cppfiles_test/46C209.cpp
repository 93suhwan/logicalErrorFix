#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
long long INF = 1e18 + 7;
long long MOD = 998244353;
template <typename T>
T my_gcd(T a, T b) {
  return gcd(a, b);
}
template <typename T>
T my_min(T a, T b) {
  return min(a, b);
}
template <typename T>
T my_max(T a, T b) {
  return max(a, b);
}
template <typename T>
T my_and(T a, T b) {
  return (a & b);
}
template <typename T>
T my_xor(T a, T b) {
  return (a ^ b);
}
template <typename T>
T my_or(T a, T b) {
  return (a | b);
}
template <typename T>
T my_sum(T a, T b) {
  return (a + b);
}
template <typename T>
T my_sum_mod(T a, T b) {
  return (a + b) % MOD;
}
template <typename T>
T my_mod(T a, T mod) {
  return a % mod;
}
int solve() {
  long long n;
  while (!(cin >> n)) {
    return 1;
  }
  vector<long long> a(n + 1);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  for (int i = 0; i < n - 1; i += 2) {
    long long diff = 0, mn = INF;
    for (int j = i + 1; j < n; j += 2) {
      ans += max(0ll, min(1ll * a[i], a[j] - diff) + min(mn, diff - 1) + 1);
      mn = min(mn, diff - a[j]);
      diff += (-a[j] + a[j + 1]);
    }
  }
  cout << ans << endl;
  return 0;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cout << std::fixed << std::setprecision(15);
  cin.tie(0);
  int TET = 1e9;
  for (int i = 1; i <= TET; i++) {
    if (solve()) {
      break;
    }
  }
}
