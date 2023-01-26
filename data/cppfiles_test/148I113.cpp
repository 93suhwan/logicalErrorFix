#include <bits/stdc++.h>
using namespace std;
int max2(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}
int max4(int a, int b, int c, int d) { return max2(max2(a, b), max2(d, c)); }
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int w, h;
    cin >> w >> h;
    vector<int> a(4, 0);
    for (int j = 0; j < 4; j++) {
      int n;
      cin >> n;
      int x1, x2;
      cin >> x1;
      for (int k = 1; k < n; k++) {
        cin >> x2;
      }
      a[j] = x2 - x1;
    }
    a[0] *= h;
    a[1] *= h;
    a[2] *= w;
    a[3] *= w;
    cout << max4(a[0], a[1], a[2], a[3]) << endl;
  }
  return 0;
}
