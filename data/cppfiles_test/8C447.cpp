#include <bits/stdc++.h>
using namespace std;
void Input_Preparing() {}
void Processing() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 3 == 0) {
      cout << n / 3 << " " << n / 3 << "\n";
    } else {
      int x = n / 3;
      int y = n / 3 + 1;
      if (y + 2 * x == n) swap(x, y);
      cout << x << " " << y << "\n";
    }
  }
}
int main() {
  std::cin.tie(0)->sync_with_stdio(0);
  ;
  Processing();
  return 0;
}
