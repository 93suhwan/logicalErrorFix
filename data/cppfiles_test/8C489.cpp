#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if ((int)ceil(n / 3.0) * 2 + n / 3 == n)
      cout << n / 3 << ' ' << (int)ceil(n / 3.0) << endl;
    else
      cout << (int)ceil(n / 3.0) << ' ' << n / 3 << endl;
  }
  return 0;
}
