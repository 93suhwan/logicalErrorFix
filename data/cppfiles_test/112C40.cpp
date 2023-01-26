#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c, m;
    cin >> a >> b >> c >> m;
    long long ar[3] = {a, b, c};
    sort(ar, ar + 3);
    for (int i = 0; i <= 100000000; i++) {
    }
    if (m > (a - 1 + b - 1 + c - 1)) {
      cout << "NO\n";
    } else {
      long long l = ar[2] - (ar[1] + ar[0] + 1);
      if (m >= l) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}
