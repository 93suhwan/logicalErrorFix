#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int x;
    cin >> x;
    if (x % 3)
      cout << x / 3 + 1 << " " << x / 3 << endl;
    else
      cout << x / 3 << " " << x / 3 << endl;
  }
  return 0;
}
