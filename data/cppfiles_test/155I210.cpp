#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &x : a) cin >> x;
  string s;
  cin >> s;
  vector<long long> b, c;
  b.clear();
  c.clear();
  for (int i = 0; i < n; i++) {
    if (s[i] == '0')
      b.push_back(a[i]);
    else if (s[i] == '1')
      c.push_back(a[i]);
  }
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  long long cnt = 1;
  vector<long long> ans(n + 1, 0);
  for (auto i : b) ans[i] = cnt, cnt += 1;
  for (auto i : c) ans[i] = cnt, cnt += 1;
  for (auto x : ans) cout << x << ' ';
  cout << '\n';
}
int main() {
  int t;
  for (cin >> t; t; t--) solve();
}
