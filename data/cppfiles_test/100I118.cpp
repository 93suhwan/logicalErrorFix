#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5 + 7;
const long long MOD = 998244353;
int a[mxN];
long long silnia[mxN];
long long pom[mxN];
long long npok(long long n, long long k) {
  long long res = 1;
  res *= silnia[n];
  res /= silnia[k];
  res /= silnia[n - k];
  res %= MOD;
  return res;
}
void solve() {
  int n;
  cin >> n;
  map<int, int> cnt;
  int mx = -1;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (long long i = 1; i <= n; i++) mx = max(mx, a[i]);
  for (long long i = 1; i <= n; i++) cnt[a[i]]++;
  if (n == 1 && a[1] < 2)
    cout << "1\n";
  else if (cnt[mx] > 1)
    cout << silnia[n] << "\n";
  else if (a[n] - a[n - 1] > 1)
    cout << "0\n";
  else {
    int ile = cnt[a[n - 1]];
    long long res = 0;
    long long s1 = 1;
    for (long long i = n - ile; i <= n - 1; i++) {
      s1 *= i;
      s1 %= MOD;
    }
    long long x = 1;
    for (long long i = 1; i <= ile; i++) x *= i;
    pom[ile] = x;
    for (long long i = ile + 1; i <= n; i++)
      pom[i] = pom[i - 1] * i / (i - ile);
    for (long long i = 1; i <= n; i++) {
      res += s1;
      if (i > ile) res -= pom[i - 1];
      res *= MOD;
    }
    res *= silnia[n - ile - 1];
    res %= MOD;
    cout << res << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  silnia[0] = 1;
  for (long long i = 1; i <= 2e5; i++) silnia[i] = (silnia[i - 1] * i) % MOD;
  int t;
  cin >> t;
  while (t--) solve();
}
