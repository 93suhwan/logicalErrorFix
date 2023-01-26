#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, j;
  long long n;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n < 6)
      cout << 15 << endl;
    else
      cout << (n + 1) / 2 * 5 << endl;
  }
  return 0;
}
