#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int MAXN = 200005;
long long qpow(long long d, long long z) {
  long long res = 1;
  for (; z; z >>= 1) {
    if (z & 1) res = res * d % MOD;
    d = d * d % MOD;
  }
  return res;
}
int n, k;
char str[MAXN];
int ch[MAXN][2], fa[MAXN];
int p[MAXN], rk[MAXN], cur = 0;
int dep[MAXN];
void inord(int x) {
  if (x == 0) return;
  dep[x] = dep[fa[x]] + 1;
  inord(ch[x][0]);
  p[++cur] = x;
  rk[x] = cur;
  inord(ch[x][1]);
}
int diff[MAXN];
bool rep[MAXN];
int curdep;
void solve(int x, int fas) {
  if (x == 0) return;
  solve(ch[x][0], fas);
  int remcd = curdep;
  if (fas == 0) {
    int i = rk[x];
    int z = diff[i];
    if (str[x] < str[p[z]] && dep[x] - curdep <= k) {
      int rc = dep[x] - curdep, xd = x;
      for (int i = 1; i <= rc; i++) {
        rep[xd] = 1;
        xd = fa[xd];
      }
      k -= rc;
      curdep = dep[x];
    } else {
      fas++;
    }
  }
  solve(ch[x][1], fas);
  curdep = remcd;
}
int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", str + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &ch[i][0], &ch[i][1]);
    fa[ch[i][0]] = fa[ch[i][1]] = i;
  }
  fa[0] = 0;
  dep[1] = 1;
  str[n + 1] = 0;
  inord(1);
  for (int i = n; i >= 1; i--) {
    if (str[p[i]] != str[p[i + 1]])
      diff[i] = i + 1;
    else
      diff[i] = diff[i + 1];
  }
  curdep = 0;
  solve(1, 0);
  for (int i = 1; i <= n; i++) {
    printf("%c", str[p[i]]);
    if (rep[p[i]]) printf("%c", str[p[i]]);
  }
  printf("\n");
  return 0;
}
