#include <bits/stdc++.h>
using namespace std;
const int sz = 5e5 + 10;
const int inf = 0x3f3f3f3f;
inline int read() {
  int f = 1, x = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
  return f * x;
}
void print(int *z, int n) {
  for (int i = 1; i <= n; i++) printf("%d  ", z[i]);
  puts("");
}
int z[sz];
int solve() {
  int n = read();
  bool one = 0, two = 0, trone = 0, three;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    z[i] = read();
    if (z[i] == 1)
      trone = 1;
    else if (z[i] == 3)
      three = 1;
    if (z[i] % 3 == 1)
      one = 1;
    else if (z[i] % 3 == 2)
      two = 1;
    mx = max(mx, z[i]);
  }
  if (mx % 3 == 0) {
    if (one || two) return mx / 3 + 1;
    return mx / 3;
  } else if (mx % 3 == 2) {
    if (one)
      return mx / 3 + 2;
    else
      return mx / 3 + 1;
  } else {
    if (trone || three && mx == 4) return mx / 3 + 2;
    return mx / 3 + 1;
  }
}
signed main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }
}
