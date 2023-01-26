#include <bits/stdc++.h>
using namespace std;
int ask(int a, int b) {
  cout << "? " << a << ' ' << b << endl;
  int x;
  cin >> x;
  return x;
}
int main() {
  int low = 1, high = 1e9;
  int got = 2e9;
  while (low <= high) {
    int mid1 = low + (high - low) / 3;
    int mid2 = high - (high - low) / 3;
    int u = ask(mid1, 1);
    int v = ask(mid2, 1);
    got = min(u, v);
    if (u > v) {
      low = mid1 + 1;
    } else if (u < v) {
      high = mid2 - 1;
    } else {
      low = mid1 + 1;
      high = mid2 - 1;
    }
  }
  int mx = 1e9;
  int e, f, g, h;
  e = got;
  f = ask(1, e);
  g = ask(mx, e);
  h = ask(mx - g, mx);
  cout << "! " << f << ' ' << e << ' ' << mx - g << ' ' << mx - h << endl;
}
