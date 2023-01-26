#include <bits/stdc++.h>
using namespace std;
const int LEN_IN = 233;
inline bool Isdigit(char &c) {
  if (c >= '0' && c <= '9') return true;
  return false;
}
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; !Isdigit(c); c = getchar()) {
    if (c == '-') f = -1;
  }
  for (; Isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
  return x * f;
}
inline bool Ischar(char &c) {
  if (c >= 'a' && c <= 'z') return true;
  return false;
}
inline int Cread(char ch[]) {
  int s = 0;
  char c = getchar();
  for (; !Ischar(c); c = getchar())
    ;
  for (; Ischar(c); c = getchar()) ch[++s] = c;
  return s;
}
int Out_put[LEN_IN], Len_;
inline void write(int &x) {
  if (x < 0) putchar('-'), x = (~x) + 1;
  Out_put[++Len_] = x % 10;
  for (int tmp_ = x / 10; tmp_; tmp_ /= 10) Out_put[++Len_] = tmp_ % 10;
  for (; Len_; --Len_) putchar(Out_put[Len_] + '0');
  return;
}
int T, n, s, k;
int main() {
  T = read();
  for (; T; --T) {
    s = read(), n = read(), k = read();
    if (n > s) {
      puts("NO");
    } else {
      if (s < k) {
        puts("NO");
        continue;
      }
      if (n >= k)
        puts("YES");
      else
        puts("NO");
    }
  }
  return 0;
}
