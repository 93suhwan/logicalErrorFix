#include <bits/stdc++.h>
using namespace std;
void handle_io() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  int P;
  cin >> P;
  if (P == 5)
    cout << 2 << " " << 4 << endl;
  else
    cout << 2 << " " << P / 2 << endl;
}
int main() {
  handle_io();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
