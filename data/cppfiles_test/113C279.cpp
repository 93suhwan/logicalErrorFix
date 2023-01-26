#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x1, p1, x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    double f = log10((double)x1 / x2);
    if (f > p2 - p1)
      cout << '>' << "\n";
    else if (f < p2 - p1)
      cout << '<' << "\n";
    else
      cout << '=' << "\n";
  }
  return 0;
}
