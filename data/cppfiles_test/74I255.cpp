#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  string str, str2;
  long long elm, tc, n, m;
  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    if (n == 0) {
      if (m % 2 == 0)
        cout << 1 << endl << m / 2 << endl;
      else
        cout << 2 << endl << m / 2 << " " << m / 2 + 1 << endl;
    } else if (m == 0) {
      if (n % 2 == 0)
        cout << 1 << endl << n / 2 << endl;
      else
        cout << 2 << endl << n / 2 << " " << n / 2 + 1 << endl;
    } else if (n == m) {
      cout << (n + m) / 2 + 1 << endl;
      for (long long x = 0; x <= (n + m); x += 2) cout << x << " ";
      cout << endl;
    } else {
      cout << n + m + 1 << endl;
      for (long long x = 0; x <= (n + m); x++) cout << x << " ";
      cout << endl;
    }
  }
  return 0;
}
