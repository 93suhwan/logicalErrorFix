#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
long long a[1005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int m;
    cin >> m;
    long long suma[2];
    suma[0] = 0;
    suma[1] = 0;
    int a[2][m];
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < m; k++) {
        cin >> a[j][k];
        suma[j] += a[j][k];
      }
    }
    long long sumamin = INT_MAX;
    for (int k = 0; k < m; k++) {
      long long suma1 = 0, suma2 = 0, suma3;
      for (int j = 0; j <= k; j++) suma1 += a[0][j];
      for (int j = k; j < m; j++) suma2 += a[1][j];
      suma3 = max(suma[0] - suma1, suma[1] - suma2);
      if (suma3 < sumamin) sumamin = suma3;
    }
    cout << sumamin << endl;
  }
  return 0;
}
