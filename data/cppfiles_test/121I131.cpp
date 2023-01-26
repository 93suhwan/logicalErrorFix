#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int TESTCASE;
  cin >> TESTCASE;
  while (TESTCASE--) {
    long long int n, ck = 1;
    cin >> n;
    string a, b;
    cin >> a >> b;
    long long int cntOneOne = 0, cntZeroZero = 0, cntZeroOne = 0,
                  cntOneZero = 0;
    for (long long int i = (0); i <= (n - 1); i++) {
      if (a[i] == '1' && b[i] == '1') cntOneOne++;
      if (a[i] == '0' && b[i] == '0') cntZeroZero++;
      if (a[i] == '1' && b[i] == '0') cntOneZero++;
      if (a[i] == '0' && b[i] == '1') cntZeroOne++;
      if (a[i] != b[i]) ck = 0;
    }
    long long int ans = min(cntZeroOne, cntOneZero) * 2;
    if (cntOneOne == cntZeroZero + 1 && ans != 0)
      ans = min(ans, cntOneOne + cntZeroZero);
    else if (cntOneOne == cntZeroZero + 1 && ans == 0)
      ans = cntOneOne + cntZeroZero;
    if (cntOneOne == 0 && ans == 0) ans = -1;
    if (ck) ans = 0;
    cout << ans << "\n";
  }
  return 0;
}
