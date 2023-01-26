#include <bits/stdc++.h>
using namespace std;
void f() {
  int n, m, k, p;
  cin >> n >> m >> k;
  p = (n * m) / 2 - k;
  if (n % 2) {
    k -= (m / 2);
    if (k < 0)
      cout << "NO" << endl;
    else if (k % 2)
      cout << "NO" << endl;
    else if (k % 2 == 0)
      cout << "YES" << endl;
  } else if (m % 2) {
    p -= (n / 2);
    if (p < 0)
      cout << "NO" << endl;
    else if (p % 2)
      cout << "NO" << endl;
    else if (p % 2 == 0)
      cout << "YES" << endl;
  } else if (n % 2 == 0 && m % 2 == 0) {
    if (k % 2 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) f();
  return 0;
}
