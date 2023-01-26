#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    double n, s;
    cin >> n >> s;
    int m = ceil(n / 2);
    cout << int(s / (n - m + 1)) << "\n";
  }
  return 0;
}
