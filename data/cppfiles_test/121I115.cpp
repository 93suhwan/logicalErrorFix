#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long MOD = (long long)1e9 + 7LL;
const int MAXN = (int)1e6 + 5;
void Solve() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  bool tag1 = false, tag2 = false;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < n; ++i) {
    if (s1[i] == s2[i]) {
      ++cnt1;
      if (s1[i] == '1') tag1 = true;
    } else {
      ++cnt2;
      if (s1[i] == '1') tag2 = true;
    }
  }
  if (cnt1 == n) {
    cout << 0 << endl;
    return;
  }
  if (tag1 && tag2)
    cout << min(cnt1, cnt2) << endl;
  else if (tag1)
    cout << cnt1 << endl;
  else if (tag2)
    cout << cnt2 << endl;
  else
    cout << -1 << endl;
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
