#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n == 1) {
      cout << 1 << endl;
    } else {
      double c = cbrt(n);
      int s = sqrt(n);
      int cb = cbrt(n);
      int six = sqrt(c);
      cout << s << " " << cb << " " << six << endl;
      cout << (s + cb - six) << endl;
    }
  }
  return 0;
}
