#include <bits/stdc++.h>
using namespace std;
bool isprime(long long k) {
  for (long long i = 2; i <= sqrt(k); i++)
    if (k % i == 0) return false;
  return true;
}
long long bm(long long a, long long b, long long mod) {
  if (b == 0) return 1;
  long long t = bm(a, b / 2, mod);
  t = t * t % mod;
  return (b % 2 == 1 ? t * a % mod : t);
}
long long inv(long long a, long long mod) { return bm(a, mod - 2, mod); }
void gay(long long TC) { cout << "Case #" << TC << ": "; }
long long n;
bool can(long long a, vector<long long> arr) {
  bool reach[n + 5][a + 5];
  memset(reach, false, sizeof reach);
  for (long long i = 0; i <= a; i++) reach[0][i] = true;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j <= a; j++) {
      if (!reach[i][j]) continue;
      if (j - arr[i] >= 0) reach[i + 1][j - arr[i]] = true;
      if (j + arr[i] <= a) reach[i + 1][j + arr[i]] = true;
    }
  }
  for (long long i = 0; i < a; i++)
    if (reach[n][i] == true) return true;
  return false;
}
void solve(long long TC) {
  cin >> n;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) cin >> arr[i];
  long long l = 0, r = 2000;
  while (l < r) {
    long long m = (l + r) / 2;
    if (!can(m, arr))
      l = m + 1;
    else
      r = m;
  }
  cout << l << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) solve(i);
  return 0;
}
