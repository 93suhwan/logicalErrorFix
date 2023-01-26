#include <bits/stdc++.h>
using namespace std;
void prar(long long *a, long long n) {
  for (long long i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}
long long mgcd(long long a, long long b) {
  return (a == 0) ? (b) : (mgcd(b % a, a));
}
void solve(long long z) {
  long long n;
  cin >> n;
  map<long long, long long> fa, fb;
  vector<pair<long long, long long> > p(n);
  for (long long i = 0; i < n; i++) {
    cin >> p[i].first;
    cin >> p[i].second;
    fa[p[i].first] = 0;
    fb[p[i].second] = 0;
  }
  for (long long i = 0; i < n; i++) {
    fa[p[i].first] += 1;
    fb[p[i].second] += 1;
  }
  long long cnt = 0;
  for (long long i = 0; i < n; i++) {
    cnt += (fa[p[i].first] - 1) * (fb[p[i].second] - 1);
  }
  long long ans = (n * (n - 1) * (n - 2) / 6) - cnt;
  cout << ans << "\n";
  return;
}
signed main() {
  long long t;
  scanf("%lld", &t);
  for (long long z = 1; z <= t; z++) {
    solve(z);
  }
  return 0;
}
