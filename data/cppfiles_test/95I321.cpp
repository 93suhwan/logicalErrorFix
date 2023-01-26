#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, s;
    cin >> x >> s;
    if (s == 1) {
      cout << x << "\n";
      continue;
    }
    cout << x - s + 1 << " ";
    for (int i = 1; i < s; ++i) cout << 1 << " ";
    cout << "\n";
  }
}
