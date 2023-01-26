#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chkmin(T &first, T second) {
  return second < first ? first = second, 1 : 0;
}
template <typename T>
bool chkmax(T &first, T second) {
  return first < second ? first = second, 1 : 0;
}
template <typename T>
void readint(T &first) {
  int f = 1;
  char c;
  first = 0;
  for (c = getchar(); !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) first = first * 10 + (c - '0');
  first *= f;
}
const int MOD = 1000000007;
inline int dmy(int first) { return first >= MOD ? first - MOD : first; }
inline void inc(int &first, int second) { first = dmy(first + second); }
int qmi(int first, int second) {
  int ans = 1;
  for (; second; second >>= 1, first = 1ll * first * first % MOD)
    if (second & 1) ans = 1ll * ans * first % MOD;
  return ans;
}
const int MAXN = 750005;
int n, m;
pair<int, int> e[MAXN];
bool ins[MAXN];
int ch[MAXN][2], fa[MAXN], sz[MAXN];
bool rev[MAXN];
int sum[MAXN], hv[MAXN], col[MAXN], tag[MAXN];
bool nroot(int first) {
  return ch[fa[first]][0] == first || ch[fa[first]][1] == first;
}
bool sonr(int first) { return ch[fa[first]][1] == first; }
void reverse(int first) {
  rev[first] ^= 1;
  swap(ch[first][0], ch[first][1]);
}
void cover(int first, int c) {
  sum[first] = sz[first], hv[first] = (first > n), col[first] = c,
  tag[first] = 1;
}
void clean(int first) {
  sum[first] = 0, hv[first] = 0, col[first] = 0, tag[first] = -1;
}
void pushdown(int first) {
  if (rev[first]) reverse(ch[first][0]), reverse(ch[first][1]), rev[first] = 0;
  if (tag[first] == 1)
    cover(ch[first][0], col[first]), cover(ch[first][1], col[first]),
        tag[first] = 0;
  else if (tag[first] == -1)
    clean(ch[first][0]), clean(ch[first][1]), tag[first] = 0;
}
void pushall(int first) {
  if (nroot(first)) pushall(fa[first]);
  pushdown(first);
}
void update(int first) {
  sum[first] = sum[ch[first][0]] + sum[ch[first][1]] + hv[first];
  sz[first] = sz[ch[first][0]] + sz[ch[first][1]] + (first > n);
}
void rotate(int first) {
  int second = fa[first], z = fa[second], ty = sonr(first),
      s = ch[first][ty ^ 1];
  if (nroot(second)) ch[z][sonr(second)] = first;
  ch[first][ty ^ 1] = second, ch[second][ty] = s;
  fa[first] = z, fa[second] = first;
  if (s) fa[s] = second;
  update(second), update(first);
}
void splay(int first) {
  pushall(first);
  while (nroot(first))
    if (!nroot(fa[first]))
      rotate(first);
    else if (sonr(first) == sonr(fa[first]))
      rotate(fa[first]), rotate(first);
    else
      rotate(first), rotate(first);
}
void access(int first) {
  for (int second = 0; first; first = fa[second = first])
    splay(first), ch[first][1] = second, update(first);
}
void makeroot(int first) {
  access(first);
  splay(first);
  reverse(first);
}
void link(int first, int second) {
  makeroot(first);
  makeroot(second);
  fa[first] = second;
}
void cut(int first, int second) {
  makeroot(first);
  access(second);
  splay(first);
  ch[first][1] = fa[second] = 0;
  update(first);
}
bool nok(int first, int second) {
  makeroot(first), access(second), splay(second), splay(first);
  return nroot(second) && sum[first];
}
void insert(int t) {
  int first = e[t].first, second = e[t].second;
  makeroot(first), access(second), splay(second), splay(first);
  if (!nroot(second))
    link(first, t + n), link(second, t + n), ins[t] = 1;
  else
    cover(first, t);
}
void erase(int t) {
  int first = e[t].first, second = e[t].second;
  if (!ins[t])
    makeroot(first), access(second), splay(second), clean(second);
  else {
    splay(t + n);
    if (col[t + n]) {
      int s = col[t + n];
      int u = e[s].first, v = e[s].second;
      makeroot(u), access(v), splay(v), clean(v);
      cut(t + n, first), cut(t + n, second), ins[t] = 0;
      insert(s);
    } else
      cut(t + n, first), cut(t + n, second), ins[t] = 0;
  }
}
int main() {
  readint(n), readint(m);
  for (int i = 1; i <= m; ++i) readint(e[i].first), readint(e[i].second);
  for (int i = 1; i <= n + m; ++i) sz[i] = 1;
  long long res = 0;
  for (int l = 1, r = 1; r <= m; ++r) {
    while (l <= r && nok(e[r].first, e[r].second)) erase(l), ++l;
    insert(r);
    res += r - l + 1;
  }
  printf("%lld\n", res);
  return 0;
}
