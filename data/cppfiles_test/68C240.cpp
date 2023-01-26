#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, z, i, j;
    cin >> n;
    z = sqrt(n - 1);
    long long int x = (z + 1) * (z + 1) - z * z;
    z = z * z;
    if (z + x / 2 >= n) {
      i = n - z;
      j = sqrt(z) + 1;
    } else {
      i = sqrt(z) + 1;
      j = x - (n - z) + 1;
    }
    cout << i << " " << j;
    cout << "\n";
  }
}
