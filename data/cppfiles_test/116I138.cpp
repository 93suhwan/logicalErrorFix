#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
void testcase() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long mex[n + 1][2];
  for (int i = 0; i <= n; i++) {
    mex[i][0] = 0;
    mex[i][1] = 0;
  }
  mex[0][0] = 1;
  long long res = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] - 1 >= 0) {
      res += mex[a[i] - 1][1];
      res %= mod;
      mex[a[i] - 1][1] += mex[a[i] - 1][1];
      mex[a[i] - 1][1] %= mod;
      res += mex[a[i] - 1][0];
      res %= mod;
      mex[a[i] - 1][1] += mex[a[i] - 1][0];
      mex[a[i] - 1][1] %= mod;
    }
    long long tmp = 0;
    res += mex[a[i] + 1][0];
    res %= mod;
    res += mex[a[i]][0];
    res %= mod;
    tmp = mex[a[i] + 1][0] + mex[a[i]][0];
    tmp %= mod;
    mex[a[i] + 1][0] += tmp;
    mex[a[i] + 1][0] %= mod;
  }
  cout << res << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) testcase();
  return 0;
}
