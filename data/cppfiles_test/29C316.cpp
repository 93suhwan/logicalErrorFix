#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  long long test;
  cin >> test;
  for (long long ee = 0; ee < test; ++ee) {
    long long n;
    cin >> n;
    long long x = 0, y = 0;
    for (long long i = 0; i < n; ++i) {
      long long t;
      cin >> t;
      x += (t == 0);
      y += (t == 1);
    }
    long long sol = y * (1ll << x);
    cout << sol << '\n';
  }
}
