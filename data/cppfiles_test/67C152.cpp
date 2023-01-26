#include <bits/stdc++.h>
using namespace std;
void init() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void solve() {
  long long int a, b, c;
  cin >> a >> b >> c;
  if (abs(a - b) <= 1) {
    cout << "-1" << endl;
    return;
  }
  if (true) {
    long long int diff = abs(a - b);
    long long int n = diff * 2;
    if (c > n or a > n or b > n) {
      cout << "-1" << endl;
      return;
    } else {
      long long int x = c + diff;
      if (x > n) x %= n;
      cout << x << endl;
      return;
    }
  }
}
int main() {
  init();
  long long int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
