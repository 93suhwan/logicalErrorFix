#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = ' ';
  while (!isdigit(ch)) {
    ch = getchar();
    if (ch == '-') f = -1;
  }
  while (isdigit(ch)) x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x * f;
}
long long n, a[400005], c[400005], ans;
void jia(long long i, long long x) {
  while (i <= n * 2 + 1) {
    c[i] = max(c[i], x);
    i += -i & i;
  }
}
long long he(long long x) {
  long long s = 0;
  while (x) {
    s = max(s, c[x]);
    x -= -x & x;
  }
  return s;
}
int main() {
  cin >> n;
  jia(n, 1);
  for (int i = 1; i <= n; i++) {
    int x = read();
    a[i] = he(x - i + n + 1);
    jia(x - i + n + 1, a[i] + 1);
    ans = max(ans, a[i]);
  }
  cout << ans;
}
