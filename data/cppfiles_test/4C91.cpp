#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  long long n;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n / 2 == 2) {
      cout << 2 << " " << 4 << "\n";
    } else
      cout << 2 << " " << n / 2 << "\n";
  }
}
