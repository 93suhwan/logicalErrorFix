#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("179")
#pragma GCC optimize("unroll-loops")
using namespace std;
void solve() {
  long long n, s = 0;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
    s += a[i];
  }
  if (n < 10) {
    cout << -(s - a[0]) << " ";
    for (long long i = 1; i < n; ++i) {
      cout << a[0] << " ";
    }
    cout << '\n';
    return;
  }
  if (n % 2 == 0) {
    for (long long i = 0; i < n; i += 2) {
      cout << -a[i + 1] << " " << a[i] << '\n';
    }
    return;
  }
  vector<long long> ind, ind1;
  for (long long i = 0; i < n; ++i) {
    if (a[i] > 0)
      ind.push_back(i);
    else
      ind1.push_back(i);
  }
  if (ind.size() > 2) {
    swap(ind, ind1);
  }
  while (ind.size() > 3) ind1.push_back(ind.back()), ind.pop_back();
  vector<long long> ans(n);
  ans[ind[0]] = -(a[ind[1]] + a[ind[2]]);
  ans[ind[1]] = ans[ind[2]] = a[ind[0]];
  for (long long i = 0; i < n - 3; i += 2) {
    ans[ind1[i]] = a[ind1[i + 1]], ans[ind1[i + 1]] = -a[ind1[i]];
  }
  for (long long i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
