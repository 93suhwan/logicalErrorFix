#include <bits/stdc++.h>
using namespace std;
namespace IO {
const int INF = 0x3f3f3f3f;
const double esp = 1e-7;
template <class I>
inline void read(I &x) {
  x = 0;
  I f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    f *= (c != '-') ? 1 : (-1);
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  x = x * f;
  return void();
}
template <class I>
inline void write(I x) {
  printf("%d", x);
  return void();
}
}  // namespace IO
using namespace IO;
int T, n;
char s[1000010];
int main() {
  read(T);
  while (T--) {
    read(n);
    ::cin >> (s + 1);
    bool flag = false;
    for (int i = 1; i < n && !flag; i++) {
      if (s[i] != s[i + 1]) {
        write(i), putchar(' '), write(i + 1), putchar('\n');
        flag = true;
      }
    }
    if (flag == false) {
      write(-1), putchar(' '), write(-1), putchar('\n');
    }
  }
  return 0;
}
