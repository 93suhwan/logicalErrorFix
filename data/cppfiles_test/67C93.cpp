#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
double n, p;
double C(int a, int b) {
  if (a < b) return 0;
  double res = 1;
  for (int i = a, j = 1; j <= b; i--, j++) res = res * i / j;
  return res;
}
int main() {
  cin >> n >> p;
  for (int i = 0; i < n; i++)
    if (C(i, 3) + C(i, 2) * C(n - i, 1) + 1 / 2.0 * C(i, 1) * C(n - i, 2) -
            C(n, 3) * p >=
        -1e-6) {
      cout << i << endl;
      break;
    }
  return 0;
}
