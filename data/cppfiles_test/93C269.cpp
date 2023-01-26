#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  for (long long int i = 0; i < t; i++) {
    long long int a, b;
    cin >> a >> b;
    long long int x = 0;
    long long int d = a - 1;
    if (d % 4 == 0) x = d;
    if (d % 4 == 1) x = 1;
    if (d % 4 == 2) x = d + 1;
    if (d % 4 == 3) x = 0;
    if (x == b)
      cout << a << "\n";
    else if ((x ^ b) != a)
      cout << a + 1 << "\n";
    else
      cout << a + 2 << "\n";
  }
  return 0;
}
