#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int x, n;
    cin >> x >> n;
    if (n == 0) {
      cout << x << endl;
    } else if (x % 2 == 0) {
      long long int f = (n / 4);
      long long int r = (n % 4);
      if (r == 0) {
        cout << x << endl;
      } else if (r == 1) {
        cout << x - 4 * f - 1 << endl;
      } else if (r == 2) {
        cout << x - (4 * f + 1) + (4 * f + 2) << endl;
      } else if (r == 3) {
        cout << x - (4 * f + 1) + (4 * f + 2) + (4 * f + 3) << endl;
      }
    } else {
      long long int f = (n / 4);
      long long int r = (n % 4);
      if (r == 0) {
        cout << x << endl;
      } else if (r == 1) {
        cout << x + 4 * f + 1 << endl;
      } else if (r == 2) {
        cout << x + (4 * f + 1) - (4 * f + 2) << endl;
      } else if (r == 3) {
        cout << x + (4 * f + 1) - (4 * f + 2) - (4 * f + 3) << endl;
      }
    }
  }
}
