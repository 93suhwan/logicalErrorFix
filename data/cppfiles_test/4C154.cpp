#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long p;
    cin >> p;
    if (p % 2 == 0) {
      cout << 2 << " " << p / 2 << "\n";
    } else {
      cout << (p - 1) / 2 << " " << p - 1 << "\n";
    }
  }
}
