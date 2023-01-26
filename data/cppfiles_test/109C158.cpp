#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != '0') {
      if (i == n - 1) {
        cnt += s[i] - '0';
      } else {
        cnt += s[i] - '0';
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
