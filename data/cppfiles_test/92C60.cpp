#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m, k, x, y, i, j, ans = 0, c = 0, sum = 0;
  string s;
  cin >> s;
  n = s.size();
  for (i = 1; i < n; i++) {
    if (s[i] == 'a' && s[i - 1] == 'b')
      c++;
    else if (s[i] == 'b' && s[i - 1] == 'a')
      c--;
  }
  if (c == 0) {
    cout << s << "\n";
    return;
  }
  if (c > 0) {
    for (i = n - 1; i >= 0; i--) {
      if (s[i] == 'a') {
        c--;
        s[i] = 'b';
        break;
      }
    }
    cout << s << "\n";
  } else {
    for (i = 0; i < n; i++) {
      if (s[i] == 'a') {
        s[i] = 'b';
        break;
      }
    }
    cout << s << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
