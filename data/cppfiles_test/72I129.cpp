#include <bits/stdc++.h>
using namespace std;
int ask(int i, int j) {
  cout << "? " << i << " " << j << endl;
  int n;
  cin >> n;
  return n;
}
int N = 1e9;
signed main() {
  int d1 = ask(1, N);
  int d2 = ask(N, N);
  int ym = 1 + (N - 1 - d1 + d2) / 2;
  int d3 = ask(N, ym);
  int p = N - d3;
  int q = N - d2 + d3;
  int d4 = ask(p, 1);
  int y = 1 + d4;
  int x = 1 + ask(1, q);
  cout << "! " << x << " " << y << " " << p << " " << q << endl;
}
