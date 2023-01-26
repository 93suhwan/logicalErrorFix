#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 5) {
      cout << "2"
           << " "
           << "4"
           << "\n";
    } else
      cout << 2 << " " << n / 2 << "\n";
  }
  return 0;
}
