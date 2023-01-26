#include <bits/stdc++.h>
using namespace std;
int a[10005];
int getsum(int q, int r) {
  cout << "and " << q << " " << r << endl;
  int p, t;
  cin >> p;
  cout << "or " << q << " " << r << endl;
  cin >> t;
  return p + t;
}
int main() {
  int n, k;
  cin >> n >> k;
  int x = getsum(1, 2), y = getsum(2, 3), z = getsum(1, 3);
  int s = (x + y + z) / 2;
  a[1] = s - y, a[2] = s - z, a[3] = s - x;
  for (int i = 4; i <= n; i++) {
    a[i] = getsum(1, i) - a[1];
  }
  sort(a + 1, a + n + 1);
  cout << a[k];
  return 0;
}
