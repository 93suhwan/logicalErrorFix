#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') {
      f = -1;
    }
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch & 15);
    ch = getchar();
  }
  return x * f;
}
int solve() {
  int n;
  n = read();
  std::vector<int> a(n + 1);
  int cnt1 = 0, cnt0 = 0;
  for (int i = 1; i <= n; i++)
    a[i] = read(), cnt1 += (a[i] & 1), cnt0 += (!(a[i] & 1));
  if (abs(cnt1 - cnt0) > 1) {
    return -1;
  } else {
    for (int i = 1; i <= n; i++) a[i] = (a[i] & 1);
    long long ret, j = 1, o = 2, J, O;
    J = O = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i]) {
        J += abs(i - j);
        O += abs(i - o);
        j += 2, o += 2;
      }
    }
    if (n % 2 == 0)
      return min(J, O);
    else {
      return cnt1 < cnt0 ? O : J;
    }
  }
}
int main() {
  for (int t = read(); t; t--) {
    printf("%d\n", solve());
  }
  return 0;
}
