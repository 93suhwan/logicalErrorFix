#include <bits/stdc++.h>
using namespace std;
namespace LYYY {
inline int rd() {
  int s = 0;
  char c = getchar();
  int f = 1;
  while (c < 48 || c > 57) {
    if (c == 45) f = -1;
    c = getchar();
  }
  while (c >= 48 && c <= 57) s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
  return s * f;
}
long long rdl() {
  long long s = 0;
  char c = getchar();
  int f = 1;
  while (c < 48 || c > 57) {
    if (c == 45) f = -1;
    c = getchar();
  }
  while (c >= 48 && c <= 57) s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
  return s * f;
}
void wt(int x) {
  if (x >= 10) wt(x / 10);
  putchar(x % 10 + 48);
}
void WT(int x) {
  if (x < 0) x = -x, putchar(45);
  wt(x);
}
void wtl(long long x) {
  if (x >= 10) wtl(x / 10);
  putchar(x % 10 + 48);
}
void WTL(long long x) {
  if (x < 0) x = -x, putchar(45);
  wtl(x);
}
}  // namespace LYYY
using namespace LYYY;
int main() {
  int T = rd();
  while (T--) {
    int N = rd();
    long long ans = 0, tmp = rd();
    for (int i = 2; i <= N; ++i) {
      long long a = rd();
      ans = max(ans, a * tmp);
      tmp = a;
    }
    wtl(ans), puts("");
  }
  return 0;
}
