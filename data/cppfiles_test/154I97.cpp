#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tst;
  cin >> tst;
  while (tst--) {
    int a, b, c;
    cin >> a >> b >> c;
    int perimeter = a + b + c;
    if (perimeter % 2 == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
