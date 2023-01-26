#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    if (a == 1)
      cout << b << "\n";
    else if (a == 2 || a == 3)
      cout << b / 2 << "\n";
    else if ((a & 1) == 0) {
      a = (a + 1) / 2;
      cout << b / (a + 1) << "\n";
    } else {
      a = (a + 1) / 2;
      cout << b / a << "\n";
    }
  }
}
