#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[2][n], b[n], i, j, sum1 = 0, sum2 = 0;
    for (long long int i = 0; i < 2; i++) {
      for (long long int j = 0; j < n; j++) {
        cin >> a[i][j];
        if (i == 0) sum1 += a[i][j];
      }
    }
    sum1 -= a[0][0];
    sum2 = 0;
    b[0] = max(sum1, sum2);
    for (int i = 1; i < n; i++) {
      sum1 -= a[0][i];
      sum2 += a[1][i - 1];
      b[i] = max(sum1, sum2);
    }
    sort(b, b + n);
    cout << b[0] << "\n";
  }
}
