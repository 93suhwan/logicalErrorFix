#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a, b, c, d, n, T, m, x[N], p[N], y[N];
bool check(int s) {
  for (int i = 2; i <= sqrt(s); i++) {
    if (s % i == 0) return 1;
  }
  return 0;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int sum = 0, minn = 1111111, minx = 1111111;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &x[i]);
      sum += x[i];
      if (x[i] % 2)
        minn = min(minn, x[i]);
      else
        minx = min(minx, x[i]);
    }
    int maxx = 0;
    if (check(sum)) {
      cout << n << endl;
      for (int i = 1; i <= n; i++) cout << i << ' ';
    } else {
      int s1, s2;
      if (check(sum - minn))
        s1 = sum - minn;
      else
        s1 = 0;
      if (check(sum - minx))
        s2 = sum - minx;
      else
        s2 = 0;
      if (s1 > s2) {
        cout << n - 1 << endl;
        for (int i = 1; i <= n; i++)
          if (x[i] != minn) cout << i << ' ';
      } else {
        cout << n - 1 << endl;
        for (int i = 1; i <= n; i++)
          if (x[i] != minx) cout << i << ' ';
      }
    }
    cout << endl;
  }
}
