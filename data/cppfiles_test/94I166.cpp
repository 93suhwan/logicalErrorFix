#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  array<long long, 19> p10 = {};
  p10[0] = 1;
  for (int i = 1; i < 19; i++) {
    p10[i] = p10[i - 1] * 10;
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    array<int, 19> mp = {};
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mp[a[i]] = 1;
    }
    a.push_back(18);
    for (int i = 0; i <= n; i++) {
      long long c = 0, need = 0, nn = 0;
      vector<long long> v(a[i] + 1);
      for (int j = 0; j < a[i]; j++) {
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
      long long cj = a[i] - 1;
      while (need > k && cj >= 0) {
        while (need - v[cj] > k && nn - p10[cj] > 0) {
          need -= v[cj];
          nn -= p10[cj];
        }
        cj -= 1;
      }
      cout << nn << '\n';
      break;
    }
  }
  return 0;
}
