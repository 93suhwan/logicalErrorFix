#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int x;
    cin >> x;
    if (x == 9)
      cout << 1 << endl;
    else
      cout << x / 10 << endl;
  }
}
