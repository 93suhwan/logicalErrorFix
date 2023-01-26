#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int N, K, L[MAXN], R[MAXN];
bool ans[MAXN], ok[MAXN];
char C[MAXN];
int P[MAXN], id[MAXN], tp;
string str;
void init(int u) {
  if (L[u]) init(L[u]);
  id[P[tp] = u] = tp, tp++;
  if (R[u]) init(R[u]);
}
bool dfs(int u, int dep) {
  if (dep > K) return false;
  bool ret = false;
  if (ok[id[u]]) ret = true;
  bool tmp = false;
  if (L[u])
    tmp = dfs(L[u], dep + 1);
  else
    tmp = false;
  if (tmp == false && ret) K -= dep;
  ret |= tmp;
  if (ret && R[u]) dfs(R[u], 1);
  ans[u] = ret;
  return ret;
}
void get(int u) {
  if (!u) return;
  get(L[u]);
  str += C[u];
  if (ans[u]) str += C[u];
  get(R[u]);
}
int main() {
  scanf("%d %d %s", &N, &K, C + 1);
  for (int i = (1), iend = (N + 1); i < iend; ++i) {
    scanf("%d %d", &L[i], &R[i]);
  }
  init(1);
  for (int i = (N)-1, iend = (0); i >= iend; --i) {
    if (C[P[i]] < C[P[i + 1]])
      ok[i] = true;
    else if (C[P[i]] == C[P[i + 1]])
      ok[i] = ok[i + 1];
  }
  dfs(1, 1);
  get(1);
  cout << str << '\n';
  return 0;
}
