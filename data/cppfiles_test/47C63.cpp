#include <bits/stdc++.h>
using namespace std;
int n, k;
long long f(vector<int>& x, vector<int>& y) {
  0;
  long long re = 0;
  while (x.size() > k) {
    re += x.back() * 2ll;
    for (int i = 0; i < k; ++i) x.pop_back();
  }
  if (x.size()) re += x.back() * 2ll;
  while (y.size() > k) {
    re += y.back() * 2ll;
    for (int i = 0; i < k; ++i) y.pop_back();
  }
  if (y.size()) re += y.back() * 2ll;
  0;
  return re;
}
void solve() {
  long long ans = 0;
  cin >> n >> k;
  vector<int> da, xiao;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x > 0) da.push_back(x);
    if (x < 0) xiao.push_back(-x);
  }
  sort(xiao.begin(), xiao.end());
  sort(da.begin(), da.end());
  {
    long long z = 0;
    auto a = xiao, b = da;
    if (a.size()) {
      z += a.back();
      for (int i = 0; i < k; ++i) {
        if (a.size()) a.pop_back();
      }
    }
    z += f(a, b);
    ans = z;
  }
  {
    long long z = 0;
    auto a = xiao, b = da;
    if (b.size()) {
      z += b.back();
      for (int i = 0; i < k; ++i) {
        if (b.size()) b.pop_back();
      }
    }
    z += f(a, b);
    ans = min(ans, z);
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
