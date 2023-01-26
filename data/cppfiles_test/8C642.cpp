#include <bits/stdc++.h>
using namespace std;
void Solve() {
  int n;
  cin >> n;
  int tmp = n / 3;
  cout << (tmp + ((n % 3) == 1)) << " " << tmp + ((n % 3) == 2) << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    Solve();
  }
  return 0;
}
