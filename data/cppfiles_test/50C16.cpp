#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5;
const int Mod = 998244353;
int a[Maxn + 5], l[Maxn + 5];
int f[Maxn + 5], sum[Maxn + 5];
int n;
int getsum(int l, int r) {
  int val = (sum[r - 1] - sum[l - 1] + Mod) % Mod;
  if ((l & 1) ^ ((r - l + 1) & 1)) val = Mod - val;
  return val;
}
int main() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; i++) scanf("%d", &a[i]);
  stack<int> s;
  for (register int i = 1; i <= n; i++) {
    while (!s.empty() && a[s.top()] > a[i]) s.pop();
    if (!s.empty()) l[i] = s.top();
    s.push(i);
  }
  f[0] = sum[0] = 1;
  for (register int i = 1; i <= n; i++) {
    int k = l[i];
    if (k) f[i] = (i - k) & 1 ? Mod - f[k] : f[k];
    f[i] = (f[i] + 1ll * a[i] * getsum(k, i) % Mod) % Mod;
    sum[i] = (sum[i - 1] + (i & 1 ? Mod - f[i] : f[i])) % Mod;
  }
  printf("%d\n", f[n]);
  return 0;
}
