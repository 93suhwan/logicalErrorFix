#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n][5];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < 5; j++) cin >> a[i][j];
    int m, t, w, th, f;
    m = t = w = th = f = 0;
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < n; j++)
        if (i == 0 && a[j][i] == 1)
          m++;
        else if (i == 1 && a[j][i] == 1)
          t++;
        else if (i == 2 && a[j][i] == 1)
          w++;
        else if (i == 3 && a[j][i] == 1)
          th++;
        else if (i == 4 && a[j][i] == 1)
          f++;
    }
    int tr[5];
    tr[0] = m;
    tr[1] = t;
    tr[2] = w;
    tr[3] = th;
    tr[4] = f;
    int c = 0;
    for (int i = 0; i < 5; i++)
      if (tr[i] >= n / 2) c++;
    if (c >= 2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
