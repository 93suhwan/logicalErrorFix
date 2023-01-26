#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b + c) % 2 == 0) {
      cout << 0 << '\n';
    } else {
      cout << 1 << '\n';
    }
  }
  return 0;
}
