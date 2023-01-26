#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long read() {
  long long s = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * f;
}
long long x[1010], y[1010];
long long vis[1010];
long long f1(long long i, long long j) {
  if (x[i] < x[j] && x[j] < y[i]) return 1;
  return 0;
}
long long f2(long long i, long long j) {
  if (!(x[i] < y[j] && y[j] < y[i])) return 1;
  return 0;
}
signed main() {
  long long T = read();
  while (T--) {
    n = read();
    k = read();
    long long nw = n * 2;
    for (long long i = 1, iend = nw; i <= iend; ++i) vis[i] = 0;
    for (long long i = 1, iend = k; i <= iend; ++i) {
      x[i] = read(), y[i] = read();
      vis[x[i]] = vis[y[i]] = 1;
    }
    long long s = k;
    vector<long long> v;
    for (long long i = 1, iend = nw; i <= iend; ++i)
      if (!vis[i]) v.push_back(i);
    long long siz = v.size();
    long long ps = siz / 2;
    for (long long i = 0, iend = siz / 2 - 1; i <= iend; ++i) {
      x[++s] = v[i];
      y[s] = v[ps++];
    }
    for (long long i = 1, iend = n; i <= iend; ++i)
      if (x[i] > y[i]) swap(x[i], y[i]);
    long long ans = 0;
    for (long long i = 1, iend = n; i <= iend; ++i) {
      for (long long j = 1, jend = n; j <= jend; ++j) {
        if (i == j) continue;
        if (f1(i, j) && f2(i, j)) ++ans;
      }
    }
    cout << ans << "\n";
  }
}
