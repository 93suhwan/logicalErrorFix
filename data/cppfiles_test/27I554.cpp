#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    long long int upper = (n * (n - 1)) / 2;
    if (m > upper || (k == 1)) {
      cout << "NO\n";
    } else if (m < upper && k <= 3) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}
