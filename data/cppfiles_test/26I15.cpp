#include <bits/stdc++.h>
using namespace std;
int const N = 1e5;
int b[N];
int main() {
  int n;
  cin >> n;
  int a[n], x, mx = 0, y = 0, mxx = 0, mnx = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a[i] = x;
    b[x] += x;
    mx = max(mx, b[x]);
    mnx = min(mnx, x);
    mxx = max(mxx, x);
  }
  for (int i = mnx; i <= mxx; i++) {
    mx = max(mx, b[i] + b[i + 2]);
  }
  cout << mx;
  return 0;
}
