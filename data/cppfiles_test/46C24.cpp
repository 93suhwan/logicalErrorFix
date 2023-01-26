#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265358979323846;
const long long M = 1e18 + 7;
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const int mod = 998244353;
void solve() {
  int n;
  cin >> n;
  vector<long long> v(n), pre(n);
  pre[0] = 0;
  for (long long i = 0; i < (n); ++i) {
    cin >> v[i];
    if (i == 0)
      pre[i] = v[i];
    else if (i % 2) {
      pre[i] = pre[i - 1] - v[i];
    } else
      pre[i] = pre[i - 1] + v[i];
  }
  long long mn;
  long long ans = 0;
  for (int i = 0; i < n; i += 2) {
    mn = 0;
    long long a = 0, b = 0;
    for (int j = i + 1; j < n; j++) {
      if (j % 2) {
        if (v[i] >= mn && v[j] >= a + mn) {
          int b = a + mn;
          ans += min(v[i] - mn + (mn != 0 ? 1 : 0),
                     v[j] - (a + mn) + (b != 0 ? 1 : 0));
        }
        if (v[j] > a) {
          mn = max(mn, v[j] - a);
          a -= v[j];
        } else {
          a -= v[j];
        }
      } else {
        a += v[j];
      }
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
