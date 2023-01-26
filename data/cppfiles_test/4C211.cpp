#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int n;
  while (t--) {
    cin >> n;
    if (n == 2)
      cout << 1 << " " << 1 << endl;
    else
      cout << 2 << " " << n - 1 << endl;
  }
}
