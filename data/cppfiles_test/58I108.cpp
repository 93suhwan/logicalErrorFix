#include <bits/stdc++.h>
using namespace std;
constexpr long long MAXN = 200000;
constexpr long long MAXFACT = MAXN * 2 + 5;
constexpr long long MOD = 998244353;
pair<long long, long long> arr[MAXN];
struct fenwick {
  constexpr static long long FWSIZE = MAXN + 5;
  long long arr[FWSIZE];
  long long query(long long index) {
    long long ans = 0;
    for (; index > 0; index -= index & -index) {
      ans += arr[index];
    }
    return ans;
  }
  void update(long long index, long long inc) {
    for (; index < FWSIZE; index += index & -index) {
      arr[index] += inc;
    }
  }
} fw;
template <typename Callback>
long long bsta(long long low, long long high, Callback cb) {
  while (low + 1 < high) {
    long long mid = (low + high) / 2;
    if (cb(mid)) {
      low = mid;
    } else {
      high = mid;
    }
  }
  return high;
}
long long facts[MAXFACT], invfacts[MAXFACT];
long long powmod(long long base, long long e) {
  if (e == 0) return 1;
  long long tmp = powmod(base, e / 2);
  tmp *= tmp;
  tmp %= MOD;
  if (e & 1) {
    tmp *= base;
    tmp %= MOD;
  }
  return tmp;
}
long long combin(long long n, long long a, long long b) {
  return (((facts[n] * invfacts[a]) % MOD) * invfacts[b]) % MOD;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  {
    long long cum = 1;
    facts[0] = invfacts[0] = cum;
    for (long long i = 1; i < MAXFACT; ++i) {
      cum *= i;
      cum %= MOD;
      facts[i] = cum;
      invfacts[i] = powmod(facts[i], MOD - 2);
    }
  }
  long long t;
  cin >> t;
  for (long long c = 0; c < t; ++c) {
    long long n, m;
    cin >> n >> m;
    for (long long i = 0; i < m; ++i) {
      cin >> arr[i].first >> arr[i].second;
    }
    long long splits = 0;
    for (long long i = m - 1; i >= 0; --i) {
      const long long target = arr[i].second;
      long long realidx = bsta(
          0, n, [&](long long test) { return test - fw.query(test) < target; });
      if (fw.query(realidx + 1) == fw.query(realidx)) {
        ++splits;
      }
      fw.update(realidx, 1);
    }
    long long tmp = n - 1 - splits;
    cout << combin(n + tmp, n, tmp) << '\n';
  }
}
