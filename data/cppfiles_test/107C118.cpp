#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int n, m, t, q, a, b, c, h, d, x, y, z, i, j, k,
      ans = 0, ans2 = 0, cur = 0, cur2 = 0, sum = 0, sum2 = 0, maxn;
  string str = "", str2, str3;
  cin >> t;
  while (t--) {
    cin >> n >> x >> y;
    if (abs(x - y) > 1) {
      cout << "-1\n";
      continue;
    } else if (x + y > n - 2) {
      cout << "-1\n";
      continue;
    }
    a = 1;
    b = n;
    if (x == y) {
      cout << "1 ";
      a++;
      for (i = 0; i < x; i++) {
        cout << b << " " << a << " ";
        a++;
        b--;
      }
      for (i = a; i <= b; i++) cout << i << " ";
      cout << "\n";
    } else if (x > y) {
      for (i = 0; i < x; i++) {
        cout << a << " " << b << " ";
        a++;
        b--;
      }
      for (i = b; i >= a; i--) cout << i << " ";
      cout << "\n";
    } else {
      for (i = 0; i < y; i++) {
        cout << b << " " << a << " ";
        a++;
        b--;
      }
      for (i = a; i <= b; i++) cout << i << " ";
      cout << "\n";
    }
  }
}
