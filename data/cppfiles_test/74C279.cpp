#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
void solve() {
  int a, b;
  cin >> a >> b;
  int p = (a + b) / 2 + (a + b) % 2;
  int q = (a + b) / 2;
  set<int> s;
  for (int i = 0; i <= p; i++) {
    int y = a - (p - i);
    if (y >= 0 && y <= q) {
      s.insert(i + y);
    }
  }
  for (int i = 0; i <= q; i++) {
    int y = a - (q - i);
    if (y >= 0 && y <= p) {
      s.insert(i + y);
    }
  }
  cout << s.size() << '\n';
  for (int x : s) {
    cout << x << ' ';
  }
}
int main() {
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
    cout << '\n';
  }
}
