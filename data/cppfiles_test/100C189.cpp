#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5 + 7;
const long long MOD = 998244353;
int a[mxN];
long long silnia[mxN];
long long potega(long long x) {
  long long res = 1;
  long long y = MOD - 2;
  while (y) {
    if (y & 1) res = (res * x) % MOD;
    x = (x * x) % MOD;
    y /= 2;
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  int ile = 0;
  for (long long i = 1; i <= n; i++)
    if (a[i] == a[n - 1]) ile++;
  if (a[n] == a[n - 1])
    cout << silnia[n] << "\n";
  else if (a[n] - a[n - 1] == 1) {
    long long x = (silnia[n] * potega(ile + 1)) % MOD;
    cout << (silnia[n] - x + MOD) % MOD << "\n";
  } else
    cout << "0\n";
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
