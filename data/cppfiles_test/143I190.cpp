#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> store(n + 1, 0);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    store[v]++;
  }
  vector<int> ans(n + 1, -1);
  stack<int> extras;
  int extraMoves = 0;
  for (int i = 0; i <= n; i++) {
    int operations = 0;
    operations += store[i];
    if (i > 0) {
      int idx = i - 1;
      bool cannot = false;
      while (idx >= 0 && store[idx] == 0) {
        if (extras.empty()) {
          cannot = true;
          break;
        }
        int extraDig = extras.top();
        extras.pop();
        extraMoves += idx - extraDig;
        store[idx]++;
        idx--;
      }
      if (cannot) {
        break;
      }
      operations += extraMoves;
    }
    for (int j = 0; j < store[i] - 1; j++) {
      extras.push(i);
    }
    ans[i] = operations;
  }
  for (int i = 0; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
