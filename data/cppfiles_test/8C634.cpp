#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  ios_base::sync_with_stdio(false);
  ;
  cin.tie(NULL);
  ;
  long long tc;
  cin >> tc;
  while (tc--) {
    long long n;
    cin >> n;
    long long c1, c2;
    if (n == 3) {
      c1 = n / 3;
      c2 = n / 3;
      cout << c1 << " " << c2 << endl;
    }
    if (n == 2) {
      c1 = 0;
      c2 = 1;
      cout << c1 << " " << c2 << endl;
    }
    if (n == 1) {
      c1 = 1;
      c2 = 0;
      cout << c1 << " " << c2 << endl;
    }
    if (n == 0) {
      c1 = 0;
      c2 = 0;
      cout << c1 << " " << c2 << endl;
    }
    if (n % 3 == 0 && n > 3) {
      c1 = n / 3;
      c2 = n / 3;
      cout << c1 << " " << c2 << endl;
    }
    if (n % 3 == 1 && n > 3) {
      c1 = n / 3 + 1;
      c2 = n / 3;
      cout << c1 << " " << c2 << endl;
    } else if (n % 3 == 2 && n > 3) {
      c1 = n / 3;
      c2 = n / 3 + 1;
      cout << c1 << " " << c2 << endl;
    }
  }
  return 0;
}
