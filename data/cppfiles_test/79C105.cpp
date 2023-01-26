#include <bits/stdc++.h>
using namespace std;
int n, a[300030], b[300030], dp[300030], pre[300003], pv[300003];
set<int> s;
queue<int> q;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = i - a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    b[i] += i;
  }
  for (int i = 0; i < n; i++) dp[i] = -1;
  dp[n] = 0;
  q.push(n);
  for (int i = 0; i < n; i++) {
    s.insert(i);
  }
  while (q.size()) {
    auto v = q.front();
    q.pop();
    while (true) {
      auto it = s.lower_bound(a[v]);
      if (it == s.end() || *it > v) break;
      if (dp[b[*it]] == -1) {
        pre[b[*it]] = v;
        pv[b[*it]] = *it;
        dp[b[*it]] = dp[v] + 1;
        q.push(b[*it]);
      }
      s.erase(it);
    }
  }
  if (dp[0] == -1)
    cout << "-1\n";
  else {
    cout << dp[0] << "\n";
    vector<int> ans;
    for (int i = 0; i != n; i = pre[i]) ans.push_back(pv[i]);
    reverse(ans.begin(), ans.end());
    for (auto k : ans) {
      cout << k << " ";
    }
    cout << "\n";
  }
  return 0;
}
