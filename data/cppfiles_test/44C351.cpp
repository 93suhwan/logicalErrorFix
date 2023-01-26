#include <bits/stdc++.h>
using namespace std;
int t;
long long a, b;
int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (abs(a - b) % 2 == 1)
      cout << -1 << endl;
    else {
      if (a == b)
        if (a == 0)
          cout << 0 << endl;
        else
          cout << 1 << endl;
      else
        cout << "2" << endl;
    }
  }
  return 0;
}
