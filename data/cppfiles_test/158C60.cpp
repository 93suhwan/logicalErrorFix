#include <bits/stdc++.h>
using namespace std;
void solve_case();
signed main() {
  cin.tie(0), cout.tie(0)->sync_with_stdio(0);
  int test;
  cin >> test;
  while (test--) {
    solve_case();
  }
}
const int N = 15, M = 1e4 + 5;
int n, m, a[N], delta[M], p[M], res[M];
vector<int> vec[N * 2];
long long ans;
string s[N];
void solve_case() {
  cin >> n >> m;
  ans = -1;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int mask = 0; mask < 1 << n; mask++) {
    fill(delta, delta + m, 0);
    long long cur = 0;
    for (int i = 0; i < n; i++) {
      int f = mask >> i & 1 ? 1 : -1;
      cur -= f * a[i];
      for (int j = 0; j < m; j++)
        if (s[i][j] == '1') delta[j] += f;
    }
    for (int i = 0; i < m; i++) vec[delta[i] + N].push_back(i);
    for (int i = 0, f = 1; i < N * 2; i++) {
      for (auto v : vec[i]) {
        cur += f * delta[v];
        p[v] = f++;
      }
      vec[i].clear();
    }
    if (cur > ans) {
      ans = cur;
      for (int i = 0; i < m; i++) res[i] = p[i];
    }
  }
  for (int i = 0; i < m; i++) cout << res[i] << ' ';
  cout << '\n';
}
