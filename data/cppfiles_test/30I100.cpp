#include <bits/stdc++.h>
template <class T>
void read(T &x) {
  x = 0;
  char f = 0, c = getc(stdin);
  while (c < '0' || c > '9') f ^= (c == '-'), c = getc(stdin);
  while (c >= '0' && c <= '9') x = x * 10 + (c & 15), c = getc(stdin);
  f && (x = -x);
}
int Max(int a, int b) { return a > b ? a : b; }
int Min(int a, int b) { return a < b ? a : b; }
int Abs(int a) { return a < 0 ? -a : a; }
long long sqr(int a) { return (long long)a * a; }
int qpow(int a, int b) {
  if (b < 0) return 0;
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * a * ans % 1000000007;
    a = 1ll * a * a % 1000000007;
    b >>= 1;
  }
  return ans;
}
int T = 1;
int n, k;
int a[150010];
int s, t;
std ::vector<int> d[1000010];
int fa[1000010];
int f(int x) { return (fa[x] == x) ? x : (fa[x] = f(fa[x])); }
std ::set<std ::pair<int, int> > mp;
int tmp[2][110];
int main() {
  for (int i = 2; i <= 1000001; ++i)
    if (!d[i].size())
      for (int j = i; j <= 1000001; j += i) d[j].push_back(i);
  while (T--) {
    read(n), read(k);
    for (int i = 1; i <= 1000001; ++i) fa[i] = i;
    for (int i = 1; i <= n; ++i) {
      read(a[i]);
      for (int p : d[a[i]]) fa[f(a[i])] = f(p);
    }
    for (int i = 1; i <= n; ++i) {
      for (int q : d[a[i] + 1])
        mp.insert(std ::make_pair(Min(f(a[i]), f(q)), Max(f(a[i]), f(q))));
    }
    while (k--) {
      read(s), read(t);
      s = f(a[s]), t = f(a[t]);
      if (s > t) std ::swap(s, t);
      if (s == t)
        puts("0");
      else {
        auto it = mp.find(std ::make_pair(s, t));
        if (it != mp.end() && *it == std ::make_pair(s, t))
          puts("1");
        else
          puts("2");
      }
    }
  }
}
