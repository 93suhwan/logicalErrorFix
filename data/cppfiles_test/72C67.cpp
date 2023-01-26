#include <bits/stdc++.h>
using namespace std;
const int N = 1e9;
int ask(int i, int j) {
  cout << "? " << i << ' ' << j << endl;
  cout.flush();
  int r;
  cin >> r;
  return r;
}
int main() {
  int l = ask(1, 1);
  int r = ask(1, N);
  int m = (N + 1 + l - r) / 2;
  int x = 1 + ask(1, m);
  int p = N - ask(N, m);
  int u = l;
  int d = ask(N, 1);
  m = (N + 1 + u - d) / 2;
  int y = 1 + ask(m, 1);
  int q = N - ask(m, N);
  cout << "! " << x << ' ' << y << ' ' << p << ' ' << q << endl;
  cout.flush();
}
