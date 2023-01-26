#include <bits/stdc++.h>
using namespace std;
double C(int a, int b) {
  double ans = 1;
  for (double i = 1; i <= b; ++i) {
    ans *= (i + a - b);
    ans /= i;
  }
  return ans;
}
int main() {
  int n;
  double p;
  cin >> n >> p;
  for (int x = 0; x <= n; ++x) {
    if (C(x, 3) + C(n - x, 1) * C(x, 2) + C(n - x, 2) * C(x, 1) * 0.5 >=
        p * C(n, 3)) {
      cout << x << endl;
      return 0;
    }
  }
}
