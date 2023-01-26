#include <bits/stdc++.h>
using namespace std;
long long f[200005];
int a[200005], n;
long long getmod(long long x) {
  long long res = 1;
  int t = 998244353 - 2;
  for (; t; t /= 2, x = (x * x) % 998244353)
    if (t & 1) res = (res * x) % 998244353;
  return res;
}
long long C(int k, int n) {
  long long res = f[n];
  res = (res * getmod(f[k])) % 998244353;
  res = (res * getmod(f[n - k])) % 998244353;
  return res;
}
void Solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1, greater<int>());
  if (a[1] == a[2]) {
    cout << f[n] << '\n';
    return;
  }
  if (a[1] - a[2] > 1) {
    cout << 0 << '\n';
    return;
  }
  int cnt = 0;
  for (int i = 2; i <= n; ++i)
    if (a[i] == a[2]) ++cnt;
  long long ans = 0;
  for (int i = 1; i < n; ++i) {
    if (cnt >= i)
      ans = (ans + f[n - 1]) % 998244353;
    else {
      ans = (ans + (f[n - 1] -
                    ((f[cnt] * C(cnt, i - 1) % 998244353) * f[n - cnt - 1] %
                     998244353) +
                    998244353)) %
            998244353;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  if (fopen("D:\\C++\\clion\\"
            ".inp",
            "r")) {
    freopen(
        "D:\\C++\\clion\\"
        ".inp",
        "r", stdin);
    freopen(
        "D:\\C++\\clion\\"
        ".out",
        "w", stdout);
  }
  f[0] = 1;
  for (int i = 1; i < 200005; ++i) f[i] = f[i - 1] * i % 998244353;
  int t;
  cin >> t;
  while (t--) {
    Solve();
  }
  cerr << "Time collapse : " << fixed << setprecision(3)
       << 1.000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
