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
    auto f = [&](__int128 x) {
      __int128 ans = 0;
      for (int i = 20; i >= 0; i--) {
        __int128 d = x / p10[i];
        x -= d * p10[i];
        if (!d) continue;
        __int128 c = 0;
        for (int j = i; j >= 0; j--) {
          if (mp[j]) {
            ans += d * p10[c];
            break;
          }
          c += 1;
        }
      }
      return ans;
    };
    __int128 nn = 0;
    vector<__int128> v(21);
    for (long long j = 0; j < 21; j++) {
      nn = 10LL * nn + 9LL;
    }
    if (f(nn) < k) {
      assert(false);
    }
    long long cj = 20;
    while (f(nn) > k && cj >= 0) {
      while (nn - p10[cj] > 0 && f(nn - p10[cj]) > k) {
        nn -= p10[cj];
      }
      cj -= 1;
    }
    cout << (long long)nn << '\n';
  }
  return 0;
}
