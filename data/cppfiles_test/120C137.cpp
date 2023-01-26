#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    map<long long, long long> m;
    for (long long i = 0; i <= log2(r); i++) {
      long long x = i + 1;
      long long y = 1 << x;
      long long ans = 0;
      ans += ((r + 1) / y) * (y / 2);
      ans -= ((l) / y) * (y / 2);
      long long a = l % y;
      long long b = (r + 1) % y;
      if (b) {
        if (b <= (y / 2))
          ans += b;
        else
          ans += (y / 2);
      }
      if (a) {
        if (a <= (y / 2))
          ans -= a;
        else
          ans -= (y / 2);
      }
      m[i] += ans;
    }
    long long res = INT_MAX;
    for (auto i : m) {
      if (i.second < res) res = i.second;
    }
    cout << res << endl;
  }
  return 0;
}
