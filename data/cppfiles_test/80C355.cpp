#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  string s;
  cin >> n >> s;
  if (s.find("0") == string::npos) {
    cout << 1 << ' ' << n / 2 << ' ';
    cout << 2 << ' ' << n / 2 + 1;
    return;
  } else {
    for (int i = 0; i < n / 2; i++) {
      if (s[i] == '0') {
        cout << i + 2 << ' ' << n << ' ';
        cout << i + 1 << ' ' << n;
        return;
      }
    }
    for (int i = n / 2; i < n; i++) {
      if (s[i] == '0') {
        cout << 1 << ' ' << i + 1 << ' ';
        cout << 1 << ' ' << i;
        return;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}
