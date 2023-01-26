#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  unsigned long long a, b, zs, os;
  for (int k = 0; k < n; k++) {
    zs = 0, os = 0;
    cin >> a;
    for (int i = 0; i < a; i++) {
      cin >> b;
      if (b == 0) {
        zs++;
      } else if (b == 1) {
        os++;
      }
    }
    for (unsigned long long i = 0; i < zs; i++) {
      os *= 2;
    }
    cout << os;
    if (k != n - 1) {
      cout << "\n";
    }
  }
}
