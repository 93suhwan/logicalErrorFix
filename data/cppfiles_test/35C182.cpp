#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    int x = 0;
    for (int b = 30; b >= 0; b--) {
      int y = x + (1 << b) - 1;
      if ((n | y) <= m) {
        x += (1 << b);
      }
    }
    cout << x << '\n';
  }
  return 0;
}
