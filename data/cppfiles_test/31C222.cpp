#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  if (n % 2 == 1) {
    int x, y, z;
    cin >> x >> y >> z;
    n -= 3;
    if (x + y != 0)
      printf("%d %d %d ", -z, -z, x + y);
    else if (x + z != 0)
      printf("%d %d %d ", -y, x + z, -y);
    else
      printf("%d %d %d ", z + y, -x, -x);
  }
  while (n > 0) {
    int a, b;
    cin >> a >> b;
    printf("%d %d ", -b, a);
    n -= 2;
  }
  cout << endl;
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) solve();
}
