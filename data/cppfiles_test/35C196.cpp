#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
void solve() {
  long long n, m;
  cin >> n >> m;
  if (n > m) {
    cout << "0\n";
    return;
  }
  vector<long long> pre(35, 0);
  long long res = 1;
  for (long long bit = 0; bit < 31; bit++) {
    if (!(n & res)) {
      if (bit == 0) {
        pre[bit] += res;
      } else {
        pre[bit] += pre[bit - 1];
        pre[bit] += res;
      }
    } else if (bit != 0)
      pre[bit] += pre[bit - 1];
    res <<= 1;
  }
  long long ans = m - n + 1;
  long long mul = 1 << 30;
  for (long long bit = 30; bit >= 0; bit--) {
    if (!(n & mul)) {
      if (bit == 0 && ans > 0) {
        ans -= mul;
      } else if (pre[bit - 1] < ans && ans > 0) {
        ans -= mul;
      }
    }
    mul >>= 1;
  }
  ans = abs(ans) + m + 1;
  ans = n ^ ans;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
