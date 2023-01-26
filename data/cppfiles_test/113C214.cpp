#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-8;
int sgn(long double x) {
  if (x < -eps)
    return -1;
  else if (x > eps)
    return 1;
  else
    return 0;
}
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int x1, p1;
    int x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    long double t1 = x1;
    while (sgn(t1 - 10) >= 0) t1 /= 10, p1++;
    long double t2 = x2;
    while (sgn(t2 - 10) >= 0) t2 /= 10, p2++;
    if (p1 < p2)
      cout << "<\n";
    else if (p1 > p2)
      cout << ">\n";
    else {
      int flag = sgn(t1 - t2);
      if (flag == 1)
        cout << ">\n";
      else if (flag == 0)
        cout << "=\n";
      else
        cout << "<\n";
    }
  }
  return 0;
}
