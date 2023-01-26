#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x7fffffff;
void solve() {
  string s;
  cin >> s;
  set<char> s1;
  int cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < s.length(); i++) {
    s1.insert(s[i]);
    if (s[i] == '1')
      cnt1++;
    else
      cnt0++;
  }
  if (s1.size() == 1) {
    if (s[0] == '1') {
      cout << 0 << "\n";
      return;
    } else {
      cout << 1 << "\n";
      return;
    }
  }
  if (cnt0 == cnt1) {
    cout << 1 << "\n";
    return;
  } else if (cnt0 > cnt1) {
    cout << 2 << "\n";
    return;
  } else {
    cout << 1 << "\n";
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
