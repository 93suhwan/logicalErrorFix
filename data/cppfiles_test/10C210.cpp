#include <bits/stdc++.h>
using namespace std;
long long n, k;
void solve() {
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  unordered_map<int, vector<int> > mp;
  for (int i = 0; i < n; i++)
    if (mp[arr[i]].size() < k) mp[arr[i]].push_back(i);
  int m = 0;
  for (auto& e : mp) m += e.second.size();
  m -= m % k;
  vector<int> ans(n);
  int color = 0;
  for (auto& e : mp) {
    for (auto& i : e.second) {
      color++;
      ans[i] = color;
      color %= k;
      m--;
      if (m == 0) {
        break;
      }
    }
    if (m == 0) {
      break;
    }
  }
  for (int i = 0; i < ans.size() - 1; i++) cout << ans[i] << " ";
  cout << ans[ans.size() - 1] << "\n";
}
signed main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
