#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n < 0)
      cout << 0 << endl;
    else if (0 < n < 10)
      cout << 1 << endl;
    else
      cout << (n / 10) << endl;
  }
  return 0;
}
