#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;
    cout << a << " " << b << " " << g - (a + b) << "\n";
  }
  return 0;
}
