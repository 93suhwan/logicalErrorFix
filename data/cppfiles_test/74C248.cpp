#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--) {
    int a, b;
    cin >> a >> b;
    set<int> s;
    int p = (a + b + 1) / 2, q = (a + b) / 2;
    for (int x = 0; x <= p; x++) {
      int y = x + a - p;
      if (y >= 0 && y <= q) s.insert(x + y);
    }
    q = (a + b + 1) / 2;
    p = (a + b) / 2;
    for (int x = 0; x <= p; x++) {
      int y = x + a - p;
      if (y >= 0 && y <= q) s.insert(x + y);
    }
    cout << s.size() << "\n";
    for (auto &x : s) cout << x << " ";
    cout << "\n";
  }
  return 0;
}
