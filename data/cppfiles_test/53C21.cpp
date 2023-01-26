#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long res = 0, flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    res = (res << 3) + (res << 1) + (ch ^ 48);
    ch = getchar();
  }
  return res * flag;
}
const long long maxn = 1e6 + 5;
const long long mod = 1e9 + 7;
const double pi = acos(-1);
const double eps = 1e-8;
long long n, k, a[maxn];
vector<long long> v;
signed main() {
  long long t = read();
  while (t--) {
    n = read(), k = read();
    v.clear();
    for (long long i = 1; i <= n; i++) v.push_back(a[i] = read());
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (long long i = 1; i <= n; i++)
      a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    long long cnt = 0;
    a[0] = -1;
    for (long long i = 1; i <= n; i++) {
      if (a[i] != a[i - 1] + 1) cnt++;
    }
    puts(cnt <= k ? "Yes" : "No");
  }
  return 0;
}
