#include <bits/stdc++.h>
using namespace std;
long long n, k, a, in[200005], dp[200005];
vector<pair<long long, long long> > vec[200005];
int main() {
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 1; i <= n; i++) {
      vec[i].clear();
      in[i] = 0;
      dp[i] = 0;
    }
    for (long long i = 1; i <= n; i++) {
      cin >> k;
      in[i] += k;
      while (k--) {
        cin >> a;
        vec[a].push_back({i, (a > i ? 1 : 0)});
      }
    }
    queue<long long> q;
    for (long long i = 1; i <= n; i++) {
      if (in[i] == 0) {
        q.push(i);
        dp[i] = 1;
      }
    }
    while (!q.empty()) {
      long long u = q.front();
      q.pop();
      for (auto p : vec[u]) {
        long long v = p.first;
        long long w = p.second;
        dp[v] = max(dp[v], dp[u] + w);
        in[v]--;
        if (in[v] == 0) q.push(v);
      }
    }
    long long mx = -1, flag = 0;
    for (long long i = 1; i <= n; i++) {
      if (in[i] > 0) flag = 1;
      mx = max(mx, dp[i]);
    }
    if (flag)
      cout << -1 << endl;
    else
      cout << mx << endl;
  }
  return 0;
}
