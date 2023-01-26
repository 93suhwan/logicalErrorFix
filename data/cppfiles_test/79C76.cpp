#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int &i : a) cin >> i;
  for (int &i : b) cin >> i;
  set<int> s;
  for (int i = 0; i < n; ++i) s.insert(i);
  vector<int> dp(n + 1, -1);
  dp[n] = 0;
  queue<int> q;
  q.push(n);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (x == 0) break;
    int y = x;
    x += b[x - 1];
    int r = x, l = x - a[x - 1];
    while (true) {
      auto it = s.lower_bound(l);
      if (it != s.end() && *it <= r) {
        dp[*it] = y;
        q.push(*it);
        s.erase(it);
      } else
        break;
    }
  }
  if (dp[0] == -1)
    cout << "-1\n";
  else {
    vector<int> ans;
    int x = 0;
    while (x != n) {
      ans.push_back(x);
      x = dp[x];
    }
    cout << ans.size() << "\n";
    reverse(ans.begin(), ans.end());
    for (auto &i : ans) cout << i << " \n"[&i == &ans.back()];
  }
  return 0;
}
