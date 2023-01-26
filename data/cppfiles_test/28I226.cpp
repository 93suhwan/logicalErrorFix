#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    if ((a % 2 == b % 2) && (a % 2 == c % 2)) {
      cout << 0 << endl;
    } else {
      if (c % 2 == 0) {
        if (a % 2 == 0) {
          if (a > 1)
            cout << 0 << endl;
          else
            cout << 2 << endl;
        } else {
          cout << 1 << endl;
        }
      } else {
        if (a % 2 == 1) {
          if (a > 2)
            cout << 0 << endl;
          else {
            cout << 2 << endl;
          }
        } else {
          if (b % 2 == 0) {
            if (a > 2)
              cout << 1 << endl;
            else
              cout << 1 << endl;
          } else {
            cout << 1 << endl;
          }
        }
      }
    }
  }
  return 0;
}
