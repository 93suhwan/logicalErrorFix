#include <bits/stdc++.h>
using namespace std;
long long n, d;
const long long maxn = 1e6;
long long arr[maxn + 5];
long long dist[maxn + 5];
long long bfs() {
  queue<long long> q;
  for (long long i = 0; i < n; i++) {
    if (arr[i] == 0) {
      q.push(i);
      dist[i] = 0;
    }
  }
  long long ans = 0;
  while (!q.empty()) {
    long long tp = q.front();
    q.pop();
    if (dist[(tp + d) % n] == 1e6 + 1) {
      dist[(tp + d) % n] = dist[tp] + 1;
      q.push((tp + d) % n);
      ans = max(ans, dist[(tp + d) % n]);
    }
  }
  bool ok = true;
  for (long long i = 0; i < n; i++) {
    if (dist[i] == 1e6 + 1) {
      ok = false;
      break;
    }
  }
  return (ok ? ans : -1);
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    cin >> n >> d;
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    for (long long i = 0; i < n; i++) dist[i] = 1e6 + 1;
    long long ans = bfs();
    cout << ans << endl;
  }
  return 0;
}
