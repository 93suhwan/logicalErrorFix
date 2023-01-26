#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int n = s.length();
    if (n == 1)
      cout << a << " " << b << "\n";
    else if (n > 1 && a == b)
      cout << a - 1 << " " << b - 2 << "\n";
    else
      cout << a - 1 << " " << b << "\n";
  }
  return 0;
}
