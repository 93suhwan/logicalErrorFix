#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n > 1)
      cout << "-" << n - 1 << " " << n << "\n";
    else
      cout << n - 1 << " " << n << "\n";
  }
  return 0;
}
