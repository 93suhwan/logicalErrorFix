#include <bits/stdc++.h>
using namespace std;
int fr[4];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  int n;
  while (t--) {
    cin >> n;
    if (n <= 9) {
      if (n % 3 != 0)
        cout << n << '\n';
      else
        cout << n + 1 << '\n';
    } else {
      n++;
      while (true) {
        int d = n % 10;
        if (d != 3 && n % 3 != 0) {
          cout << n << '\n';
          break;
        }
        n++;
      }
    }
  }
}
