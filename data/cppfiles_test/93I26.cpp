#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t, a, b, i, j, s;
  cin >> t;
  for (i = 0; i < t; i++) {
    s = 0;
    cin >> a >> b;
    if (a % 4 == 0 || a == 1)
      s = 0;
    else if ((a + 1) % 4 == 0)
      s = a;
    else if ((a + 2) % 4 == 0)
      s = 1;
    else
      s = a - 1;
    s = s ^ b;
    if (s == b && b <= a)
      cout << a + 2 << "\n";
    else if (s < b)
      cout << a << "\n";
    else
      cout << a + 1 << "\n";
  }
  return 0;
}
