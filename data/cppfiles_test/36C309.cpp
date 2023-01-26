#include <bits/stdc++.h>
const long long mod = 2147483647LL;
long long read() {
  long long r = 0, flag = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') {
      flag = -1LL;
    }
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    r = 10LL * r + (long long)c - '0';
    c = getchar();
  }
  return flag * r;
}
int t, n, a[105];
std::vector<int> p;
bool isp[20005];
signed main() {
  for (int i = 2; i <= 20000; ++i) {
    if (!isp[i]) p.push_back(i);
    for (int j = 0; j < p.size(); ++j) {
      if (i * p[j] > 20000) break;
      isp[i * p[j]] = 1;
      if (i % p[j] == 0) break;
    }
  }
  t = read();
  while (t--) {
    n = read();
    int sum = 0;
    for (int i = 1; i <= n; ++i) sum += (a[i] = read());
    if (isp[sum]) {
      printf("%d\n", n);
      for (int i = 1; i <= n; ++i) printf("%d ", i);
    } else {
      printf("%d\n", n - 1);
      for (int i = 1; i <= n; ++i)
        if (isp[sum - a[i]]) {
          for (int j = 1; j <= n; ++j)
            if (i != j) printf("%d ", j);
          break;
        }
    }
    puts("");
  }
  return 0;
}
