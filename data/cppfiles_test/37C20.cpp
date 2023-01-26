#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int f = 1, ans = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return f * ans;
}
const int MAXN = 3e5 + 11;
vector<int> vec[MAXN];
int cas, N, Ans[MAXN], nw[MAXN];
bool ff;
void dfs(int u, int fath, int Lim) {
  nw[u] = 0;
  for (auto v : vec[u])
    if (v != fath) dfs(v, u, Lim);
  if (fath) {
    if (nw[u])
      nw[u] = (nw[u] + 1) % Lim;
    else
      nw[fath] = (nw[fath] + 1) % Lim;
  }
  if (nw[u]) ff = 0;
  return;
}
signed main() {
  cas = read();
  while (cas--) {
    N = read();
    for (int i = 1; i <= N; i++) vec[i].clear(), Ans[i] = 0;
    int res = 1;
    for (int i = 1; i < N; i++) {
      res = res * 2 % 998244353;
      int u = read(), v = read();
      vec[u].push_back(v), vec[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 2; i <= N; i++)
      if (!((N - 1) % i)) {
        ff = 1;
        dfs(1, 0, i);
        Ans[i] = ff;
      }
    for (int i = N - 1; i >= 2; i--)
      for (int j = i + i; j <= N - 1; j += i) Ans[i] -= Ans[j];
    for (int i = 2; i <= N - 1; i++) cnt += Ans[i];
    Ans[1] = (res - cnt + 998244353) % 998244353;
    for (int i = 1; i <= N; i++) printf("%d ", Ans[i]);
    printf("\n");
  }
  return 0;
}
