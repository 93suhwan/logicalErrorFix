#include <bits/stdc++.h>
using namespace std;
int n;
double p;
double f(int x) {
  double res = 0;
  res = res + (x * (x - 1) * (x - 2) / 6) * 1.0;
  res = res + (x * (x - 1) / 2) * (n - x) * 1.0;
  res = res + x * ((n - x) * (n - x - 1) / 2) * 0.5;
  return res;
}
int main() {
  cin >> n >> p;
  p = p * (n * (n - 1) * (n - 2) / 6) * 1.0;
  for (int i = 0; i <= n; i++)
    if (f(i) >= p) {
      cout << i << endl;
      return 0;
    }
}
