#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int base = 2333;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int s = 0;
    if (c & 1) {
      s = 3;
      if (b) b--, s -= 2;
    }
    if (b & 1) {
      if (!s) s = 2;
    }
    if (s == 2) {
      if (a) {
        if (a % 2 == 0)
          cout << 0 << endl;
        else
          cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    } else if (s == 1) {
      if (a & 1)
        cout << 0 << endl;
      else
        cout << 1 << endl;
    } else if (s == 0) {
      if (a & 1)
        cout << 1 << endl;
      else
        cout << 0 << endl;
    }
  }
}
