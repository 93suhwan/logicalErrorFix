#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
inline int in() {
  char ch = getchar();
  int f = 1, x = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
  return f * x;
}
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int N = 200010;
void Initialization() {}
vector<int> e[N];
pair<int, int> f[N];
void dfs(int u, int F) {
  if (e[u].size() == 0) {
    f[u] = {0, 1};
    return;
  }
  int A = 0, B = 0;
  for (auto v : e[u])
    if (v != F) {
      dfs(v, u);
      A += f[v].first;
      B += f[v].second;
    }
  if (B == 0) {
    f[u] = {A, 1};
  } else {
    f[u] = {A + 1, 0};
  }
}
void solve(int CaseNum) {
  int n = in();
  for (int i = (1); i <= (int)(n); ++i) e[i].clear();
  for (int i = (1); i <= (int)(n - 1); ++i) {
    int u = in(), v = in();
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, 0);
  int ans = 0;
  for (int i = (2); i <= (int)(n); ++i) ans += (f[i].second == 1);
  int A = 0, B = 0;
  for (auto v : e[1]) {
    A += f[v].first;
    B += f[v].second;
  }
  if (B == 0 && A >= 1) {
    ans -= A - 1;
  } else {
    ans -= A;
  }
  printf("%d\n", ans);
}
int main() {
  int T = 1;
  T = in();
  Initialization();
  for (int _ = (1); _ <= (int)(T); ++_) solve(_);
  return 0;
}
