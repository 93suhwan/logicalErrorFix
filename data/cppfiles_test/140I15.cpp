#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    n = sqrt(n) + cbrt(n);
    cout << n - 1 << endl;
  }
  return 0;
}
