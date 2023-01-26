#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5 + 7;
const long long MOD = 998244353;
int a[mxN];
long long silnia[mxN];
int pref[mxN];
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
  else
    cout << silnia[n] * cnt[mx - 1] / (cnt[mx - 1] + 1) << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  silnia[0] = 1;
  for (long long i = 1; i <= 2e5; i++) silnia[i] = (silnia[i - 1] * i) % MOD;
  pref[0] = 0;
  for (long long i = 1; i <= 2e5; i++) pref[i] = pref[i - 1] + i;
  int t;
  cin >> t;
  while (t--) solve();
}
