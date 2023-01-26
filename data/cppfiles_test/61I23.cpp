#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int testcase = 1;
  cin >> testcase;
  int __testcase = testcase;
  while (testcase--) {
    int n, m, i, j, k;
    cin >> n;
    int a[n], b[n];
    for (i = 0; i < n; i++) cin >> a[i] >> b[i];
    vector<int> _a(n + 1, 0), _b(n + 1, 0);
    vector<int> cnt(n);
    for (i = 0; i < n; i++) {
      cnt[i] = i - _a[a[i]] - _b[b[i]];
      _a[a[i]]++;
      _b[b[i]]++;
    }
    _a.assign(n + 1, 0);
    _b.assign(n + 1, 0);
    long long int ans = 0;
    for (i = n - 1; i >= 0; i--) {
      long long int t = n - 1 - i - _a[a[i]] - _b[b[i]];
      _a[a[i]]++;
      _b[b[i]]++;
      ans += t * cnt[i];
    }
    ans = -ans;
    long long int suma = 0, sumb = 0;
    for (i = 1; i <= n; i++) {
      ans += suma * _a[i] * (n - suma - _a[i]);
      ans += sumb * _b[i] * (n - sumb - _b[i]);
      suma += _a[i];
      sumb += _b[i];
    }
    cout << ans << endl;
  }
}
