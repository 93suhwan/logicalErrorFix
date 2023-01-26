#include <bits/stdc++.h>
using namespace std;
const int N = 4e4 + 5;
long long T, n, b[N], c[N];
long long l, r, mid, mm;
long long check(long long mid) {
  long long cnt = 0;
  for (int i = 1; i <= n; i++) cnt += (mid - c[i]) / (n) * (n - i + 1);
  return b[n] - cnt;
}
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 2; i <= n; i++) c[i] = b[i] - b[i - 1];
    c[1] = b[1] - b[n];
    bool flag = false;
    for (int i = 2; i <= n; i++)
      if ((c[i] % n + n) % n != (c[i - 1] % n + n) % n) flag = true;
    if (flag) {
      puts("NO");
      continue;
    }
    l = 0, r = 1e9 + 5;
    while (l < r - 1) {
      mm = (l + r) >> 1;
      mid = c[1] + n * mm;
      long long t = check(mid);
      if (t == 0) {
        flag = true;
        break;
      } else if (t < 0)
        r = mm;
      else
        l = mm;
    }
    if (flag) {
      for (int i = 1; i <= n; i++)
        if (mid <= c[i]) flag = false;
      if (!flag) {
        puts("NO");
        continue;
      }
      puts("YES");
      for (int i = 1; i <= n; i++) cout << (mid - c[i]) / (n) << ' ';
      puts("");
    } else
      puts("NO");
  }
  return 0;
}
