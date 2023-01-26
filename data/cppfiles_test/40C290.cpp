#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int m;
    cin >> m;
    int a[2][m];
    for (int j = 0; j < m; j++) {
      cin >> a[0][j];
    }
    for (int j = 0; j < m; j++) {
      cin >> a[1][j];
    }
    int sum1 = 0, sum2 = 0;
    for (int j = 1; j < m; j++) {
      sum1 += a[0][j];
    }
    int max, min;
    if (sum1 > sum2)
      max = sum1;
    else
      max = sum2;
    min = max;
    for (int j = 1; j < m; j++) {
      sum2 += a[1][j - 1];
      sum1 -= a[0][j];
      if (sum1 > sum2)
        max = sum1;
      else
        max = sum2;
      if (min > max) min = max;
    }
    cout << min << endl;
  }
  return 0;
}
