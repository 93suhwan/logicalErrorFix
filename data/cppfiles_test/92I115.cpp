#include <bits/stdc++.h>
using namespace std;
void Solve() {
  string s;
  cin >> s;
  int n = s.size();
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < n - 1; i++) {
    string t = s.substr(i, 2);
    if (t == "ab") {
      cnt1++;
    } else if (t == "ba") {
      cnt2++;
    }
  }
  if (cnt1 == cnt2) {
    cout << s << "\n";
    return;
  }
  if (cnt1 > cnt2) {
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == 'b') {
        s[i] = 'a';
        break;
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      if (s[i] == 'a') {
        s[i] = 'b';
        break;
      }
    }
  }
  cout << s << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int TC = 1;
  cin >> TC;
  while (TC--) Solve();
}
