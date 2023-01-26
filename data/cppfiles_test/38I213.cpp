#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10, maxq = 100 + 2, mad = 1e9 + 7;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    n = ceil(n / 2.0);
    n *= 5;
    cout << n << "\n";
  }
}
