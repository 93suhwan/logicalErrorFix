#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const long long mod = 998244353;
int n, m, k;
int Pre[N], Suc[N];
int cnt[N], nxt[N];
bool CanId[N], CanVec[N], tVis[N];
long long dp[N << 1];
vector<int> vec[N], Sons[N];
int fa[N];
int _Find(int u) { return u == fa[u] ? u : fa[u] = _Find(fa[u]); }
void check(int Col) {
  for (int now = Suc[Col]; now; now = Suc[now]) {
    int fu = _Find(Pre[now]), fv = _Find(now);
    if (fu == fv)
      CanId[Pre[now]] = CanId[now] = 0;
    else
      fa[fu] = fv;
  }
}
bool CheckCircle(int Col) {
  if (tVis[Col]) return 1;
  for (int now = Suc[Col]; now; now = Suc[now])
    if (Col == now)
      return 0;
    else
      tVis[now] = 1;
  return 1;
}
bool CheckVec(int Id) {
  bool ret = 1;
  for (int i = 0; i < vec[Id].size(); i++)
    if (tVis[vec[Id][i]]) {
      ret = 0;
      break;
    } else
      tVis[vec[Id][i]] = 1;
  for (int i = 0; i < vec[Id].size(); i++) tVis[vec[Id][i]] = 0;
  if (!ret) CanId[vec[Id][0]] = 0;
  return ret;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) fa[i] = i, CanId[i] = CanVec[i] = 1;
  for (int C, i = 1; i <= n; i++) {
    scanf("%d", &C);
    for (int x; C--;) scanf("%d", &x), vec[i].push_back(x);
    CheckVec(i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < vec[i].size(); j++) {
      int Up = vec[i][j - 1], Down = vec[i][j];
      if ((!Pre[Down] || Pre[Down] == Up) && (!Suc[Up] || Suc[Up] == Down)) {
        Pre[Down] = Up;
        Suc[Up] = Down;
      } else
        CanId[Up] = CanId[Down] = 0;
    }
  }
  for (int i = 1; i <= k; i++)
    if (!Pre[i]) check(i);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < vec[i].size(); j++) {
      int Up = vec[i][j - 1], Down = vec[i][j];
      int fu = _Find(Up), fv = _Find(Down);
      if (fu != fv) fa[fu] = fv;
    }
  for (int i = 1; i <= k; i++) _Find(i);
  for (int i = 1; i <= k; i++) tVis[i] = 0;
  for (int i = 1; i <= k; i++) Sons[fa[i]].push_back(i);
  for (int i = 1; i <= k; i++)
    if (!CheckCircle(i)) CanId[i] = 0;
  for (int i = 1; i <= k; i++)
    if (!CanId[i]) CanVec[fa[i]] = 0;
  for (int i = 1; i <= k; i++)
    if (CanVec[i] && Sons[i].size() > 0U) cnt[Sons[i].size()]++;
  int tHead = 0;
  for (int i = 1; i <= k; i++) {
    if (cnt[i]) nxt[tHead] = i, tHead = i;
  }
  dp[0] = 1;
  for (int i = 0; i <= m; i++) {
    for (int j = nxt[0]; j; j = nxt[j]) {
      (dp[i + j] += dp[i] * cnt[j]) %= mod;
    }
  }
  printf("%lld\n", dp[m]);
  return 0;
}
