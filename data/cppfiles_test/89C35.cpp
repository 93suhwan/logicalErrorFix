#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
vector<int> adj[N];
vector<int> tmp;
int k = 0;
bool gl;
int dfs(int v, int p) {
  int flg = 0;
  int cnt = 0;
  for (int i : adj[v]) {
    if (i != p) {
      cnt++;
      flg += dfs(i, v);
    }
  }
  if (v) {
    if (flg)
      k++;
    else
      return 1;
  } else if (flg)
    gl = 1;
  return 0;
}
void solve() {
  int n;
  cin >> n;
  for (long long int i = 0; i < n; ++i) adj[i].clear();
  for (long long int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  gl = 0;
  k = 0;
  dfs(0, 0);
  cout << n - 2 * k - gl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1, tmp = 0;
  cin >> t;
  while (t--) {
    solve();
    if (t) cout << "\n";
  }
  cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n";
  return 0;
}
