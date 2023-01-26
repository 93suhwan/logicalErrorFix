#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, a[200200];
set<pair<int, int>> s[200200];
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<pair<int, int>> v;
  for (int i = 1; i <= n; i++)
    if (a[i] <= i) v.push_back({i - a[i], a[i]});
  sort(v.begin(), v.end());
  for (auto [x, y] : v) {
    int l = 1, r = n;
    while (l <= r) {
      int m = (l + r) / 2;
      auto it = s[m].lower_bound({x, y});
      if (it != s[m].begin() && prev(it)->second < y)
        l = m + 1;
      else
        r = m - 1;
    }
    auto it = next(s[l].insert({x, y}).first);
    while (it != s[l].end() && it->second >= y) it = s[l].erase(it);
  }
  int l = 1;
  while (!s[l].empty()) l++;
  cout << l - 1;
}
