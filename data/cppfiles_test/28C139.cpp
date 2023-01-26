#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long k = a + 2 * b + 3 * c;
    cout << k % 2 << endl;
  }
  return 0;
}
