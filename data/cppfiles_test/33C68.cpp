#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<bool> dp(520, 0);
  vector<int> pos(520, n + 10);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[0] = 1;
  dp[a[1]] = 1;
  pos[a[1]] = a[1];
  for (int i = 2; i <= n; i++) {
    dp[a[i]] = 1;
    pos[a[i]] = min(pos[a[i]], a[i]);
    for (int k = 0; k < 520; k++) {
      if (dp[k] && pos[k] <= a[i]) {
        dp[k ^ a[i]] = 1;
        pos[k ^ a[i]] = min(pos[k ^ a[i]], a[i]);
      }
    }
  }
  vector<int> ans;
  for (int i = 0; i < 520; i++) {
    if (dp[i]) ans.push_back(i);
  }
  cout << ans.size() << '\n';
  for (auto e : ans) {
    cout << e << ' ';
  }
  cout << '\n';
}
int main() { solve(); }
