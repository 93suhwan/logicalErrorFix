#include <bits/stdc++.h>
using namespace std;
int n, A[207171];
int cost(int a, int b) {
  a = A[a];
  b = A[b];
  int r = 0, p2 = 1;
  while (p2 < a || p2 < b) p2 <<= 1;
  while (a != b) {
    if (a > b) swap(a, b);
    while ((p2 >> 1) >= b) p2 >>= 1;
    b = p2 - b;
    ++r;
  }
  return r;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> A[i];
  int pm, cm = -1, v, ppm;
  for (int i = 2; i <= n; ++i)
    if ((v = cost(1, i)) > cm) cm = v, pm = i;
  cm = -1;
  for (int i = 1; i <= n; ++i)
    if ((v = cost(i, pm)) > cm) cm = v, ppm = i;
  cout << pm << " " << ppm << " " << cm;
  return 0;
}
