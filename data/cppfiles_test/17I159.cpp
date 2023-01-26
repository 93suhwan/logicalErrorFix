#include <bits/stdc++.h>
using namespace std;
inline int r() {
  int s = 0, k = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') k = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    s = s * 10 + c - '0';
    c = getchar();
  }
  return s * k;
}
int T, n, c[1000005], a[1000005], ans, cnt, t[1000005];
int lowbit(int x) { return x & (-x); }
void add(int x) {
  for (; x <= n; x += lowbit(x)) c[x]++;
}
int sum(int x) {
  int s = 0;
  for (; x; x -= lowbit(x)) s += c[x];
  return s;
}
int main() {
  T = r();
  while (T--) {
    n = r();
    ans = 0;
    for (int i = 1; i <= n; i++) {
      a[i] = r();
      t[i] = a[i];
      c[i] = 0;
    }
    sort(t + 1, t + n + 1);
    cnt = unique(t + 1, t + n + 1) - t - 1;
    for (int i = 1; i <= n; i++) a[i] = lower_bound(t + 1, t + n + 1, a[i]) - t;
    for (int i = 1; i <= n; i++) {
      int sum1 = sum(a[i] - 1);
      int sum2 = sum(n) - sum(a[i]);
      ans += min(sum1, sum2);
      add(a[i]);
    }
    cout << ans << endl;
  }
}
