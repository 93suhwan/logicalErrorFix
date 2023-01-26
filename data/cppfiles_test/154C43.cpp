#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a == b) {
    if (c % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else if (a == c) {
    if (b % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else if (b == c) {
    if (a % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else {
    int mx = max(a, b);
    mx = max(mx, c);
    if (a == mx && b + c == a || b == mx && a + c == b || c == mx && a + b == c)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) solve();
  return 0;
}
