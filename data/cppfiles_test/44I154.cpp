#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long c, d;
    cin >> c >> d;
    if (abs(c - d) % 2 != 0) {
      cout << -1 << endl;
    } else if (c == d && c == 0) {
      cout << 0 << endl;
    } else if (abs(c) == abs(d) && c != 0) {
      cout << 1 << endl;
    } else if (((c > 0 && d < 0) || (c < 0 && d > 0)) && abs(c) != abs(d)) {
      if (c > d) {
        if (abs(c) > abs(d)) {
          cout << 2 << endl;
        } else {
          cout << -1 << endl;
        }
      }
      if (c < d) {
        if (abs(c) < abs(d)) {
          cout << 2 << endl;
        } else {
          cout << -1 << endl;
        }
      } else {
        cout << 2 << endl;
      }
    }
  }
}
