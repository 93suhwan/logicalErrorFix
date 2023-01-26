#include <bits/stdc++.h>
using namespace std;
int calc(int n, int m) {
  int ans = 0;
  for (int k = 29; k >= 0; k--) {
    if (n > m) break;
    if (m + 1 == (1 << (k + 1))) {
      ans ^= (1 << (k + 1));
      break;
    }
    int nbit = ((n >> k) & 1);
    int mbit = ((m >> k) & 1);
    if (nbit == 0) {
      if (mbit == 1) {
        ans ^= (1 << k);
        m ^= (1 << k);
      }
    } else {
      if (mbit == 1) {
        n ^= (1 << k);
        m ^= (1 << k);
      } else {
        cerr << n << ' ' << m << endl;
        assert(false);
      }
    }
  }
  if (n == 0 && m == 0) ans++;
  return ans;
}
int calc_naive(int n, int m) {
  if (n > m) return 0;
  vector<int> b(2 * m + 2);
  for (int i = 0; i <= m; i++) {
    assert((n ^ i) < b.size());
    b[n ^ i] = 1;
  }
  for (int i = 0; i < b.size(); i++)
    if (b[i] == 0) return i;
  assert(false);
}
void solve() {
  int n, m;
  cin >> n >> m;
  int ans = calc(n, m);
  cout << ans << '\n';
}
void test_solve() {
  for (int n = 0; n <= 32; n++) {
    for (int m = 0; m <= 128; m++) {
      int r1 = calc(n, m);
      int r2 = calc_naive(n, m);
      if (r1 != r2) {
        cout << n << ' ' << m << ' ' << r1 << ' ' << r2 << endl;
        assert(false);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
