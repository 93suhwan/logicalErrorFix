#include <bits/stdc++.h>
using namespace std;
int n = 1e9;
unordered_map<int, int> mp;
int main() {
  cout << "? 1 1" << endl;
  int k1, k2;
  cin >> k1;
  cout << "? " << n << " " << n << endl;
  cin >> k2;
  int x = 0, p = 1, pp;
  long long temp = 1e18;
  mp[1] = k1;
  while (p) {
    int o = min(n, x + p);
    if (!mp[o]) {
      cout << "? " << o << " 1" << endl;
      cin >> pp;
      mp[o] = pp;
    } else {
      pp = mp[o];
    }
    if (pp > temp) {
      p /= 2;
    } else {
      x += p;
      p *= 2;
      temp = pp;
    }
  }
  int k = 2 * n - k1 - k2 - 2;
  int y1 = temp + 1, x1 = k1 + 2 - y1;
  int x2 = x, y2 = k - (x - x1) + y1;
  cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  return 0;
}
