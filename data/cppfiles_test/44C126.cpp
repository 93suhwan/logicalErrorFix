#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, d, c;
  cin >> t;
  while (t--) {
    long long d, c;
    cin >> d >> c;
    if ((c + d) % 2)
      cout << -1 << endl;
    else if (c == d)
      cout << !(c == 0) << endl;
    else
      cout << 2 << endl;
  }
}
