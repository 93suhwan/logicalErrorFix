#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, flag = 0;
  cin >> n;
  string a[2];
  for (int i = 0; i < 2; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    if (a[0][i] == '1' && a[1][i] == '1') {
      flag = 1;
      break;
    }
  }
  if (flag == 0)
    cout << "YES";
  else
    cout << "NO";
  cout << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
