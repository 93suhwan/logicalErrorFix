#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
const int maxm = 4e5 + 50;
int T, n, fa[maxn];
int fir[maxn], nex[maxm], to[maxm], ecnt;
bool mk[maxn];
void add(int u, int v) {
  nex[++ecnt] = fir[u];
  fir[u] = ecnt;
  to[ecnt] = v;
}
void dfs(int x, int f) {
  fa[x] = f;
  mk[x] = 0;
  for (int e = fir[x]; e; e = nex[e]) {
    int v = to[e];
    if (v == f) continue;
    dfs(v, x);
    mk[x] |= !mk[v];
  }
}
template <typename T>
void inline read(T &aa) {
  long long ff = 1;
  char cc = getchar();
  aa = 0;
  while ((cc < '0' || cc > '9') && cc != '-') cc = getchar();
  if (cc == '-') ff = -1, cc = getchar();
  while (cc <= '9' && cc >= '0') aa = aa * 10 + cc - 48, cc = getchar();
  aa *= ff;
}
int main() {
  read(T);
  while (T--) {
    read(n);
    for (int i = 1; i <= n; i++) {
      mk[i] = 0;
      fa[i] = 0;
      fir[i] = 0;
      nex[i] = 0;
      nex[i + n] = 0;
      to[i] = 0;
      to[i + n] = 0;
      ecnt = 0;
    }
    for (int i = 1; i < n; i++) {
      int x, y;
      read(x), read(y);
      add(x, y);
      add(y, x);
    }
    dfs(1, 0);
    int ans = 0;
    for (int i = 2; i <= n; i++) {
      if (!mk[i])
        ans++;
      else
        ans--;
    }
    if (!mk[1]) ans++;
    cout << ans << endl;
  }
  return 0;
}
