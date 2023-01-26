#include <bits/stdc++.h>
using namespace std;
int n, ans, tot, tmp, rk[1000005], a[1000005], vis[(1 << 13)], X[(1 << 13)],
    Y[(1 << 13)], Z[(1 << 13)], ok[(1 << 13)];
inline bool cmp(int x, int y) {
  if (a[x] ^ a[y]) return a[x] < a[y];
  return x < y;
}
struct FastIO {
  static const int S = 1048576;
  char buf[S], *L, *R;
  int stk[20], Top;
  ~FastIO() { clear(); }
  inline char nc() {
    return L == R && (R = (L = buf) + fread(buf, 1, S, stdin), L == R) ? EOF
                                                                       : *L++;
  }
  inline void clear() {
    fwrite(buf, 1, Top, stdout);
    Top = 0;
  }
  inline void pc(char ch) {
    Top == S && (clear(), 0);
    buf[Top++] = ch;
  }
  inline void endl() { pc('\n'); }
  FastIO& operator>>(char& ch) {
    while (ch = nc(), ch == ' ' || ch == '\n' || ch == '\r')
      ;
    return *this;
  }
  template <typename T>
  FastIO& operator>>(T& ret) {
    ret = 0;
    int f = 1;
    char ch = nc();
    while (ch < '0' || ch > '9') {
      if (ch == '-') f = -f;
      ch = nc();
    }
    while (ch >= '0' && ch <= '9') {
      ret = ret * 10 + ch - '0';
      ch = nc();
    }
    ret *= f;
    return *this;
  }
  FastIO& operator>>(char* s) {
    int Len = 0;
    char ch = nc();
    while (ch != '\n') {
      *(s + Len) = ch;
      Len++;
      ch = nc();
    }
  }
  template <typename T>
  FastIO& operator<<(T x) {
    if (x < 0) {
      pc('-');
      x = -x;
    }
    do {
      stk[++stk[0]] = x % 10;
      x /= 10;
    } while (x);
    while (stk[0]) pc('0' + stk[stk[0]--]);
    return *this;
  }
  FastIO& operator<<(char ch) {
    pc(ch);
    return *this;
  }
  FastIO& operator<<(string str) {
    int Len = str.size() - 1;
    for (stk[0] = 0; Len >= 0; Len--) stk[++stk[0]] = str[Len];
    while (stk[0]) pc(stk[stk[0]--]);
    return *this;
  }
} fin, fout;
int main() {
  fin >> n;
  for (register int i = 1; i <= n; i++) rk[i] = i, fin >> a[i];
  sort(rk + 1, rk + n + 1, cmp);
  for (register int i = 1; i <= n; i++) {
    int j = i, x = a[rk[i]], tt = 0;
    while (j <= n && x == a[rk[j]]) j++;
    j--;
    if (!vis[x] || vis[x] > rk[i]) vis[x] = rk[i], Y[++tt] = x;
    tmp++;
    for (register int k = 1; k <= tot; k++) {
      while (i <= j && vis[X[k]] >= rk[i]) i++;
      if (i > j) break;
      int y = X[k] ^ x;
      if (vis[y] > rk[i] || !vis[y]) ok[y] = tmp, vis[y] = rk[i], Y[++tt] = y;
    }
    int l = 1, r = 1, T = tot;
    tot = 0;
    while (l <= tt && r <= T) {
      if (ok[X[r]] == tmp) {
        r++;
        continue;
      }
      if (vis[Y[l]] < vis[X[r]])
        Z[++tot] = Y[l], l++;
      else
        Z[++tot] = X[r], r++;
    }
    while (l <= tt) Z[++tot] = Y[l], l++;
    while (r <= T) {
      if (ok[X[r]] == tmp) {
        r++;
        continue;
      }
      Z[++tot] = X[r], r++;
    }
    for (register int k = 1; k <= tot; k++) X[k] = Z[k];
    i = j;
  }
  vis[0] = 1;
  for (register int i = 0; i < (1 << 13); i++)
    if (vis[i]) ans++;
  fout << ans << '\n';
  for (register int i = 0; i < (1 << 13); i++)
    if (vis[i]) fout << i << ' ';
  return 0;
}
