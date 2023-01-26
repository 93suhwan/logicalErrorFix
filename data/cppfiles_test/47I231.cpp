#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long ans = 0;
  int n, k;
  cin >> n >> k;
  vector<int> da, xiao;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x > 0) da.push_back(x);
    if (x < 0) xiao.push_back(-x);
  }
  sort(da.rbegin(), da.rend());
  sort(xiao.rbegin(), xiao.rend());
  if (da.size() == 0) {
    swap(da, xiao);
  } else {
    if (xiao.size() != 0) {
      if (xiao[0] > da[0]) {
        swap(xiao, da);
      }
    }
  }
  sort(xiao.begin(), xiao.end());
  while (xiao.size() > k) {
    ans += xiao.back() * 2ll;
    for (int i = 0; i < k; ++i) xiao.pop_back();
  }
  if (xiao.size()) ans += xiao.back() * 2ll;
  sort(da.begin(), da.end());
  if (da.size() >= k) {
    ans += da.back();
    for (int i = 0; i < k; ++i) da.pop_back();
  }
  while (da.size() > k) {
    ans += da.back() * 2ll;
    for (int i = 0; i < k; ++i) da.pop_back();
  }
  if (da.size()) ans += da.back() * 2ll;
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
