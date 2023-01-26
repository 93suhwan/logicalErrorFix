#include <bits/stdc++.h>
using namespace std;
const int LEN_IN = 233;
inline bool Isdigit(char &c) {
  if (c >= '0' && c <= '9') return true;
  return false;
}
inline long long read() {
  long long x = 0, f = 1;
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
inline long long Cread(char ch[]) {
  long long s = 0;
  char c = getchar();
  for (; !Ischar(c); c = getchar())
    ;
  for (; Ischar(c); c = getchar()) ch[++s] = c;
  return s;
}
long long Out_put[LEN_IN], Len_;
inline void write(long long &x) {
  if (x < 0) putchar('-'), x = (~x) + 1;
  Out_put[++Len_] = x % 10;
  for (long long tmp_ = x / 10; tmp_; tmp_ /= 10) Out_put[++Len_] = tmp_ % 10;
  for (; Len_; --Len_) putchar(Out_put[Len_] + '0');
  return;
}
long long T, n, s, k;
signed main() {
  T = read();
  for (; T; --T) {
    s = read(), n = read(), k = read();
    if (s < n)
      puts("NO");
    else if (n == 1 && s == k)
      puts("YES");
    else {
      long long blck = n / k + (n % k != 0), seat = n / k;
      long long X = (seat - 1) * (k << 1) + 1;
      long long ans = X + (n - ((seat - 1) * k + 1));
      if (s < ans)
        puts("YES");
      else
        puts("NO");
    }
  }
}
