#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long b[3];
    for (long long i = 0; i < 3; i++) {
      cin >> b[i];
    }
    sort(b, b + 3);
    if ((b[0] + b[1]) == b[2])
      cout << "YES" << endl;
    else if ((b[1] == b[2]) && b[0] % 2 == 0)
      cout << "YES" << endl;
    else if ((b[0] == b[1]) && b[2] % 2 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
