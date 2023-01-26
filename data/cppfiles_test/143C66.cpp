#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> cnt(n + 1);
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    cnt[x]++;
  }
  long long ans = cnt[0];
  stack<pair<long long, long long>> stk;
  for (long long i = 0; i <= n; i++) {
    if (ans != -1 && i - 1 >= 0) {
      ans = ans - cnt[i - 1] + cnt[i];
      if (cnt[i - 1] == 0) {
        if (stk.size()) {
          auto x = stk.top();
          stk.pop();
          ans += (i - 1 - x.first);
          if (x.second - 1) stk.push({x.first, x.second - 1});
        } else {
          ans = -1;
        }
      }
    }
    cout << ans << ' ';
    if (ans != -1 && cnt[i] - 1 > 0) stk.push({i, cnt[i] - 1});
  }
  cout << '\n';
}
signed main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
