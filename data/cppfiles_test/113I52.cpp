#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0);
  vector<double> t(1000000 + 10, 0.0);
  t[0] = 1;
  t[1] = 10;
  for (int i = 2; i <= 1000000; i++) t[i] = t[i - 1] * 10;
  int T;
  cin >> T;
  while (T--) {
    int x1, p1;
    int x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    double t1 = (double)x1 * t[p1];
    double t2 = (double)x2 * t[p2];
    if (t1 == t2)
      cout << "=\n";
    else if (t1 < t2)
      cout << "<\n";
    else
      cout << ">\n";
  }
  return 0;
}
