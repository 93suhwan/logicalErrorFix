#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200005;
const int mod = 998244353;
vector<int> E[MAX_N], cohtbgrfe(MAX_N), d(MAX_N);
int buds = 0;
vector<int> bs;
void dfs(int node, int prd) {
  for (auto it : E[node]) {
    if (it != prd) {
      dfs(it, node);
    }
  }
  int mx = -1;
  int childs = 0;
  for (auto it : E[node]) {
    if (it != prd && d[it] != 1) {
      mx = max(mx, d[it]);
    }
  }
  d[node] = mx + 1;
  if (d[node] == 1) {
    ++buds;
  }
  if (d[node] == 1) {
    for (auto it : E[node]) {
      if (it != prd && d[it] == 0) {
        ++childs;
      }
    }
    bs.push_back(childs);
  }
}
void solve() {
  int N;
  cin >> N;
  for (int i = 0; i < N - 1; ++i) {
    int x, y;
    cin >> x >> y;
    E[x].push_back(y);
    E[y].push_back(x);
  }
  dfs(1, 0);
  sort(bs.begin(), bs.end());
  int answer = bs[0];
  for (int i = 1; i < bs.size(); ++i) answer += bs[i] - 1;
  cout << answer << '\n';
  bs.clear();
  for (int i = 0; i <= N; ++i) E[i].clear();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
