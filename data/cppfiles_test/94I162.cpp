#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  array<__int128, 21> p10 = {};
  p10[0] = 1;
  for (int i = 1; i < 21; i++) {
    p10[i] = p10[i - 1] * 10;
  }
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    array<long long, 21> mp = {};
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      mp[a[i]] = 1;
    }
    __int128 c = 0, need = 0, nn = 0;
    vector<__int128> v(21);
    for (long long j = 0; j < 21; j++) {
      nn = 10LL * nn + 9LL;
      if (mp[j]) {
        c = 0;
      }
      c += 1;
      v[j] = p10[c - 1];
      need += 9LL * p10[c - 1];
    }
    if (need < k) {
      continue;
    }
    long long cj = 20;
    while (need > k && cj >= 0) {
      while (need - v[cj] > k && nn - p10[cj] > 0) {
        need -= v[cj];
        nn -= p10[cj];
      }
      cj -= 1;
    }
    long long z = nn / 10000;
    long long f = nn % 10000;
    cout << z << f << '\n';
  }
  return 0;
}
