#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n, b, x;
    cin >> n;
    if (n == 1 || n == 2) {
      if (n == 1) {
        x = 1;
        b = 0;
      } else {
        x = 0;
        b = 1;
      }
    } else if (n % 2 == 0) {
      if (n % 3 == 0) {
        x = (int)n / 3;
        b = (int)n / 3;
      } else {
        x = (int)n / 3;
        if ((n - x) % 2 == 0) {
          x = (int)n / 3;
          b = (n - x) / 2;
        } else {
          x = (int)n / 3;
          x += 1;
          b = (n - x) / 2;
        }
      }
    } else {
      x = (int)n / 3;
      b = (int)((n - x) / 2);
    }
    cout << x << " " << b << endl;
  }
  return 0;
}
