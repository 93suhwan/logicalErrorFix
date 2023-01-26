#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n == 1 and s[0] == '?') {
    cout << 'R' << "\n";
    return;
  }
  for (int i = 1; i < n; i++) {
    if (s[i] == '?') {
      if (s[i - 1] == 'B') {
        s[i] = 'R';
      } else if (s[i - 1] == 'R') {
        s[i] = 'B';
      }
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    if (s[i] == '?') {
      if (s[i + 1] == 'B') {
        s[i] = 'R';
      } else if (s[i + 1] == 'R') {
        s[i] = 'B';
      }
    }
  }
  cout << s << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  for (int c = 0; c < t; c++) {
    solve();
  }
}
