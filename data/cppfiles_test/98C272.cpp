#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
int t, n;
string s;
void solve() {
  for (int i = 1; i <= n; ++i) {
    int a = 0, b = 0;
    for (int j = i; j <= n; ++j) {
      a += (s[j] == 'a');
      b += (s[j] == 'b');
      if (a == b) {
        cout << i << ' ' << j << '\n';
        return;
      }
    }
  }
  cout << -1 << ' ' << -1 << '\n';
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    s = ' ' + s;
    solve();
  }
}
