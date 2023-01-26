#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T& t) {
  T sum = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) sum = sum * 10 + c - '0', c = getchar();
  t = sum * f;
}
template <typename T, typename... Args>
inline void read(T& t, Args&... args) {
  read(t);
  read(args...);
}
template <typename T>
inline void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
inline void write(const char ch, T x) {
  write(x);
  putchar(ch);
}
template <typename T, typename... Args>
inline void write(const char ch, T x, Args... args) {
  write(ch, x);
  write(ch, args...);
}
inline void read(string& x) {
  x = "";
  char ch = getchar();
  while (ch == ' ' || ch == '\n' || ch == '\r') ch = getchar();
  while (ch != ' ' && ch != '\n' && ch != '\r') x += ch, ch = getchar();
}
inline void write(string x) {
  for (int i = 0; x[i] != '\0'; i++) putchar(x[i]);
}
long long num[200005];
signed main(void) {
  long long t;
  read(t);
  while (t--) {
    long long n, k;
    read(n, k);
    for (long long i = 0; i < n; i++) {
      read(num[i]);
    }
    sort(num, num + n);
    long long pos1 = upper_bound(num, num + n, 0) - num;
    long long pos2 = lower_bound(num, num + n, 0) - num - 1;
    long long ans = 0;
    long long maxx = 0;
    if (num[n - 1] > 0) {
      long long now = n - 1;
      while (now - (k - 1) >= pos1) {
        ans += num[now];
        now -= k;
      }
      if (now >= pos1) ans += (num[now]);
    }
    if (num[0] < 0) {
      long long now = 0;
      while (now + k - 1 <= pos2) {
        ans += -num[now];
        now += k;
      }
      if (now <= pos2) ans += (-num[now]);
    }
    maxx = max(num[0] < 0 ? -num[0] : num[0],
               num[n - 1] < 0 ? (-num[n - 1]) : num[n - 1]);
    ans = ans * 2 - maxx;
    write('\n', ans);
  }
  return 0;
}
