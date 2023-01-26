#include <bits/stdc++.h>
using namespace std;
long long int findOnFromOneToN(int n, int j) {
  n++;
  long long int v = 1 << j;
  long long int d = v * 2;
  long long int seg = n / d;
  long long int res = seg * v;
  long long int ex = n - seg * d;
  ex -= v;
  if (ex > 0) res += ex;
  return res;
}
void solve() {
  int l, r;
  cin >> l >> r;
  long long int mx = 0;
  for (int i = 0; i < 31; i++) {
    long long int res = findOnFromOneToN(r, i) - findOnFromOneToN(l - 1, i);
    mx = max(mx, res);
  }
  cout << r - l + 1 - mx << endl;
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
