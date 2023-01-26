#include <bits/stdc++.h>
using namespace std;
void test_case() {
  long long n, d;
  cin >> n >> d;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  queue<long long> q;
  for (long long i = 0; i < n; i++)
    if (a[i] == 0) q.push(i);
  long long res = 0, taken = 0;
  while (!q.empty()) {
    long long m = q.size();
    for (long long j = 0; j < m; j++) {
      long long u = q.front();
      q.pop();
      taken++;
      (u += d) %= n;
      if (a[u] == 1) {
        a[u] = 0;
        q.push(u);
      }
    }
    res++;
  }
  cout << (taken == n ? res - 1 : -1) << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long tc;
  cin >> tc;
  while (tc--) {
    test_case();
  }
  return 0;
}
