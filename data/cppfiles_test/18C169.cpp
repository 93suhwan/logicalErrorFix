#include <bits/stdc++.h>
using namespace std;
int cnt(vector<array<int, 2>> l) {
  int re = 0;
  for (int i = 0; i < l.size(); ++i) {
    for (int j = i + 1; j < l.size(); ++j) {
      if (l[i][0] < l[j][0] && l[i][1] > l[j][0] && l[i][1] < l[j][1]) ++re;
      if (l[j][0] < l[i][0] && l[j][1] > l[i][0] && l[j][1] < l[i][1]) ++re;
    }
  }
  return re;
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<bool> check(2 * n + 1, false);
  vector<array<int, 2>> l;
  for (int i = 0; i < k; ++i) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    l.push_back({a, b});
    check[a] = check[b] = true;
  }
  vector<int> left;
  for (int i = 1; i <= 2 * n; ++i) {
    if (!check[i]) left.push_back(i);
  }
  for (int i = 0; i < n - k; ++i) {
    l.push_back({left[i], left[i + n - k]});
  }
  cout << cnt(l) << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
