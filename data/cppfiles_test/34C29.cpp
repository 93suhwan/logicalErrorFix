#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
const int N = 1e6 + 100, K = 10001, INF = 2e18, MOD = 1e9 + 7;
int n, a[N];
vector<bool> ans(K);
vector<vector<bool>> ok(K, vector<bool>(K));
vector<int> v[K];
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < K; i++) {
    ok[i][0] = true;
    v[i].push_back(0);
  }
  for (int i = 0; i < n; i++) {
    for (int x : v[a[i]]) {
      int e = (x ^ a[i]);
      for (int h = a[i] + 1; h < K; h++) {
        if (ok[h][e]) break;
        if (!ok[h][e]) {
          ok[h][e] = true;
          v[h].push_back(e);
        }
      }
    }
    v[a[i]].clear();
  }
  for (int i = 0; i < K; i++) {
    for (int j = 0; j < K; j++) {
      if (ok[i][j]) {
        ans[j] = true;
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < K; i++) {
    cnt += ans[i];
  }
  cout << cnt << '\n';
  for (int i = 0; i < K; i++) {
    if (ans[i]) {
      cout << i << " ";
    }
  }
}
