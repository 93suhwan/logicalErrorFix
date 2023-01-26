#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int t;
  cin >> t;
  double n;
  while (t--) {
    cin >> n;
    int k = round(n / 3);
    cout << int(n) - (k * 2) << " " << k << endl;
  }
  return 0;
}
