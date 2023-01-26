#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
;
const int sz = 6e5 + 5;
const int N = 1e6;
void solve() {
  long long n;
  cin >> n;
  map<long long, long long> m;
  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    m[a]++;
  }
  long long ans[n + 1];
  memset(ans, -1, sizeof ans);
  long long cost = 0;
  priority_queue<long long> q;
  for (long long i = 0; i < n + 1; i++) {
    ans[i] = cost + m[i];
    if (m[i]) {
      for (long long j = 0; j < m[i] - 1; j++) {
        q.push(i);
      }
      continue;
    }
    if (q.empty()) break;
    cost += (i - q.top());
    q.pop();
  }
  for (long long i = 0; i < n + 1; i++) cout << ans[i] << ' ';
  cout << "\n";
}
int32_t main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  }
  long long T;
  T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
