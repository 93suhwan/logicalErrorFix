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
  for (intll i = 1; i < n - 1; i++) {
    if (t[i] == '1') {
      if (s[i] == '0') {
        cnt++;
      } else if (s[i] == '1' && s[i - 1] == '1') {
        cnt++;
        s[i - 1] = '0';
        continue;
      } else if (s[i] == '1' && s[i + 1] == '1') {
        cnt++;
        s[i + 1] = '0';
        continue;
      }
    }
  }
  if (t[0] == '1') {
    if (s[0] == '0') {
      cnt++;
    } else if (s[0] == '1' && s[1] == '1') {
      cnt++;
      s[1] = '0';
    }
  }
  if (t[n - 1] == '1') {
    if (s[n - 1] == '0') {
      cnt++;
    } else if (s[n - 1] == '1' && s[n - 2] == '1') {
      cnt++;
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
