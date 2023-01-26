#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    int mx = INT_MIN;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      mx = max(mx, x);
      pq.push(x);
    }
    int add = 0;
    int mn = pq.top();
    int ans = INT_MIN;
    for (int i = 0; i < n - 1; i++) {
      mn = pq.top() - add;
      pq.pop();
      mx = mx - mn;
      add = add + mn;
      ans = max(ans, mn);
    }
    ans = max(ans, mx);
    cout << ans << endl;
  }
  return 0;
}
