#include <bits/stdc++.h>
using namespace std;
void run() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m));
  map<int, vector<int>> mp;
  for (int i = 1; i < n * m + 1; i++) {
    int k;
    cin >> k;
    mp[k].push_back(i);
  }
  set<int> s;
  int ans = 0;
  int row_filled = 0;
  int seat_left = m;
  for (auto x : mp) {
    int q = 0;
    for (auto y : x.second) {
      if (s.size() + q >= m) {
        q = 0;
        s.clear();
      }
      auto val = lower_bound(s.begin(), s.end(), y);
      auto k = s.begin();
      int count = 0;
      while (k != val) {
        count++;
        k++;
      }
      q++;
      ans += count;
    }
    int value = 0;
    if (s.size() + x.second.size() >= m) {
      int l = m - s.size();
      int k = x.second.size() - l;
      int g = k / m;
      value = l + g * m;
      s.clear();
    }
    s.insert(x.second.begin() + value, x.second.end());
  }
  cout << ans;
}
int main() {
  run();
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
