#include <bits/stdc++.h>
using namespace std;
const long long MAX = 100000;
const long long M = 1e9 + 7;
vector<long long> dv[MAX + 1], phi(MAX + 1);
void init() {
  for (long long i = 1; i <= MAX; i++) {
    if (i % 2)
      phi[i] = i;
    else
      phi[i] = i / 2;
    for (long long j = i; j <= MAX; j += i) {
      dv[j].push_back(i);
    }
  }
  for (long long i = 3; i <= MAX; i++) {
    if (phi[i] == i) {
      for (long long j = i; j <= MAX; j += i) {
        phi[j] = phi[j] / i * (i - 1);
      }
    }
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  init();
  long long n;
  cin >> n;
  vector<long long> a(n + 1);
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  vector<long long> hist(MAX + 1);
  for (long long i = 1; i <= n; i++) {
    vector<long long> dvs;
    for (long long j = i; j <= n; j += i) {
      for (long long d : dv[a[j]]) {
        dvs.push_back(d);
        hist[d]++;
      }
    }
    long long tmp = 0;
    for (long long d : dvs) {
      tmp += hist[d] * hist[d] * phi[d];
      tmp %= M;
      hist[d] = 0;
    }
    ans += tmp * phi[i];
    ans %= M;
  }
  cout << ans << '\n';
  return 0;
}
