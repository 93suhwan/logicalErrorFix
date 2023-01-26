#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int b = n / 3;
    int r = n % 3;
    if (r == 0)
      cout << b << " " << b << endl;
    else if (r == 1)
      cout << b + 1 << " " << b << endl;
    else
      cout << b << " " << b + 1 << endl;
  }
  return 0;
}
