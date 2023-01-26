#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    if (a + b == c || a == b && c % 2 == 0 || b == c && a % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
