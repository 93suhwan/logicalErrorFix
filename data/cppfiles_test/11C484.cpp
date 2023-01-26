#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
template <typename t>
using vc = vector<t>;
void solve() {
  long long n;
  cin >> n;
  vc<array<long long, 6>> a(n, {0, 0, 0, 0, 0});
  string s;
  for (long long i = 0; i < n; i++) {
    cin >> s;
    for (auto &j : s) a[i][j - 'a']++;
    a[i][5] = s.length();
  }
  long long res(0);
  for (long long i = 0; i < 5; i++) {
    sort(begin(a), end(a), [&](array<long long, 6> x, array<long long, 6> y) {
      long long p = x[i];
      p -= (x[5] - x[i]);
      long long q = y[i];
      q -= (y[5] - y[i]);
      return p > q;
    });
    long long sum1(0), sum2(0);
    for (long long j = 0; j < n; j++) {
      sum1 += a[j][i];
      sum2 += a[j][5] - a[j][i];
      if (sum1 <= sum2) break;
      res = max(res, j + 1);
    }
  }
  cout << res << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t(1);
  cin >> t;
  for (long long i = 1; i <= t; solve(), i++)
    ;
  return 0;
}
