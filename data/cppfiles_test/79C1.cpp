#include <bits/stdc++.h>
using namespace std;
int const N = 3e5 + 3;
int a[N], b[N], cad[N], t[N];
bool viz[N];
int dp[N], prv[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0x0);
  cout.tie(0x0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    cad[i] = i + b[i];
    prv[i + b[i]] = i;
  }
  queue<int> q;
  q.push(n);
  viz[n] = true;
  dp[n] = 0;
  int nextNode = n - 1;
  fill(dp, dp + n, (1 << 30));
  while (q.size()) {
    int x = q.front();
    q.pop();
    if (a[x] >= x) {
      dp[0] = 1 + dp[x];
      t[0] = x;
      while (q.size()) q.pop();
      continue;
    }
    for (; nextNode >= x - a[x]; --nextNode) {
      int to = cad[nextNode];
      if (!viz[to]) {
        dp[to] = 1 + dp[x];
        viz[to] = true;
        t[to] = x;
        q.push(to);
      }
    }
  }
  if (dp[0] >= (1 << 30)) {
    cout << "-1\n";
    exit(0);
  }
  cout << dp[0] << '\n';
  int node = 0;
  vector<int> sol;
  while (t[node]) {
    sol.push_back(prv[node]);
    node = t[node];
  }
  reverse(sol.begin(), sol.end());
  for (auto y : sol) cout << y << ' ';
  return 0;
}
