#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool solved = false;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      solved = true;
      if (i >= n / 2) {
        cout << 1 << " " << i + 1 << " " << 1 << " " << i << endl;
        break;
      } else {
        cout << i + 2 << " " << n << " " << i + 1 << " " << n << endl;
        break;
      }
    }
  }
  if (!solved) {
    cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;
  }
}
int main() {
  ll ttt;
  cin >> ttt;
  while (ttt--) solve();
  return 0;
}
