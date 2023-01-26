#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a + b == c || a + c == b || b + c == a)
    cout << "YES" << endl;
  else if (a == b && (c % 2 == 0))
    cout << "YES" << endl;
  else if (a == c && (b % 2 == 0))
    cout << "YES" << endl;
  else if (b == c && (a % 2 == 0))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
