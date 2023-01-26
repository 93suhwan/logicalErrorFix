#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int mini1 = 0, maxi1 = 0, mini2 = 0, maxi2 = 0;
  for (int i = 0; i < 10; i++) {
    if (i % 2) {
      if (s[i] == '1')
        mini2++, maxi2++;
      else if (s[i] == '?')
        maxi2++;
    } else {
      if (s[i] == '1')
        mini1++, maxi1++;
      else if (s[i] == '?')
        maxi1++;
    }
    if ((9 - i) / 2 + mini1 < maxi2) {
      cout << i + 1 << "\n";
      return;
    }
    if ((10 - i) / 2 + mini2 < maxi1) {
      cout << i + 1 << "\n";
      return;
    }
  }
  cout << 10 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
