#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    if (n == 0)
      cout << -1 << " " << 1 << "\n";
    else if (n > 0)
      cout << 1 - n << " " << n << "\n";
    else
      cout << n << " " << -1 - n << "\n";
  }
  return 0;
}
