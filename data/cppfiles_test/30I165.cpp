#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool f = false;
  for (; !isdigit(c); c = getchar()) f |= c == '-';
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  if (f) x = -x;
}
template <typename T, typename... Arg>
inline void read(T &x, Arg &...args) {
  read(x);
  read(args...);
}
template <typename T>
inline void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
const int N = 3e5 + 10, K = 1e6 + 10;
int n, q, a[N];
namespace MAtH {
int tot, pr[K];
bool npr[K];
int mxp[K];
void orz() {
  for (int i = 2; i < K; i++) {
    if (!npr[i]) pr[++tot] = i;
    for (int j = 1; j <= tot && i * pr[j] < K; j++) {
      npr[i * pr[j]] = 1;
      if (i % pr[j] == 0) break;
    }
  }
  for (int i = tot; i; i--)
    for (int j = 1; j * pr[i] < K; j++)
      if (!mxp[j * pr[i]]) mxp[j * pr[i]] = pr[i];
}
vector<int> fac(int x) {
  vector<int> res;
  while (x > 1) {
    res.push_back(mxp[x]);
    x /= mxp[x];
  }
  return res;
}
}  // namespace MAtH
using MAtH::fac;
set<pair<int, int>> S;
int fa[N];
int rt[K];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  fa[x] = y;
}
signed main() {
  MAtH::orz();
  read(n, q);
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= n; i++) {
    read(a[i]);
    auto res = fac(a[i]);
    for (auto x : res)
      if (!rt[x])
        rt[x] = i;
      else
        merge(rt[x], i);
  }
  for (int i = 1; i <= n; i++) {
    auto res = fac(a[i] + 1);
    for (auto x : res)
      if (rt[x]) S.insert({find(i), find(rt[x])});
  }
  while (q--) {
    int s, t;
    read(s, t);
    if (find(s) == find(t))
      puts("0");
    else if (S.count({find(s), find(t)}) || S.count({find(t), find(s)}))
      puts("1");
    else
      puts("2");
  }
}
