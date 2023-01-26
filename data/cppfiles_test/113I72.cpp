#include <bits/stdc++.h>
using namespace std;
long long f(int x) {
  if (x == 0) return 1LL;
  if (x == 1) return 10 * 1LL;
  long long a = f(x / 2);
  if (x & 1) return 10 * 1LL * a * a;
  return a * 1LL * a;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x1, x2, p1, p2;
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
