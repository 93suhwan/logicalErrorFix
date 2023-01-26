#include <bits/stdc++.h>
using namespace std;
const long long maxn = 200000 + 10;
const long long mod = 998244353;
unordered_map<long long, long long> f[maxn];
long long a[maxn];
int main() {
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
    f[n][a[n]] = 1;
    vector<long long> fr, nt;
    fr.push_back(a[n]);
    long long ans = 0;
    for (long long i = n - 1; i >= 1; i--) {
      f[i][a[i]] = 1;
      nt.push_back(a[i]);
      for (long long j = 0; j < fr.size(); j++) {
        long long v = f[i + 1][fr[j]];
        long long t = a[i] / ((a[i] + fr[j] - 1) / fr[j]);
        if (!f[i][t]) nt.push_back(t);
        f[i][t] += v;
        ans += i * v * ((a[i] + fr[j] - 1) / fr[j] - 1);
        cout << i << " " << fr[j] << " " << v << " " << t << "  "
             << (a[i] + fr[j] - 1) / fr[j] - 1 << endl;
      }
      fr = nt;
      nt.clear();
    }
    printf("%lld\n", ans);
  }
  return 0;
}
