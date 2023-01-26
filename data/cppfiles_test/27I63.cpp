#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int upper = (n * (n - 1)) / 2;
    if (m > (n * (n - 1)) / 2 || (k == 1)) {
      cout << "NO\n";
    } else if (m != upper && k <= 3) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}
