#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int tt = 0; tt < (t); tt++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b == c || a + c == b || b + c == a || (a == b && c % 2 == 0) ||
        (a == c && b % 2 == 0) || (b == c && a % 2 == 0))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
