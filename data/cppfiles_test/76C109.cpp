#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n, mod;
  cin >> n >> mod;
  vector<long long> d(n + 1), p(n + 1);
  d[1] = 1;
  long long cur = d[1];
  for (long long i = 2; i <= n; i++) {
    d[i] += cur;
    d[i] %= mod;
    long long q = (long long)sqrt(i);
    vector<long long> s;
    for (long long j = 2; i / j >= q; j++) {
      if (s.empty() || s.back() != i / j) s.push_back(i / j);
    }
    for (long long j = 1; j < q; j++) {
      d[i] += d[j] * (i / j - i / (j + 1));
      d[i] %= mod;
    }
    for (long long j : s) {
      d[i] += d[j] * (i / j - i / (j + 1));
      d[i] %= mod;
    }
    cur += d[i];
    cur %= mod;
  }
  cout << d[n];
}
