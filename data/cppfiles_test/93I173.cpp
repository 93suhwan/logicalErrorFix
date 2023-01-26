#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int x = 0;
    for (int i = 1; i < a; i++) x = x ^ i;
    cout << "x= " << x << "\n";
    if (x == b)
      cout << a << "\n";
    else if ((x ^ b) != a)
      cout << a + 1 << "\n";
    else
      cout << a + 2 << "\n";
  }
}
