#include <bits/stdc++.h>
using namespace std;
int t;
long long x, y, k, l;
int main() {
  cin >> t;
  while (t--) {
    cin >> x >> k >> y >> l;
    long long z = min(k, l);
    k -= z;
    l -= z;
    if (k >= 7)
      cout << ">\n";
    else if (l >= 7)
      cout << "<\n";
    else {
      for (int i = 0; i < k; i++) x *= 10;
      for (int i = 0; i < l; i++) y *= 10;
      if (x > y)
        cout << ">\n";
      else if (x == y)
        cout << "=\n";
      else
        cout << "<\n";
    }
  }
  return 0;
}
