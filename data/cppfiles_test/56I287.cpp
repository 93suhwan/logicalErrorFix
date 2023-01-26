#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return f == 1 ? x : -x;
}
bool quest(long long x, long long y) {
  printf("%lld %lld\n", x, y);
  string z;
  cin >> z;
  if (z == "Done")
    return 1;
  else
    return 0;
}
void solve() {
  for (register long long i = 1; i <= 4; ++i) {
    for (register long long j = 1; j <= 8; ++j)
      if (quest(2 * i - 1, j)) return;
    for (register long long j = 8; j >= 1; --j)
      if (quest(2 * i, j)) return;
  }
}
signed main() {
  long long T = read();
  while (T--) solve();
  return 0;
}
