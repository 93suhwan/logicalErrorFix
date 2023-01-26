#include <bits/stdc++.h>
using namespace std;
const int MAX = 6005;
int n, x[MAX], y[MAX];
long long rs = 0, pre[2][2], suf[2][2];
bool bound(int u1, int v1, int u2, int v2) {
  return (u1 ^ u2) == 1 || (v1 ^ v2) == 1;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    x[i] = x[i] / 2 % 2, y[i] = y[i] / 2 % 2;
    suf[x[i]][y[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    suf[x[i]][y[i]]--;
    for (int u1 = 0; u1 < 2; u1++)
      for (int v1 = 0; v1 < 2; v1++)
        for (int u2 = 0; u2 < 2; u2++)
          for (int v2 = 0; v2 < 2; v2++)
            if ((bound(x[i], y[i], u1, v1) ^ bound(x[i], y[i], u2, v2) ^
                 bound(u1, v1, u2, v2)) == 0)
              rs += pre[u1][v1] * suf[u2][v2];
    pre[x[i]][y[i]]++;
  }
  cout << rs;
}
