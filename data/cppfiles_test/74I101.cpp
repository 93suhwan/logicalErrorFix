#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long sum = 0, nega = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
  return sum * nega;
}
const long long N = 1509, M = 1509;
long long n, a[N], ans[N];
vector<long long> v0, v1;
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + n + 1);
  for (long long i = 1; i <= n - 1; i++)
    if (a[i] == a[i + 1]) {
      puts("YES");
      putchar('0');
      for (long long j = 1; j <= i; j++) printf(" %d", a[j]);
      for (long long j = i + 2; j <= n; j++) printf(" %d", a[j]);
      return 0;
    }
  for (long long i = 1; i <= n; i++)
    if (a[i] & 1)
      v1.push_back(a[i]);
    else
      v0.push_back(a[i]);
  if (v0.size() >= 3) {
    long long sum = v0[0] + v0[1] + v0[2];
    sum /= 2;
    for (long long i = 1; i <= 3; i++) ans[i] = sum - v0[i - 1];
    for (long long i = 4; i <= v0.size(); i++) ans[i] = v0[i - 1] - ans[1];
    for (long long i = 1; i <= v1.size(); i++)
      ans[i + v0.size()] = v1[i - 1] - ans[1];
    puts("YES");
    for (long long i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
  }
  if (v0.size() >= 1 && v1.size() >= 2) {
    long long sum = v0[0] + v1[0] + v1[1], cnt = 0;
    sum /= 2;
    ans[++cnt] = sum - v0[0];
    ans[++cnt] = sum - v1[0];
    ans[++cnt] = sum - v1[1];
    for (long long i = 1; i < v0.size(); i++) ans[++cnt] = v0[i] - ans[1];
    for (long long i = 2; i < v1.size(); i++) ans[++cnt] = v1[i] - ans[1];
    puts("YES");
    for (long long i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
  }
  puts("NO");
  return 0;
}
