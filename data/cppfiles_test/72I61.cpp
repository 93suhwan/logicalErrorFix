#include <bits/stdc++.h>
using namespace std;
int mx = 6;
map<pair<int, int>, int> mp;
int ask(int a, int b) {
  if (mp.count({a, b})) return mp[{a, b}];
  cout << "? " << a << ' ' << b << endl;
  int x;
  cin >> x;
  return mp[{a, b}] = x;
}
int main() {
  int in = ask(1, 1);
  int w = 1;
  for (int j = 33; j >= 0; j--) {
    long long len = (1LL << j);
    if (w + len <= mx) {
      int g = ask(w + len, 1);
      if (in - g == len) {
        w += len;
        in = g;
      }
    }
  }
  cout << "in"
       << ": " << in << endl;
  ;
  int e, f, g, h;
  e = in;
  f = ask(1, e + 1);
  g = ask(mx, e + 1);
  h = ask(mx - g, mx);
  cout << "! " << f + 1 << ' ' << e + 1 << ' ' << mx - g << ' ' << mx - h
       << endl;
}
