#include <bits/stdc++.h>
using namespace std;
void Pagla() {
  int i, j;
  long long int a, b;
  cin >> a >> b;
  if (b / 2 >= a) {
    long long int ak = ceil(b * 1.00 / 2);
    long long int mx = 0;
    mx = max(mx, b % ak);
    while (1) {
      if (b % ak != 0) {
        break;
      }
      mx = max(mx, b % ak);
      ak++;
      if (ak >= b) {
        cout << mx << "\n";
        return;
      }
    }
    cout << max(mx, b % ak) << "\n";
  } else {
    if (b % a != 0) {
      cout << b % a << "\n";
    } else {
      if (a != 1)
        cout << b % (a - 1) << "\n";
      else
        cout << b % a << "\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    Pagla();
  }
  return 0;
}
