#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long MOD = (long long)1e9 + 7LL;
const int MAXN = (int)1e6 + 5;
void Solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  int num0 = 0, num1 = 0;
  int num00 = 0, num01 = 0;
  int num10 = 0, num11 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == t[i]) {
      num0++;
      if (s[i] == '0')
        num00++;
      else
        num11++;
    } else {
      num1++;
      if (s[i] == '0')
        num01++;
      else
        num10++;
    }
  }
  int res = 0x3f3f3f3f;
  if (num0 & 1) {
    if (num11 == num00 + 1) res = min(res, num0);
  }
  if ((num1 & 1) == 0) {
    if (num01 == num10) res = min(res, num1);
  }
  if (res == 0x3f3f3f3f) res = -1;
  cout << res << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    Solve();
  }
  return 0;
}
