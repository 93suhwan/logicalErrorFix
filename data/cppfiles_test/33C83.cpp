#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, t, k;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  t = 1;
  while (t--) {
    cin >> n;
    vector<int> dp(550, 550);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      for (int j = 0; j < 512; j++) {
        if (dp[j] <= x) {
          dp[j ^ x] = min(dp[j ^ x], x);
        }
      }
    }
    set<int> s;
    for (int i = 0; i < 512; i++) {
      if (dp[i] != 550) s.insert(i);
    }
    cout << s.size() << "\n";
    for (int u : s) cout << u << " ";
    cout << "\n";
  }
  return 0;
}
