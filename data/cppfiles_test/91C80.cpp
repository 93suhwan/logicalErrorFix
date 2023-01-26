#include <bits/stdc++.h>
using namespace std;
const long long maxn = 200000 + 10;
const long long mod = 998244353;
long long f[2][maxn];
long long a[maxn];
int main() {
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
    f[n & 1][a[n]] = 1;
    vector<long long> fr, nt;
    fr.push_back(a[n]);
    long long ans = 0, cnt = 0;
    for (long long i = n - 1; i >= 1; i--) {
      f[i & 1][a[i]] = 1;
      nt.push_back(a[i]);
      for (long long j = 0; j < fr.size(); j++) {
        long long v = f[(i + 1) & 1][fr[j]];
        f[(i + 1) & 1][fr[j]] = 0;
        long long t = a[i] / ((a[i] + fr[j] - 1) / fr[j]);
        if (!f[i & 1][t]) nt.push_back(t);
        f[i & 1][t] += v;
        ans += i * v * ((a[i] + fr[j] - 1) / fr[j] - 1);
        cnt++;
      }
      fr = nt;
      nt.clear();
      ans %= mod;
    }
    for (long long j = 0; j < fr.size(); j++) {
      f[1][fr[j]] = 0;
    }
    printf("%lld\n", ans % 998244353);
  }
  return 0;
}
