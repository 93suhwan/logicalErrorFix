#include <bits/stdc++.h>
using namespace std;
void solve() {
  int t;
  cin >> t;
  string s;
  while (t--) {
    cin >> s;
    int a = 0, b = 0;
    int mn = 10;
    for (int i = 0; i < 10; i++) {
      if (i & 1) {
        if (s[i] == '1' || s[i] == '?') {
          b++;
        }
        if (a + (10 - i) / 2 < b || b + (10 - i) / 2 < a) {
          mn = min(mn, i + 1);
          break;
        }
      } else {
        if (s[i] == '1') {
          a++;
        }
        if (a + (10 - i) / 2 - 1 < b || b + (10 - i) / 2 < a) {
          mn = min(mn, i + 1);
          break;
        }
      }
    }
    a = b = 0;
    for (int i = 0; i < 10; i++) {
      if (i & 1) {
        if (s[i] == '1') {
          b++;
        }
        if (a + (10 - i) / 2 < b || b + (10 - i) / 2 < a) {
          mn = min(mn, i + 1);
          break;
        }
      } else {
        if (s[i] == '1' || s[i] == '?') {
          a++;
        }
        if (a + (10 - i) / 2 - 1 < b || b + (10 - i) / 2 < a) {
          mn = min(mn, i + 1);
          break;
        }
      }
    }
    cout << mn << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
