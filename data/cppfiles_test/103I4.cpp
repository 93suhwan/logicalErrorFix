#include <bits/stdc++.h>
using namespace std;
const int N = 2001;
const long long infL = 1e18;
const int infI = 1e9 + 7;
const long long mod = 998244353;
int I[N][N], len[N * N];
int g[N * N];
int used[N * N];
string ST;
vector<int> tops;
int idxC = -1;
void dfs(int v) {
  int to = g[v];
  len[v] = 1;
  if (to != -1 && !len[to]) {
    dfs(to);
  }
  tops.push_back(v);
}
bool opposite(char a, char b) {
  return (a == 'R' && b == 'L') || (a == 'L' && b == 'R') ||
         (a == 'U' && b == 'D') || (a == 'D' && b == 'U');
}
void solve() {
  int n, m;
  cin >> n >> m;
  int idx = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) g[idx] = -1, len[idx] = 0, I[i][j] = idx++;
  }
  idx = 0;
  int sz = n * m;
  ST.clear();
  ST.reserve(sz);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      if (s[j] == 'U' && i)
        g[idx] = I[i - 1][j];
      else if (s[j] == 'L' && j)
        g[idx] = I[i][j - 1];
      else if (s[j] == 'R' && j != m - 1)
        g[idx] = I[i][j + 1];
      else if (s[j] == 'D' && i != n - 1)
        g[idx] = I[i + 1][j];
      ST.push_back(s[j]);
      ++idx;
    }
  }
  idxC = -1;
  int mx = 1;
  tops.clear();
  for (int i = 0; i < sz; ++i) {
    if (!len[i]) dfs(i);
  }
  fill(len, len + sz, 0);
  for (int x : tops) {
    int to = g[x];
    if (to == -1) {
      len[x] = 1;
      continue;
    }
    if (len[to])
      len[x] = len[to] + 1;
    else if (opposite(ST[to], ST[x])) {
      len[x] = len[to] = 2;
    } else
      len[x] = 1;
    mx = max(mx, len[x]);
  }
  for (int i = 0; i < sz; ++i) {
    if (len[i] == mx) {
      idxC = i;
      break;
    }
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (I[i][j] == idxC) {
        cout << i + 1 << " " << j + 1 << ' ' << mx << '\n';
        return;
      }
    }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
