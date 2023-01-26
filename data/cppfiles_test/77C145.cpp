#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC optimize("trapv")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
using namespace std;
long long power(long long x, long long y, long long m) {
  if (y < 0) return 0;
  long long temp;
  if (y == 0) return 1;
  temp = (power(x, y / 2, m)) % m;
  if (y % 2 == 0)
    return ((temp % m) * temp) % m;
  else
    return ((x * temp % m) * temp % m) % m;
}
long long inv(long long x, long long m = 1000000007) {
  return (power(x, m - 2, m)) % m;
}
int32_t n, m, DP[4000001], L[4000001], R[4000001];
int32_t main() {
  cin.tie(0), iostream::sync_with_stdio(0);
  cin >> n >> m;
  DP[1] = 1;
  long long TOT = 0, TOT2 = 0;
  for (long long i = 1; i <= n; i++) {
    TOT2 = (TOT2 + L[i]) % m;
    DP[i] = (DP[i] + TOT + TOT2) % m;
    TOT2 = (TOT2 - R[i] + m) % m;
    for (long long j = i * 2; j <= n; j += i) {
      L[j] = (L[j] + DP[i]) % m;
      if (j + j / i - 1 <= 4000000)
        R[j + j / i - 1] = (R[j + j / i - 1] + DP[i]) % m;
    }
    TOT = ((TOT + DP[i]) >= m ? TOT + DP[i] - m : TOT + DP[i]);
  }
  cout << DP[n];
}
