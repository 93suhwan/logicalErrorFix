#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long p;
    cin >> p;
    if (p == 5)
      cout << 2 << " " << 4 << endl;
    else {
      cout << 2 << " " << (p - 1) / 2 << endl;
    }
  }
}
