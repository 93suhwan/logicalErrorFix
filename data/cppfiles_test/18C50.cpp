#include <bits/stdc++.h>
using namespace std;
void solve(long long int caseno) {
  long long int i, j, n, d, ans = 0, ones = 0;
  cin >> n >> d;
  vector<long long int> arr(n);
  queue<pair<long long int, long long int> > q;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] == 1) ones++;
    if (arr[i] == 0) q.push({(i + d) % n, 1});
  }
  while (!q.empty()) {
    long long int i = q.front().first, t = q.front().second;
    q.pop();
    if (arr[i] == 1) {
      ans = max(ans, t);
      arr[i] = 0;
      ones--;
      q.push({(i + d) % n, t + 1});
    }
  }
  if (ones == 0) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}
