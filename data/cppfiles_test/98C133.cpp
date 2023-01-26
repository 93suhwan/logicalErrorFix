#include <bits/stdc++.h>
using namespace std;
int ans[1010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string harf, s;
    cin >> harf >> s;
    int now, ghabl;
    for (int b = 0; b < s.size(); b++) {
      for (int c = 0; c < 26; c++) {
        if (harf[c] == s[b]) {
          now = c;
          c = 100;
        }
      }
      if (b != 0) {
        int a = ghabl - now;
        if (a < 0) {
          a *= -1;
        }
        ans[i] += a;
      }
      ghabl = now;
    }
    if (i != n) {
      cout << endl;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i];
    if (i != n) {
      cout << endl;
    }
  }
  return 0;
}
