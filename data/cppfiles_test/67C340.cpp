#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long a[N], b[N];
vector<long long> v;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c, q;
    cin >> a >> b >> c;
    if (b > a) swap(a, b);
    if (b > a / 2)
      cout << "-1\n";
    else {
      long long as = a - b;
      if (c > as * 2)
        cout << "-1\n";
      else if ((c - as <= 0) && (c + as > as * 2))
        cout << "-1\n";
      else if (c - as > 0)
        cout << c - as << "\n";
      else if (c + as <= as * 2)
        cout << c + as << "\n";
    }
  }
}
