#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
int _, n;
int main() {
  cin >> _;
  while (_--) {
    cin >> n;
    int x = n / 3;
    int y = n / 3;
    int z = n % 3;
    if (n % 3 == 1)
      x++;
    else if (n % 3 == 2)
      y++;
    cout << x << " " << y << '\n';
  }
}
