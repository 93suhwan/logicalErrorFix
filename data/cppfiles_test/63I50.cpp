#include <bits/stdc++.h>
using namespace std;
namespace Fread {
const int SIZE = 1 << 16;
char buf[SIZE], *S, *T;
inline char getchar() {
  if (S == T) {
    T = (S = buf) + fread(buf, 1, SIZE, stdin);
    if (S == T) return '\n';
  }
  return *S++;
}
}  // namespace Fread
namespace Fwrite {
const int SIZE = 1 << 16;
char buf[SIZE], *S = buf, *T = buf + SIZE;
inline void flush() {
  fwrite(buf, 1, S - buf, stdout);
  S = buf;
}
inline void putchar(char c) {
  *S++ = c;
  if (S == T) flush();
}
struct NTR {
  ~NTR() { flush(); }
} ztr;
}  // namespace Fwrite
namespace Fastio {
struct Reader {
  template <typename T>
  Reader& operator>>(T& x) {
    char c = Fread::getchar();
    short f = 1;
    while (c < '0' || c > '9') {
      if (c == '-') f *= -1;
      c = Fread::getchar();
    }
    x = 0;
    while (c >= '0' && c <= '9') {
      x = (x << 1) + (x << 3) + (c ^ 48);
      c = Fread::getchar();
    }
    x *= f;
    return *this;
  }
  Reader& operator>>(double& x) {
    char c = Fread::getchar();
    short f = 1, s = 0;
    x = 0;
    double t = 0;
    while ((c < '0' || c > '9') && c != '-' && c != '.') {
      if (c == '-') f *= -1;
      c = Fread::getchar();
    }
    while (c >= '0' && c <= '9' && c != '.')
      x = x * 10 + (c ^ 48), c = Fread::getchar();
    if (c == '.')
      c = Fread::getchar();
    else
      return x *= f, *this;
    while (c >= '0' && c <= '9')
      t = t * 10 + (c ^ 48), s++, c = Fread::getchar();
    while (s--) t /= 10.0;
    x = (x + t) * f;
    return *this;
  }
  Reader& operator>>(long double& x) {
    char c = Fread::getchar();
    short f = 1, s = 0;
    x = 0;
    long double t = 0;
    while ((c < '0' || c > '9') && c != '-' && c != '.') {
      if (c == '-') f *= -1;
      c = Fread::getchar();
    }
    while (c >= '0' && c <= '9' && c != '.')
      x = x * 10 + (c ^ 48), c = Fread::getchar();
    if (c == '.')
      c = Fread::getchar();
    else
      return x *= f, *this;
    while (c >= '0' && c <= '9')
      t = t * 10 + (c ^ 48), s++, c = Fread::getchar();
    while (s--) t /= 10.0;
    x = (x + t) * f;
    return *this;
  }
  Reader& operator>>(__float128& x) {
    char c = Fread::getchar();
    short f = 1, s = 0;
    x = 0;
    __float128 t = 0;
    while ((c < '0' || c > '9') && c != '-' && c != '.') {
      if (c == '-') f *= -1;
      c = Fread::getchar();
    }
    while (c >= '0' && c <= '9' && c != '.')
      x = x * 10 + (c ^ 48), c = Fread::getchar();
    if (c == '.')
      c = Fread::getchar();
    else
      return x *= f, *this;
    while (c >= '0' && c <= '9')
      t = t * 10 + (c ^ 48), s++, c = Fread::getchar();
    while (s--) t /= 10.0;
    x = (x + t) * f;
    return *this;
  }
  Reader& operator>>(char& c) {
    c = Fread::getchar();
    while (c == '\n' || c == ' ' || c == '\r') c = Fread::getchar();
    return *this;
  }
  Reader& operator>>(char* str) {
    int len = 0;
    char c = Fread::getchar();
    while (c == '\n' || c == ' ' || c == '\r') c = Fread::getchar();
    while (c != '\n' && c != ' ' && c != '\r')
      str[len++] = c, c = Fread::getchar();
    str[len] = '\0';
    return *this;
  }
  Reader& operator>>(string& str) {
    int len = 0;
    char c = Fread::getchar();
    while (c == '\n' || c == ' ' || c == '\r') c = Fread::getchar();
    while (c != '\n' && c != ' ' && c != '\r')
      str.push_back(c), c = Fread::getchar();
    return *this;
  }
  Reader() {}
} cin;
const char endl = '\n';
struct Writer {
  const int Setprecision = 6;
  template <typename T>
  Writer& operator<<(T x) {
    if (x == 0) return Fwrite::putchar('0'), *this;
    if (x < 0) Fwrite::putchar('-'), x = -x;
    static int sta[45];
    int top = 0;
    while (x) sta[++top] = x % 10, x /= 10;
    while (top) Fwrite::putchar(sta[top] + '0'), --top;
    return *this;
  }
  Writer& operator<<(double x) {
    if (x < 0) Fwrite::putchar('-'), x = -x;
    int _ = x;
    x -= (double)_;
    static int sta[45];
    int top = 0;
    while (_) sta[++top] = _ % 10, _ /= 10;
    if (!top) Fwrite::putchar('0');
    while (top) Fwrite::putchar(sta[top] + '0'), --top;
    Fwrite::putchar('.');
    for (int i = 0; i < Setprecision; i++) x *= 10;
    _ = x;
    while (_) sta[++top] = _ % 10, _ /= 10;
    for (int i = 0; i < Setprecision - top; i++) Fwrite::putchar('0');
    while (top) Fwrite::putchar(sta[top] + '0'), --top;
    return *this;
  }
  Writer& operator<<(long double x) {
    if (x < 0) Fwrite::putchar('-'), x = -x;
    int _ = x;
    x -= (long double)_;
    static int sta[45];
    int top = 0;
    while (_) sta[++top] = _ % 10, _ /= 10;
    if (!top) Fwrite::putchar('0');
    while (top) Fwrite::putchar(sta[top] + '0'), --top;
    Fwrite::putchar('.');
    for (int i = 0; i < Setprecision; i++) x *= 10;
    _ = x;
    while (_) sta[++top] = _ % 10, _ /= 10;
    for (int i = 0; i < Setprecision - top; i++) Fwrite::putchar('0');
    while (top) Fwrite::putchar(sta[top] + '0'), --top;
    return *this;
  }
  Writer& operator<<(__float128 x) {
    if (x < 0) Fwrite::putchar('-'), x = -x;
    int _ = x;
    x -= (__float128)_;
    static int sta[45];
    int top = 0;
    while (_) sta[++top] = _ % 10, _ /= 10;
    if (!top) Fwrite::putchar('0');
    while (top) Fwrite::putchar(sta[top] + '0'), --top;
    Fwrite::putchar('.');
    for (int i = 0; i < Setprecision; i++) x *= 10;
    _ = x;
    while (_) sta[++top] = _ % 10, _ /= 10;
    for (int i = 0; i < Setprecision - top; i++) Fwrite::putchar('0');
    while (top) Fwrite::putchar(sta[top] + '0'), --top;
    return *this;
  }
  Writer& operator<<(char c) {
    Fwrite::putchar(c);
    return *this;
  }
  Writer& operator<<(char* str) {
    int cur = 0;
    while (str[cur]) Fwrite::putchar(str[cur++]);
    return *this;
  }
  Writer& operator<<(const char* str) {
    int cur = 0;
    while (str[cur]) Fwrite::putchar(str[cur++]);
    return *this;
  }
  Writer& operator<<(string str) {
    int st = 0, ed = str.size();
    while (st < ed) Fwrite::putchar(str[st++]);
    return *this;
  }
  Writer() {}
} cout;
}  // namespace Fastio
int n, len;
char s[400010];
int pre[20], mpre[20];
int g[20][400010 * 2];
int f[1 << 20][2], sm[1 << 20];
signed main() {
  Fastio ::cin >> n;
  for (int i = (0); i <= (n - 1); i++) {
    Fastio ::cin >> s + 1;
    len = strlen(s + 1);
    mpre[i] = 1145141919;
    for (int j = (1); j <= (len); j++) {
      pre[i] += s[j] == '(' ? 1 : -1;
      mpre[i] = min(mpre[i], pre[i]);
      if (pre[i] == mpre[i]) g[i][400000 + pre[i]]++;
    }
  }
  for (int i = (1); i <= ((1 << n) - 1); i++)
    for (int j = (0); j <= (n - 1); j++)
      if (i >> j & 1) sm[i] += pre[j];
  int ans = 0;
  for (int S = (0); S <= ((1 << n) - 1); S++)
    for (int i = (0); i <= (n - 1); i++)
      if (!(S >> i & 1)) {
        int T = S | (1 << i);
        if (sm[S] + mpre[i] >= 0)
          f[T][1] = max(f[T][1], f[S][1] + g[i][400000 - sm[S]]);
        else
          f[T][0] = max(f[T][0], f[S][1] + g[i][400000 - sm[S]]);
      }
  for (int i = (0); i <= ((1 << n) - 1); i++)
    ans = max(ans, max(f[i][0], f[i][1]));
  Fastio ::cout << ans;
}
