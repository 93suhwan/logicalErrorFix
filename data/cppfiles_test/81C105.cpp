#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
void solve() {
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<long long> p(n + 1, 0);
  for (long long i = 1; i <= n; i++) {
    if (s[i - 1] == '+') {
      p[i] = -1;
    } else {
      p[i] = 1;
    }
    if (i % 2 == 0) {
      p[i] *= -1;
    }
    p[i] += p[i - 1];
  }
  while (k--) {
    long long a, b;
    cin >> a >> b;
    long long pos = p[b] - p[a - 1];
    if (pos == 0) {
      cout << 0 << endl;
    } else {
      if ((b - a + 1) & 1) {
        cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
