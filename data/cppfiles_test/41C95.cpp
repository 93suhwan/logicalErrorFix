#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1000000007LL;
const int N = 1e6 + 10;
const long long Inf = 2242545357980376863LL;
const long long Log = 30;
vector<int> G[N];
int mk[N];
vector<vector<int>> ans;
int par[N], dep[N];
void DFS(int u, int p, int d) {
  par[u] = p;
  dep[u] = d;
  mk[u] = 1;
  for (auto adj : G[u]) {
    if (mk[adj]) continue;
    DFS(adj, u, d + 1);
  }
}
void Go(int u, int v) {
  vector<int> A, B;
  while (u != v) {
    if (dep[u] <= dep[v]) {
      B.push_back(v);
      v = par[v];
    } else {
      A.push_back(u);
      u = par[u];
    }
  }
  A.push_back(u);
  reverse(B.begin(), B.end());
  for (auto x : B) A.push_back(x);
  ans.push_back(A);
}
int deg[N];
int Main() {
  int n, k;
  cin >> n >> k;
  int t = 1;
  int n2 = k;
  while (n2 < n) n2 *= k, t++;
  cout << t << '\n';
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int a = i - 1, b = j - 1;
      int idx = 0;
      for (int l = 1; l <= t; l++) {
        if (a % k != b % k) idx = l;
        a /= k;
        b /= k;
      }
      cout << idx << ' ';
    }
  }
  cout << '\n';
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) Main();
  return 0;
}
