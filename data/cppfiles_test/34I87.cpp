#include <bits/stdc++.h>
using namespace std;
int read() {
  char ch = getchar();
  int x = 0, pd = 0;
  while (ch < '0' || ch > '9') pd |= ch == '-', ch = getchar();
  while ('0' <= ch && ch <= '9') x = x * 10 + (ch ^ 48), ch = getchar();
  return pd ? -x : x;
}
int Add(int x, int y) { return x + y < 998244353 ? x + y : x + y - 998244353; }
int Mul(int x, int y) { return 1ll * x * y % 998244353; }
int Pow(int x, int y) {
  int res = 1;
  for (; y; y >>= 1, x = Mul(x, x))
    if (y & 1) res = Mul(res, x);
  return res;
}
const int maxn = 1000005;
int n, a[maxn];
int b[5005][13], vis[5005], tim[5005];
int pd;
void insert(int x, int y) {
  bool ck = 1;
  for (int i = 12; i >= 0 && x; i--)
    if (x >> i & 1) {
      if (!b[y][i])
        swap(b[y][i], x), ck = 0;
      else
        x ^= b[y][i];
    }
  pd |= ck;
}
bool qry(int y, int x) {
  for (int i = 12; i >= 0 && x; i--)
    if (x >> i & 1) x ^= b[y][i];
  return x != 0;
}
vector<int> ans;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read(), pd |= !a[i], tim[a[i]] = i;
  for (int i = 1; i <= n; i++)
    if (!vis[a[i]] && a[i]) {
      for (int j = a[i]; j <= 5000; j++)
        if (tim[j] >= i) insert(a[i], j);
      vis[a[i]] = 1;
    } else
      pd = 1;
  if (pd) ans.push_back(0);
  for (int i = 1; i < 8192; i++) {
    bool ok = 1;
    for (int j = 1; j <= 5000 && ok; j++) ok = qry(j, i);
    if (!ok) ans.push_back(i);
  }
  printf("%d\n", (int)ans.size());
  for (int x : ans) printf("%d ", x);
  return 0;
}
