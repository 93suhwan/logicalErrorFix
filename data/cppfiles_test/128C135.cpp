#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, a, b, c, i, v;
    cin >> n;
    if (n % 2 == 0) {
      n--;
      cout << n / 2 + 1 << " " << n / 2 << " "
           << "1\n";
    } else {
      n--;
      if ((n / 2) % 2 == 0) {
        cout << n / 2 + 1 << " " << n / 2 - 1 << " "
             << "1\n";
      } else {
        cout << n / 2 + 2 << " " << n / 2 - 2 << " "
             << "1\n";
      }
    }
  }
}
