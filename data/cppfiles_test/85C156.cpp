#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int N = 100010, INF = 0x3f3f3f3f;
int T;
void solve() {
  string s;
  cin >> s;
  int cnt0 = 0, cnt1 = 0, kuai = 0;
  for (auto i : s)
    if (i == '0')
      cnt0++;
    else
      cnt1++;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0' && !i)
      kuai++;
    else if (s[i] == '0' && i && s[i - 1] != '0')
      kuai++;
  }
  int ans = 0;
  if (cnt0 == 0)
    ans = 0;
  else if (cnt1 == 0)
    ans = 1;
  else if (!(kuai - 1))
    ans = 1;
  else
    ans = 2;
  cout << ans << '\n';
}
int main(void) {
  clock_t c1 = clock();
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
