#include <bits/stdc++.h>
using namespace std;
long long n, p, i, j, d, c, b, r, a1, a2, a3, x, a, k;
string s, m;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a >> b >> c;
    if (a + b == c)
      cout << "YES" << endl;
    else if (a + c == b)
      cout << "YES" << endl;
    else if (b + c == a)
      cout << "YES" << endl;
    else if (a == b && c % 2 == 0)
      cout << "YES" << endl;
    else if (a == c && b % 2 == 0)
      cout << "YES" << endl;
    else if (b == c && a % 2 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
