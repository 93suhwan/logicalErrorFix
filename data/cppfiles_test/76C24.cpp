#include <bits/stdc++.h>
using namespace std;
void _io() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const int MAXN = 200005;
int n, m, k, e[50][50];
int ar[10];
bool ANS;
vector<int> ans;
void dfs(int u, int now) {
  if (ANS) return;
  if (now == 5) {
    bool all1 = true, all0 = true;
    for (int i = 0; i < 5; i++) {
      for (int j = i + 1; j < 5; j++) {
        if (e[ar[i]][ar[j]])
          all0 = false;
        else
          all1 = false;
      }
    }
    if (all0 || all1) {
      ANS = true;
      ans.push_back(ar[0]);
      ans.push_back(ar[1]);
      ans.push_back(ar[2]);
      ans.push_back(ar[3]);
      ans.push_back(ar[4]);
    }
    return;
  }
  for (int i = u + 1; i <= k; i++) {
    ar[now] = i;
    dfs(i, now + 1);
  }
}
int main() {
  _io();
  cin >> n >> m;
  for (int u, v, i = 1; i <= m; i++) {
    cin >> u >> v;
    if (u <= 48 && v <= 48) e[u][v] = e[v][u] = 1;
  }
  k = min(48, n);
  dfs(0, 0);
  if (!ANS)
    cout << "-1";
  else {
    for (auto x : ans) cout << x << ' ';
  }
  return 0;
}
