#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long tn = abs(a - b) * 2;
    if (a > tn || b > tn || c > tn) {
      cout << -1 << "\n";
    } else {
      if (c > (tn / 2)) {
        cout << (c - (tn / 2)) << "\n";
      } else {
        cout << (c + (tn / 2)) << "\n";
      }
    }
  }
}
