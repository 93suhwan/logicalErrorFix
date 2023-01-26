#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
  if (y == 0) {
    return x;
  }
  return gcd(y, x % y);
}
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto& x : v) {
    cin >> x;
  }
  int g = 0;
  for (int i = 0; i < 30; ++i) {
    int k = (1 << i);
    int c = 0;
    for (auto x : v) {
      if (x & k) {
        ++c;
      }
    }
    g = gcd(g, c);
  }
  int a = 0;
  for (int i = 1; i <= n; ++i) {
    if (g % i == 0) {
      ++a;
    }
  }
  cout << a << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
