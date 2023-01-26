#include <bits/stdc++.h>
using namespace std;
int n, p;
double P;
int ck(int x) {
  int y = n - x, d[4];
  d[0] = y * (y - 1) * (y - 2) / 6;
  d[1] = y * (y - 1) / 2 * x;
  d[2] = y * x * (x - 1) / 2;
  d[3] = x * (x - 1) * (x - 2) / 6;
  return d[3] + d[2] + d[1] / 3;
}
int main() {
  cin >> n >> P;
  P = P * n * (n - 1) * (n - 2) / 6;
  p = (int)(P - 1e-5);
  for (int i = 0; i < n; i++)
    if (ck(i) > p) {
      cout << i;
      return 0;
    }
  return 0;
}
