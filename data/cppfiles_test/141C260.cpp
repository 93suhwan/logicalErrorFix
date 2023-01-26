#include <bits/stdc++.h>
using namespace std;
long long a, s;
void solve() {
  vector<int> b;
  while (s) {
    int x = a % 10;
    int y = s % 10;
    a /= 10;
    s /= 10;
    if (x <= y)
      b.push_back(y - x);
    else {
      y += (s % 10) * 10;
      s /= 10;
      if (x < y && y >= 10 && y <= 18) {
        b.push_back(y - x);
      } else {
        cout << -1 << endl;
        return;
      }
    }
  }
  if (a)
    cout << -1 << endl;
  else {
    while (!b.back()) b.pop_back();
    for (vector<int>::iterator it = b.end() - 1; it >= b.begin(); it--) {
      cout << *it;
    }
    cout << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> s;
    solve();
  }
  return 0;
}
