#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long mod = 1e9 + 7;
void preCal() {}
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (n % m == 0) {
    for (long long i = 1, val = n / m; i <= k; i++) {
      long long start = 1;
      for (long long j = 1; j <= m; j++) {
        cout << val << ' ';
        for (long long k = 1; k <= val; k++) {
          cout << start++ << ' ';
        }
        cout << '\n';
      }
    }
  }
  long long block1 = n / m;
  long long freq1 = m - (n % m);
  long long block2 = (n + m - 1) / m;
  long long freq2 = m - freq1;
  long long turn = 1;
  for (long long i = 1; i <= k; i++) {
    set<long long> s;
    for (long long i = 1; i <= n; i++) {
      s.insert(i);
    }
    for (long long j = 1; j <= freq2; j++) {
      cout << block2 << ' ';
      for (long long k = 1; k <= block2; k++) {
        s.erase(turn);
        cout << turn++ << ' ';
        if (turn > n) {
          turn = 1;
        }
      }
      cout << '\n';
    }
    for (long long j = 1; j <= freq1; j++) {
      cout << block1 << ' ';
      for (long long k = 1; k <= block1; k++) {
        cout << (*s.begin()) << ' ';
        s.erase(s.begin());
      }
      cout << '\n';
    }
  }
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  preCal();
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
}
