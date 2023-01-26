#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e5 + 5, lg = 20;
vector<vector<long long int> > adj;
vector<long long int> a;
void dfs(long long int s, long long int l = 0) {
  a[s] = l;
  for (auto x : adj[s]) {
    if (a[x] > l) {
      dfs(x, l + 1);
    }
  }
}
void runcases(long long int T) {
  long long int n, d;
  cin >> n >> d;
  vector<long long int> v(n);
  adj.clear();
  adj.resize(n + 5);
  a.clear();
  a.assign(n, 1e18);
  for (long long int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] == 0) {
      a[i] = 0;
    } else {
      long long int f = ((i + n - d) % n + n) % n;
      if (f != i) {
        adj[f].push_back(i);
      }
    }
  }
  for (long long int i = 0; i < n; i++) {
    if (a[i] == 0) {
      dfs(i);
    }
  }
  long long int ans = -1;
  for (long long int i = 0; i < n; i++) {
    ans = max(ans, a[i]);
  }
  if (ans == 1e18) {
    ans = -1;
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int T = 1;
  cin >> T;
  for (long long int t = 1; t <= T; t++) {
    runcases(t);
  }
  return 0;
}
