#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10, maxq = 100 + 2, mad = 1e9 + 7;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cout << min(ceil(n / 10.0) * 25,
                min(ceil(n / 6.0) * 15, ceil(n / 8.0) * 20))
         << "\n";
  }
}
