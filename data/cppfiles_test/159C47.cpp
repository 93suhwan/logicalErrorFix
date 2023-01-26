#include <bits/stdc++.h>
std::map<long long, int> mp;
int n, p[1000005], cnt, mindiv[1000005], vis[1000005], flag = 0;
long long val[1000005], pp[1000005], fac[1000005], pre[1000005];
std::mt19937 rd(*new int);
long long getrd(long long l, long long r) {
  std::uniform_int_distribution<long long> rand(l, r);
  return rand(rd);
}
void print() {
  int all = n;
  for (int i = 1; i <= n; i++)
    if (vis[i]) --all;
  printf("%d\n", all);
  for (int i = 1; i <= n; i++)
    if (!vis[i]) printf("%d ", i);
  puts("");
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) p[i] = 1000000000;
  cnt = 0;
  for (int i = 2; i <= n; i++) {
    if (!mindiv[i]) mindiv[i] = i, p[++cnt] = i;
    for (int j = 1; i * p[j] <= n && p[j] <= mindiv[i]; j++)
      mindiv[i * p[j]] = p[j];
  }
  for (int i = 1; i <= cnt; i++) pp[p[i]] = getrd(0, (1ll << 48) - 1);
  for (int i = 1; i <= n; i++) {
    int x = i;
    while (x > 1) val[i] = val[i] ^ pp[mindiv[x]], x = x / mindiv[x];
  }
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] ^ val[i];
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] ^ fac[i];
  long long gg = pre[n];
  if (gg == 0) return print(), 0;
  for (int i = 1; i <= n; i++)
    if ((gg ^ fac[i]) == 0) return vis[i] = 1, print(), 0;
  for (int i = 1; i <= n; i++) mp[gg ^ fac[i]] = i;
  for (int i = 1; i <= n; i++)
    if (mp[fac[i]]) return vis[i] = vis[mp[fac[i]]] = 1, print(), 0;
  int m = n / 4;
  if (n & 2)
    vis[2] = 1, vis[2 * m + 1] = 1;
  else
    vis[2 * m] = 1;
  if (n & 1) vis[n] = 1;
  print();
  return 0;
}
