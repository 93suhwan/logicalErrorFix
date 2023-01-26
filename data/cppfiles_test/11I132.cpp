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
const int N = 2e5;
long long n, f[400005], c[400005], ans;
void jia(long long i, long long x) {
  while (i <= 400000) {
    c[i] = max(c[i], x);
    i += i & -i;
  }
}
long long he(long long x) {
  long long s = 0;
  while (x) {
    s = max(s, c[x]);
    x -= x & -x;
  }
  return s;
}
pair<long long, long long> a[400005];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) a[i] = {read(), i};
  sort(a + 1, a + n + 1);
  jia(0 + N, 1);
  for (int i = 1; i <= n; i++) {
    f[i] = he(a[i].second - a[i].first + N);
    jia(a[i].second - a[i].first + N, f[i] + 1);
    ans = max(ans, f[i]);
  }
  cout << ans;
}
