#include <bits/stdc++.h>
using namespace std;
const long long maxn = 400505;
const long long inf = 0x3f3f3f3f;
long long n, m, k;
long long a[maxn];
void solve() {
  cin >> n >> k;
  long long t = n / 3;
  for (long long _ = 0; _ < t; _++) {
    long long i = _ * 3 + 1, j = i + 1, w = j + 1;
    long long A[6];
    cout << "or " << i << ' ' << j << endl;
    cout << "or " << i << ' ' << w << endl;
    cout << "or " << j << ' ' << w << endl;
    cout << "and " << i << ' ' << j << endl;
    cout << "and " << i << ' ' << w << endl;
    cout << "and " << j << ' ' << w << endl;
    fflush(stdout);
    for (long long ii = 0; ii < 6; ii++) cin >> A[ii];
    for (long long ii = 31; ~ii; ii--) {
      long long tmp = 0;
      for (long long jj = 0; jj < 6; jj++) {
        if (A[jj] & (1 << ii)) {
          tmp += (1 << (5 - jj));
        }
      }
      if (tmp == 24) {
        a[w] += (1 << ii);
      } else if (tmp == 40) {
        a[j] += (1 << ii);
      } else if (tmp == 57) {
        a[w] += (1 << ii);
        a[j] += (1 << ii);
      } else if (tmp == 48) {
        a[i] += (1 << ii);
      } else if (tmp == 58) {
        a[w] += (1 << ii);
        a[i] += (1 << ii);
      } else if (tmp == 60) {
        a[j] += (1 << ii);
        a[i] += (1 << ii);
      } else if (tmp == 63) {
        a[w] += (1 << ii);
        a[j] += (1 << ii);
        a[i] += (1 << ii);
      }
    }
  }
  m = n % 3;
  for (long long _ = 1; _ <= m; _++) {
    long long tmp = t * 3 + _;
    cout << "or " << 1 << ' ' << tmp << endl;
    cout << "and " << 1 << ' ' << tmp << endl;
    long long A, B;
    fflush(stdout);
    cin >> A >> B;
    for (long long ii = 31; ~ii; ii--) {
      if ((a[1] & (1 << ii)) == 0) {
        if (A & (1 << ii)) a[tmp] += (1 << ii);
      } else {
        if (B & (1 << ii)) a[tmp] += (1 << ii);
      }
    }
  }
  sort(a + 1, a + 1 + n);
  cout << "finish " << a[k] << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tn = 1;
  for (long long __ = 1; __ <= tn; __++) {
    solve();
  }
}
