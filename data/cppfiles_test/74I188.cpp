#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b;
  cin >> a >> b;
  if (a == 0 || b == 0) {
    int p = (a + b) / 2;
    int q = a + b - p;
    if (p == q)
      cout << 1 << endl << p << endl;
    else {
      if (p > q) swap(p, q);
      cout << 2 << endl << p << " " << q << endl;
    }
    return;
  }
  int p = (a + b) / 2;
  int q = a + b - p;
  vector<int> v;
  for (int i = 0; i <= a + b; i++) {
    int t1 = a, t2 = b;
    int y = min(q, b);
    y = min(y, i);
    t1 -= (q - y);
    t2 -= y;
    int z = abs(i - y);
    if (z == t1) {
      v.push_back(i);
    } else {
      t1 = a, t2 = b;
      y = min(q, a);
      y = min(y, i);
      t2 -= (q - y);
      t1 -= y;
      z = abs(i - y);
      if (z == t2) v.push_back(i);
    }
  }
  cout << v.size() << endl;
  for (auto it : v) cout << it << " ";
  cout << endl;
}
int main() {
  int testcase = 1;
  cin >> testcase;
  while (testcase--) solve();
  return 0;
}
