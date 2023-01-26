#include <bits/stdc++.h>
using namespace std;
int n, m, top, st[500005], s[500005], a[500005], rk[500005];
inline bool cmp(int x, int y) {
  if (a[x] > s[y] && s[x] >= a[y]) return 0;
  if (a[x] <= s[y] && s[x] < a[y]) return 1;
  return a[x] < a[y];
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
  fin >> n >> m;
  for (register int i = 1; i <= n; i++) fin >> s[i] >> a[i], rk[i] = i;
  sort(rk + 1, rk + n + 1, cmp), st[++top] = m;
  for (register int i = 1; i <= n; i++) {
    int l = 1, r = top, num = 0, S = s[rk[i]], A = a[rk[i]];
    while (l <= r) {
      int mid = l + r >> 1;
      if (st[mid] <= S)
        num = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    if (!num) continue;
    if (num == top)
      st[++top] = A;
    else
      st[num + 1] = min(st[num + 1], max(st[num], A));
  }
  fout << top - 1 << '\n';
  return 0;
}
