#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<long long> store(n + 1, 0);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    store[v]++;
  }
  vector<long long> ans(n + 1, -1);
  stack<long long> extras;
  long long extraMoves = 0;
  for (int i = 0; i <= n; i++) {
    long long operations = 0;
    operations += store[i];
    if (i > 0) {
      int idx = i - 1;
      bool cannot = false;
      while (idx >= 0 && store[idx] == 0) {
        if (extras.empty()) {
          cannot = true;
          break;
        }
        long long extraDig = extras.top();
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
