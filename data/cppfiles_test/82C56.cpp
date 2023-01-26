#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void fileio(const string &s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
const long long INF = 4e18;
inline long long read() {
  long long x = 0;
  bool flag = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') flag = 0;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return (flag ? x : ~(x - 1));
}
long long n, q, k, a[300001], c[300001], f[300002][20], p[300001][20];
deque<long long> que;
signed main() {
  n = read();
  q = read();
  k = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = n; i; i--) {
    while (que.size() && a[i] <= a[que.back()]) que.pop_back();
    que.push_back(i);
    while (i + k < que.front()) que.pop_front();
    c[i] = a[que.front()];
  }
  f[n + 1][0] = n + 1;
  for (long long i = n; i; i--) {
    f[i][0] = i + k;
    f[i][0] = min(f[i][0], n + 1);
    while (c[i] < c[f[i][0]]) f[i][0] = f[f[i][0]][0];
    p[i][0] = (f[i][0] - i + k - 1) / k * c[i];
  }
  for (long long i = 1; i <= 19; i++)
    for (long long l = 1; l <= n + 1; l++) {
      f[l][i] = f[f[l][i - 1]][i - 1];
      p[l][i] = p[l][i - 1] + p[f[l][i - 1]][i - 1];
    }
  while (q--) {
    long long l = read(), r = read(), ans = a[l];
    for (long long i = 19; i >= 0; i--)
      if (f[l][i] <= r) {
        ans += p[l][i];
        l = f[l][i];
      }
    ans += (r - l) / k * c[l];
    cout << ans << endl;
  }
  return 0;
}
