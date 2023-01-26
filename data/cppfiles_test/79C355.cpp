#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#pragma GCC optimize("Ofast")
using namespace std;
const long long mxn = 2e5 + 10;
long long pri(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long test = 1;
  cin >> test;
  while (test--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    std::vector<long long> ans1;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      long long x = s[i] - '0';
      if (pri(x) == 0 || x == 1) {
        cout << 1 << "\n";
        cout << x << "\n";
        ans++;
        break;
      }
    }
    long long x, xx;
    if (!ans) {
      for (long long i = 0; i < n; i++) {
        for (long long j = i + 1; j < n; j++) {
          x = s[i] - '0';
          xx = s[j] - '0';
          if (pri(10 * (x) + xx) == 0) {
            cout << 2 << "\n";
            cout << 10 * x + xx << "\n";
            ans++;
            break;
          }
        }
        if (ans) break;
      }
    }
  }
}
