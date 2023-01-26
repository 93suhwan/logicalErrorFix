#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int x = sqrt(n);
    long long int y = cbrt(n);
    long long int z = cbrt(sqrt(n));
    cout << x + y - z << endl;
  }
  return 0;
}
