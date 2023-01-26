#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long c, d;
    cin >> c >> d;
    if (c == 0 && d == 0)
      cout << 0 << "\n";
    else if (c == d)
      cout << 1 << "\n";
    else if (abs(c - d) == 1)
      cout << -1 << "\n";
    else if (abs(c - d) == c)
      cout << 2 << "\n";
    else if (abs(c - d) == d)
      cout << 2 << "\n";
    else
      cout << abs(c - d) << "\n";
  }
  return 0;
}
