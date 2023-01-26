#include <bits/stdc++.h>
namespace hyy {
const int MAXSIZE = 1 << 20;
inline char gc() {
  return getchar();
  static char buf[MAXSIZE];
  static char *p1 = buf + MAXSIZE;
  static char *p2 = buf + MAXSIZE;
  if (p1 == p2) {
    p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
  }
  if (p1 == p2) {
    return -1;
  }
  return *p1++;
}
inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
template <class T>
inline void read(T &x) {
  register double tmp = 1;
  register bool sign = 0;
  x = 0;
  register char ch = gc();
  for (; !(ch >= '0' && ch <= '9'); ch = gc()) {
    if (ch == '-') {
      sign = 1;
    }
  }
  for (; (ch >= '0' && ch <= '9'); ch = gc()) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
  }
  if (ch == '.') {
    for (ch = gc(); (ch >= '0' && ch <= '9'); ch = gc()) {
      tmp /= 10.0;
      x += tmp * (ch - 48);
    }
  }
  if (sign) {
    x = -x;
  }
}
inline void read(char *s) {
  register char ch = gc();
  for (; blank(ch); ch = gc())
    ;
  for (; !blank(ch); ch = gc()) {
    *s++ = ch;
  }
  *s = 0;
}
inline void read(char &c) {
  for (c = gc(); blank(c); c = gc())
    ;
}
inline void push(const char &c) {
  char pbuf[MAXSIZE];
  char *pp = pbuf;
  if (pp - pbuf == MAXSIZE) {
    fwrite(pbuf, 1, MAXSIZE, stdout);
    pp = pbuf;
  }
  *pp++ = c;
}
template <class T>
inline void write(T x) {
  static T sta[35];
  T top = 0;
  do {
    sta[top++] = x % 10;
    x /= 10;
  } while (x);
  while (top) {
    putchar(sta[--top] + '0');
  }
  return;
  while (top) {
    push(sta[--top] + '0');
  }
}
template <class T>
inline void write(T x, char lastChar) {
  write(x);
  putchar(lastChar);
}
}  // namespace hyy
using namespace hyy;
using namespace std;
using namespace std;
int n;
long long a[500005], dp[500005], sum[500005 * 4];
void Add(int i, int l, int r, int ed, long long w) {
  if (l == r) {
    sum[i] = w;
    return;
  }
  int mid = l + r >> 1;
  if (mid >= ed) {
    Add(i << 1, l, mid, ed, w);
  } else {
    Add(i << 1 | 1, mid + 1, r, ed, w);
  }
  sum[i] = (sum[i << 1] + sum[i << 1 | 1]) % 998244353;
}
long long Sum(int i, int l, int r, int el, int er) {
  if (l >= el && r <= er) {
    return sum[i];
  }
  int mid = l + r >> 1;
  long long ans = 0;
  if (mid >= el) {
    ans += Sum(i << 1, l, mid, el, er);
  }
  if (mid < er) {
    ans += Sum(i << 1 | 1, mid + 1, r, el, er);
  }
  return ans;
}
int stk[500005], top;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  Add(1, 1, n, 1, dp[0] = 1);
  long long S = 0;
  for (int i = 1; i <= n; i++) {
    while (top && a[stk[top]] >= a[i]) {
      S = (S - 1ll * a[stk[top]] * Sum(1, 1, n, stk[top - 1] + 1, stk[top]) %
                   998244353) %
          998244353;
      --top;
    }
    stk[++top] = i;
    S = (S +
         1ll * a[i] * Sum(1, 1, n, stk[top - 1] + 1, stk[top]) % 998244353) %
        998244353;
    dp[i] = 998244353 - S;
    if (i != n) {
      Add(1, 1, n, i + 1, dp[i]);
    }
  }
  if (n & 1) {
    cout << ((998244353 - dp[n]) % 998244353 + 998244353) % 998244353;
  } else {
    cout << (dp[n] % 998244353 + 998244353) % 998244353;
  }
  return 0;
}
