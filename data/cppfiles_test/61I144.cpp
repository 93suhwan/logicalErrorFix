#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long ret = 0;
  char c = getchar();
  while (c > '9' || c < '0') c = getchar();
  while (c >= '0' && c <= '9')
    ret = (ret << 3) + (ret << 1) + (c ^ 48), c = getchar();
  return ret;
}
long long T;
const long long maxn = 2e5 + 5;
long long n;
long long cntb[maxn];
long long ans;
long long pb[maxn];
long long sump;
long long sumn;
vector<long long> v[maxn];
signed main() {
  T = read();
  while (T--) {
    n = read();
    for (long long i = 1; i <= n; i++) v[i].clear(), cntb[i] = 0, pb[i] = 0;
    sump = sumn = 0;
    ans = 0;
    for (long long i = 1; i <= n; i++) {
      long long a = read(), b = read();
      v[a].push_back(b);
    }
    for (long long i = 1; i <= n; i++) {
      for (long long j : v[i]) ans += sump - pb[j];
      for (long long j : v[i]) {
        sump += sumn - cntb[j];
        pb[j] += sumn - cntb[j];
      }
      for (long long j : v[i]) sumn++, cntb[j]++;
    }
    ans = -ans;
    sumn = 0;
    sump = 0;
    for (long long i = 1; i <= n; i++) {
      ans += sump * v[i].size();
      sump += v[i].size() * sumn;
      sumn += v[i].size();
    }
    sumn = 0;
    sump = 0;
    for (long long i = 1; i <= n; i++) {
      ans += sump * cntb[i];
      sump += cntb[i] * sumn;
      sumn += cntb[i];
    }
    printf("%lld\n", ans);
  }
}
