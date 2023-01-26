#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    bool ok = abs(a - b) % 2 == 0;
    if (ok) {
      if (a == b && (a != 0))
        cout << "1" << '\n';
      else if (a == b && a == 0)
        cout << "0" << '\n';
      else
        cout << "2" << '\n';
    } else
      cout << "-1" << '\n';
  }
  return 0;
}
