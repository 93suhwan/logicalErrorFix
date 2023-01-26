#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
inline int readint() {
  int ans = 0;
  bool sign = true;
  char c;
  while (!isdigit(c = getchar()))
    if (c == '-') sign = false;
  while (isdigit(c)) {
    ans = (ans << 3) + (ans << 1) + (c ^ 48);
    c = getchar();
  }
  return ans * (sign ? 1 : -1);
}
inline void readint(int &x) { x = readint(); }
template <typename... Ts>
inline void readint(int &x, Ts &...y) {
  x = readint();
  readint(y...);
}
const int INF = 0x3f3f3f3f;
const long long LLINF = ((long long)INF << 32) | INF;
const int mod = 1e9 + 7;
int main() {
  ;
  int ___;
  cin >> ___;
  for (int tc = 1; tc <= ___; ++tc) {
    int s, n, p;
    readint(s, n);
    while (n--) {
      if (n == 0) {
        printf("%d\n", s);
      } else {
        printf("%d ", p = pow(10, (int)log10(s - n)));
      }
      s -= p;
    }
  }
  return 0;
}
