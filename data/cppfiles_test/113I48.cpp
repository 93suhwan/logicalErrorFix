#include <bits/stdc++.h>
using namespace std;
int f(int x) {
  if (x == 0) return 1;
  int a = f(x / 2);
  if (x & 1) return 10 * a * a;
  return a * a;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x1, x2, p1, p2;
    cin >> x1 >> p1;
    cin >> x2 >> p2;
    long long a = x1 * 1LL * f(p1);
    long long b = x2 * 1LL * f(p2);
    if (a < b)
      cout << "<" << endl;
    else if (a == b)
      cout << "=" << endl;
    else
      cout << ">" << endl;
  }
  return 0;
}
