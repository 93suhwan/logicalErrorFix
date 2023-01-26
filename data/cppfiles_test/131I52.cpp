#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
using namespace std;
const int N = 2e5 + 7;
int rev(int x) {
  if (!x) return 0;
  int k = 0;
  while ((1 << k) < x) k++;
  return (1 << k) - x;
}
int n, a[N << 5], cnt, pos, mx, poss;
vector<int> v[N << 5];
queue<int> q;
map<int, int> mp;
void dfs(int x, int fa, int dep) {
  if (mx < dep) {
    mx = dep;
    pos = x;
  }
  for (int y, i = 0; i < v[x].size(); i++) {
    y = v[x][i];
    if (y != fa) dfs(y, x, dep + 1);
  }
  return;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) mp[a[i]] = i, q.push(a[i]);
  cnt = n;
  while (!q.empty()) {
    int f = q.front();
    q.pop();
    int r = rev(f);
    if (!mp[r]) mp[r] = ++cnt, a[cnt] = r, q.push(r);
  }
  for (int x, y, i = 1; i <= cnt; i++) {
    if (!a[i]) continue;
    x = mp[a[i]], y = mp[rev(a[i])];
    v[x].push_back(y), v[y].push_back(x);
  }
  dfs(1, -1, 0);
  mx = 0, poss = pos;
  dfs(pos, -1, 0);
  printf("%d %d %d\n", poss, pos, mx);
  return 0;
}
