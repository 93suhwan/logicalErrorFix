#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long x = ceil(sqrt(n));
    long long y = x - 1;
    long long sum = y * ((2 + ((y - 1) * 2)) / 2);
    if (n - sum <= x) {
      cout << (n - sum) << " " << x << "\n";
    } else
      cout << x << " " << x - (n - (sum + x)) << "\n";
  }
}
