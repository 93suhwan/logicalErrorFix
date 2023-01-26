#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
void solve() {
  cin >> n;
  vector<int> c(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> k;
    c[k]++;
  }
  long long ans = 0;
  long long sum = 0;
  ans = c[0];
  cout << ans << " ";
  priority_queue<int> q;
  for (int i = 0; i < c[0] - 1; i++) q.push(0);
  for (int i = 1; i <= n; i++) {
    ans -= c[i - 1];
    ans += c[i];
    if (c[i - 1] == 0) {
      if (q.empty()) {
        for (int j = i; j <= n; j++) cout << "-1 ";
        cout << "\n";
        return;
      }
      int x = q.top();
      q.pop();
      ans += i - 1 - x;
    }
    cout << ans << " ";
    for (int j = 0; j < max(0, c[i] - 1); j++) q.push(i);
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) solve();
}
