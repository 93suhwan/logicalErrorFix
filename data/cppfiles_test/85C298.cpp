#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0')
      cnt1++;
    else
      cnt2++;
  }
  if (cnt1 == 0) {
    cout << 0 << endl;
    return;
  } else if (cnt2 == 0) {
    cout << 1 << endl;
    return;
  }
  int cnt = 0;
  if (s[0] == '0') cnt++;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == '0' && s[i - 1] != '0') cnt++;
  }
  if (cnt == 1)
    cout << 1 << endl;
  else
    cout << 2 << endl;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
