#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d = 4;
    cin >> a >> b;
    while (d--) {
      cin >> c;
    }
    cin >> c;
    c = c - a - b;
    cout << a << " " << b << " " << c << "\n";
  }
}
