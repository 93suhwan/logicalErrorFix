#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 7;
const int N = 1 << 13;
const int MOD = 1e9 + 7;
int n;
vector<int> G[N];
int up[N];
int ans[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  for (int i = 0; i < N; i++) up[i] = N - 1, G[i].push_back(0);
  ans[0] = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for (int u : G[x]) {
      int v = x ^ u;
      ans[v] = 1;
      while (up[v] > x) G[up[v]].push_back(v), up[v]--;
    }
    G[x].clear();
  }
  int cnt = 0;
  for (int i = 0; i < N; i++) cnt += ans[i];
  cout << cnt << '\n';
  for (int i = 0; i < N; i++)
    if (ans[i]) cout << i << " ";
  cout << '\n';
  return 0;
}
