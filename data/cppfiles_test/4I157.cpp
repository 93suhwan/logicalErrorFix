#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long P;
    cin >> P;
    if (P == 6) {
      cout << 2 << " " << 3 << endl;
    } else if (P % 2 == 0) {
      cout << P - 2 << " " << (P - 2) / 2 << endl;
    } else {
      cout << P - 1 << " " << (P - 1) / 2 << endl;
    }
  }
  return 0;
}
