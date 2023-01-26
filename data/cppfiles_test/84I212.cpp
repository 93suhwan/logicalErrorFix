#include <bits/stdc++.h>
using namespace std;
int t, N;
int main() {
  cin >> t;
  while (t-- > 0) {
    int a, b;
    cin >> a >> b;
    int x = b / a;
    int y = b % a;
    if (b % 2 == 1) {
      if (b % a > b / 2) {
        cout << (x + 1);
      } else {
        cout << x;
      }
    } else {
      if (b % a >= b / 2) {
        cout << (x + 1);
      } else {
        cout << x;
      }
    }
    cout << "\n";
  }
}
