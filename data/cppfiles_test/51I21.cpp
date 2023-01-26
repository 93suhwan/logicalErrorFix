#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n == 1)
      cout << "0"
           << " " << n << endl;
    else if (n == 2)
      cout << "0"
           << " " << n << endl;
    else
      cout << "1"
           << " " << n - 1 << endl;
  }
  return 0;
}
