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
    long long int n, m, i, j, k;
    cin >> n;
    int a[n], b[n];
    for (i = 0; i < n; i++) cin >> a[i] >> b[i];
    vector<long long int> _a(n + 1, 0), _b(n + 1, 0);
    vector<int> ta[n + 1], tb[n + 1];
    long long int ans = 0;
    for (i = 0; i < n; i++) {
      _a[a[i]]++;
      _b[b[i]]++;
    }
    for (i = 0; i < n; i++) {
      ta[a[i]].push_back(b[i]);
      tb[b[i]].push_back(a[i]);
    }
    vector<int> ca(n + 1, 0), cb(n + 1, 0);
    for (i = 1; i <= n; i++) {
      for (auto j : ta[i]) cb[j] += ta[i].size() - 1;
      for (auto j : tb[i]) ca[j] += tb[i].size() - 1;
    }
    long long int cm = 0;
    for (i = 1; i <= n; i++)
      cm += _a[i] * (_a[i] - 1) / 2 + _b[i] * (_b[i] - 1) / 2;
    for (i = 0; i < n; i++) {
      long long int t = n - _a[a[i]] - _b[b[i]] + 1;
      j = _a[a[i]];
      k = _b[b[i]];
      j--;
      k--;
      ans += t * (t - 1) / 2 - cm + j * (j - 1) / 2 + k * (k - 1) / 2 +
             ca[a[i]] + cb[b[i]];
    }
    ans = -ans / 3;
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
