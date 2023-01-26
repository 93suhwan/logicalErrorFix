#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n == 1)
      cout << 0 << " " << 1 << endl;
    else
      cout << "-" << n - 1 << " " << n << endl;
  }
  return 0;
}
