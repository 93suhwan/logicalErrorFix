#include <bits/stdc++.h>
using namespace std;
clock_t startTime, endTime;
const long long INF_ll = 1e18;
const int INF_int = 0x3f3f3f3f;
void read(){};
template <typename _Tp, typename... _Tps>
void read(_Tp& x, _Tps&... Ar) {
  x = 0;
  char c = getchar();
  bool flag = 0;
  while (c < '0' || c > '9') flag |= (c == '-'), c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  if (flag) x = -x;
  read(Ar...);
}
template <typename T>
inline void write(T x) {
  if (x < 0) {
    x = ~(x - 1);
    putchar('-');
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
void rd_test() {}
void Time_test() {}
int main() {}
