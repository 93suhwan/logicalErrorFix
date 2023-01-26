#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize "trapv"
const long double EPS = 1e-6;
long long MOD = int(1e9) + 7;
long long &mod = MOD;
class Solution {
  static const int maxN = int(1e5) + 2;
  const long long inf = 1e18;

 public:
  Solution() {}

 public:
  void SolveEachTest(int _TestCase) {
    long long n, m;
    cin >> n >> m;
    map<long long, long long> cntWeaks;
    long long res = n;
    for (long long xx = 0ll; xx < m; (xx) += 1ll) {
      long long a, b;
      cin >> a >> b;
      if (b < a) {
        swap(a, b);
      }
      cntWeaks[a] += 1;
      if (cntWeaks[a] == 1) {
        res -= 1;
      }
    }
    long long q;
    cin >> q;
    for (long long qq = 0ll; qq < q; (qq) += 1ll) {
      long long qType;
      cin >> qType;
      if (qType == 3) {
        cout << res << "\n";
      } else if (qType == 1) {
        long long a, b;
        cin >> a >> b;
        if (b < a) {
          swap(a, b);
        }
        cntWeaks[a] += 1;
        if (cntWeaks[a] == 1) {
          res -= 1;
        }
      } else {
        long long a, b;
        cin >> a >> b;
        if (b < a) {
          swap(a, b);
        }
        cntWeaks[a] -= 1;
        if (cntWeaks[a] == 0) {
          res += 1;
        }
      }
    }
  }

 public:
  void ResetTestCase() { cout << "\n"; }
};
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int _T0T4 = 1;
  Solution Aurora;
  for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
    Aurora.SolveEachTest(_TestCase);
    Aurora.ResetTestCase();
  }
  return 0;
}
