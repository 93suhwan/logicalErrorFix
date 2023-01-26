#include <bits/stdc++.h>
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
void setIO() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
}
void solve() {
  long long n;
  cin >> n;
  long long a[2][n];
  for (long long i = 0; i < (2); i++)
    for (long long j = 0; j < (n); j++) {
      cin >> a[i][j];
    }
  long long row1 = 0, row2 = 0;
  for (long long i = 1; i < (n); i++) {
    row1 += a[0][i];
  }
  long long ans = row1;
  for (long long i = 1; i < (n); i++) {
    row2 += a[1][i - 1];
    row1 -= a[0][i];
    ckmin(ans, max(row1, row2));
  }
  cout << ans << '\n';
}
int32_t main() {
  setIO();
  long long T;
  cin >> T;
  while (T--) {
    solve();
  }
}
