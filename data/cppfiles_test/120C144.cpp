#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
const long long N = 2e5 + 10;
const long double PI = acos(-1);
using namespace std;
long long pre[20][N];
void masive() {
  for (long long i = 0; i < 20; i++) {
    for (long long j = 1; j < N; j++) {
      pre[i][j] = pre[i][j - 1];
      if (((1ll << i) & j) != 0) {
        pre[i][j]++;
      }
    }
  }
}
void judge() {
  long long l, r;
  cin >> l >> r;
  long long k = r - l + 1, res = 1e15;
  for (long long i = 0; i < 20; i++) {
    res = min(res, k - (pre[i][r] - pre[i][l - 1]));
  }
  cout << res << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  ;
  masive();
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    judge();
  }
  return 0;
}
