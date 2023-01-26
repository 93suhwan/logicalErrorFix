#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long c, d;
    cin >> c >> d;
    if (c == 0 && d == 0) {
      cout << 0 << "\n";
      continue;
    }
    if (c == d) {
      cout << 1 << "\n";
      continue;
    }
    if (abs(c - d) % 2 == 0) {
      cout << 2 << "\n";
    } else {
      cout << "-1\n";
    }
  }
}
