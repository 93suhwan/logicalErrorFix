#include <bits/stdc++.h>
using namespace std;
int t, a, b, c;
int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    if (b % a != 0 && b < a * 2 || a == b || c > b) {
      cout << "-1\n";
      continue;
    }
    if (c - (b - a) <= 0)
      cout << c + (b - a) << "\n";
    else
      cout << c - (b - a) << "\n";
  }
}
