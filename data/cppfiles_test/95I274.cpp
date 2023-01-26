#include <bits/stdc++.h>
using namespace std;
namespace Fread {
const int SIZE = 1 << 26;
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
const int SIZE = 1 << 26;
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
    char c = Fread ::getchar();
    T f = 1;
    while (c < '0' || c > '9') {
      if (c == '-') f = -1;
      c = Fread ::getchar();
    }
    x = 0;
    while (c >= '0' && c <= '9') {
      x = (x * 10 + (c - '0'));
      c = Fread ::getchar();
    }
    x *= f;
    return *this;
  }
  Reader& operator>>(char& c) {
    c = Fread ::getchar();
    while (c == '\n' || c == ' ') c = Fread ::getchar();
    return *this;
  }
  Reader& operator>>(char* str) {
    int len = 0;
    char c = Fread ::getchar();
    while (c == '\n' || c == ' ') c = Fread ::getchar();
    while (c != '\n' && c != ' ') {
      str[len++] = c;
      c = Fread ::getchar();
    }
    str[len] = '\0';
    return *this;
  }
  Reader() {}
} cin;
const char endl = '\n';
struct Writer {
  template <typename T>
  Writer& operator<<(T x) {
    if (x == 0) {
      Fwrite ::putchar('0');
      return *this;
    }
    if (x < 0) {
      Fwrite ::putchar('-');
      x = -x;
    }
    static int sta[45];
    int top = 0;
    while (x) {
      sta[++top] = x % 10;
      x /= 10;
    }
    while (top) {
      Fwrite ::putchar(sta[top] + '0');
      --top;
    }
    return *this;
  }
  Writer& operator<<(char c) {
    Fwrite ::putchar(c);
    return *this;
  }
  Writer& operator<<(char* str) {
    int cur = 0;
    while (str[cur]) Fwrite ::putchar(str[cur++]);
    return *this;
  }
  Writer& operator<<(const char* str) {
    int cur = 0;
    while (str[cur]) Fwrite ::putchar(str[cur++]);
    return *this;
  }
  Writer() {}
} cout;
}  // namespace Fastio
long long n, s, T;
signed main() {
  for (Fastio ::cin >> T; T; T--) {
    Fastio ::cin >> s >> n;
    for (long long i = 1; i < n; i++) Fastio ::cout << 1 << ' ';
    s -= (n - 1);
    Fastio ::cout << s << Fastio ::endl;
  }
}
