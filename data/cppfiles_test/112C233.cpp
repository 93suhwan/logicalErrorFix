#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c, m;
    cin >> a >> b >> c >> m;
    if (m > (a + b + c - 3))
      cout << "NO" << endl;
    else {
      int l = max(a, max(b, c));
      int x;
      if (l == a) {
        x = max(a - b - c - 1, 0LL);
      } else if (l == b) {
        x = max(b - a - c - 1, 0LL);
      } else {
        x = max(c - a - b - 1, 0LL);
      }
      if (m < x)
        cout << "NO" << endl;
      else {
        cout << "YES" << endl;
      }
    }
  }
}
