#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc, n;
  array<int, 200010> a;
  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    priority_queue<long long int, vector<long long int>, greater<long long int>>
        pq;
    for (int i = 0; i < n; i++) pq.push(a[i]);
    long long int total = 0, ans = numeric_limits<long long int>::min();
    while (!pq.empty()) {
      long long int mn = pq.top();
      pq.pop();
      mn -= total;
      ans = max(ans, mn);
      total += mn;
    }
    cout << ans << "\n";
  }
  return 0;
}
