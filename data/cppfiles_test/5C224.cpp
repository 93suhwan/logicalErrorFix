#include <bits/stdc++.h>
using namespace std;
using intll = long long int;
void solve() {
  intll n;
  cin >> n;
  string s;
  string t;
  cin >> s;
  cin >> t;
  intll cnt = 0;
  for (intll i = 0; i < n; i++) {
    if (t[i] == '1') {
      if (s[i] == '0') {
        cnt++;
      } else if (s[i - 1] == '1') {
        cnt++;
        s[i - 1] = '0';
      } else if (s[i + 1] == '1') {
        cnt++;
        s[i + 1] = '0';
      }
    }
  }
  cout << cnt << endl;
}
int main() {
  intll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
