#include <bits/stdc++.h>
using namespace std;
void solve(void) {
  long long a, b, c, m;
  cin >> a >> b >> c >> m;
  long long z = 0;
  long long Max = max(z, a - 1) + max(b - 1, z) + max(c - 1, z);
  long long Min = 0;
  if (max(a, max(b, c)) == a) {
    if (b + c < a) {
      Min = max(z, a - b - c - 1);
    }
  }
  if (max(a, max(b, c)) == b) {
    if (a + c < b) {
      Min = max(b - a - c - 1, z);
    }
  }
  if (max(a, max(b, c)) == c) {
    if (b + a < c) {
      Min = max(c - b - a - 1, z);
    }
  }
  if (m >= Min && m <= Max) {
    cout << "YES"
         << "\n";
    return;
  }
  cout << "NO"
       << "\n";
  return;
  cout << endl;
}
int main(void) {
  int t;
  cin >> t;
  while (t--) solve();
}
