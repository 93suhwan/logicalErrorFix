#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  int ans = 0;
  int j = 1;
  vector<int> ost;
  multiset<int> s;
  for (int i = 0; i < n; ++i) s.insert(a[i]);
  for (int i = 0; i < n; ++i) {
    if (!s.count(i + 1))
      ost.push_back(i + 1);
    else
      s.erase(s.find(i + 1));
  }
  ans = ost.size();
  for (int i = 0; i < ost.size(); ++i) {
    auto j = s.lower_bound(2 * ost[i] + 1);
    if (j == s.end())
      ans = -1;
    else {
      s.erase(j);
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
