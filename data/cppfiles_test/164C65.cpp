#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, k, l[maxn], r[maxn], lans, to[maxn], lc2, bac[maxn], L[maxn], R[maxn],
    t[maxn];
char c[maxn], c2[maxn], nxt[maxn];
char ans[maxn * 2];
bool b[maxn], db[maxn];
void ss1(int x) {
  if (l[x]) ss1(l[x]);
  c2[++lc2] = c[x];
  to[x] = lc2;
  bac[to[x]] = x;
  if (r[x]) ss1(r[x]);
  return;
}
int ss2(int x) {
  L[x] = 9999999;
  R[x] = 9999999;
  if (l[x]) L[x] = ss2(l[x]);
  if (r[x]) R[x] = ss2(r[x]);
  if (b[x])
    return t[x] = 1;
  else
    return t[x] = L[x] + 1;
}
bool ss3(int x) {
  bool flag = false;
  if (t[x] <= k) {
    k--;
    db[x] = true;
    flag = true;
    if (L[x] <= k) flag = flag | ss3(l[x]);
    if (R[x] <= k && flag) ss3(r[x]);
  }
  return flag;
}
void ss4(int x) {
  if (l[x]) ss4(l[x]);
  ans[++lans] = c[x];
  if (db[x]) {
    ans[++lans] = c[x];
  }
  if (r[x]) ss4(r[x]);
  return;
}
int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", c + 1);
  for (int i = 1; i <= n; i++) scanf("%d%d", &l[i], &r[i]);
  ss1(1);
  c2[lc2 + 1] = 'a' - 5;
  for (int i = lc2; i >= 1; i--) {
    if (c2[i] == c2[i + 1])
      nxt[i] = nxt[i + 1];
    else
      nxt[i] = c2[i + 1];
    if (c2[i] < nxt[i]) b[bac[i]] = true;
  }
  ss2(1);
  ss3(1);
  ss4(1);
  printf("%s\n", ans + 1);
}
