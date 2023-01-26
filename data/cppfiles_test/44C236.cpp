#include <bits/stdc++.h>
using namespace std;
void doomed() {
  int a, b;
  cin >> a >> b;
  if (a == b && a == 0) {
    cout << 0 << '\n';
    return;
  } else if (a == b) {
    cout << 1 << '\n';
    return;
  }
  if ((a & 1) == (b & 1)) {
    cout << 2 << '\n';
  } else {
    cout << -1 << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    doomed();
  }
  return 0;
}
