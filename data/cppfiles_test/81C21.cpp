#include <bits/stdc++.h>
using namespace std;
int n, m, ans, tot1, tot2, Max, s[500005], a[500005], A[500005], B[500005];
inline bool cmp1(int x, int y) { return a[x] < a[y]; }
inline bool cmp2(int x, int y) { return s[x] < s[y]; }
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
  for (register int i = 1; i <= n; i++)
    fin >> s[i] >> a[i],
        (s[i] >= m) && (s[i] < a[i] ? A[++tot1] = i : B[++tot2] = i, 0);
  sort(A + 1, A + tot1 + 1, cmp1), sort(B + 1, B + tot2 + 1, cmp2);
  int now = 1;
  for (register int i = 1; i <= tot1; i++) {
    while (now <= tot2 && s[B[now]] < a[A[i]]) Max = max(Max, a[B[now]]), now++;
    if (Max > s[A[i]]) continue;
    if (s[A[i]] >= m) m = a[A[i]], ans++;
  }
  fout << ans + tot2 << '\n';
  return 0;
}
