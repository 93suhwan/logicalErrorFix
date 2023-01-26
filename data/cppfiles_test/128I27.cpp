#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 2 == 0)
      cout << n / 2 << " " << n / 2 - 1 << " "
           << "1\n";
    else {
      if (n % 3 == 0 || n % 3 == 0)
        cout << (n / 3) * 2 - 1 << " " << n / 3 << " " << 1 << endl;
      else
        cout << (n / 3) * 2 - 1 << " " << n / 3 + 1 << " " << 1 << endl;
    }
  }
  return 0;
}
