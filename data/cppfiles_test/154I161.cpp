#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a + b == c) {
    cout << "YES\n";
    return;
  }
  if (b + c == a) {
    cout << "YES\n";
    return;
  }
  if (a == b) {
    if (c % 2 == 0) {
      cout << "YES\n";
      return;
    } else {
      cout << "NO\n";
      return;
    }
  }
  if (b == c) {
    if (a % 2 == 0) {
      cout << "YES\n";
      return;
    } else {
      cout << "NO\n";
      return;
    }
  }
  if (a == c) {
    if (b % 2 == 0) {
      cout << "YES\n";
      return;
    } else {
      cout << "NO\n";
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
