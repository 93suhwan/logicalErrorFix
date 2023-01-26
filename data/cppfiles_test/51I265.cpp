#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n == 1)
      cout << "0 1\n";
    else {
      cout << -(n - 1) << " " << n << "\n";
    }
  }
  return 0;
}
